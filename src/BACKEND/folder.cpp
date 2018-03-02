#include "folder.h"

Folder::Folder(Folder* parent,const std::string& name):m_parent(parent),m_name(name){}

/*Rekurzív törlés*/
Folder::~Folder(){
    for(auto& i : this->m_folders){
        delete i.second;
    }
}

bool Folder::isRootDir() const{
    return m_parent==nullptr;
}

bool Folder::hasFolder(const std::string& name) const noexcept(true){
    return m_folders.find(name) != m_folders.end();
}

/*Ez a jelenlegi mappában is megnézi*/
bool Folder::hasSubFolder(const std::string& name) const noexcept(true){
    if(hasFolder(name)) return true;
    for(auto& i: m_folders){
        if(i.second->hasSubFolder(name)) return true;
    }
    return false;
}

bool Folder::hasFile(const std::string& name) const noexcept(true){
    return m_files.find(name) != m_files.end();
}

File& Folder::getFile(const std::string& name) noexcept(false){
    return m_files.at(name);
}

Folder& Folder::getFolder(const std::string& name){
    return *(m_folders.at(name));
}

std::list<std::string> Folder::getDirectoryList() const{
    std::list<std::string> ret;
    for(auto& i: m_folders){
        ret.push_back(i.first);
    }
    return ret;
}

std::list<std::string> Folder::getFileList() const{
    std::list<std::string> ret;
    for(auto& i: m_files){
        ret.push_back(i.first);
    }
    return ret;
}

bool Folder::addFolder(const std::string& name){
    if(hasFolder(name)){
        return false;
    }else{
        m_folders[name] = new Folder(this,name);
        return true;
    }
}

void Folder::addFile(File& file){
    m_files[file.getName()] = file;
}

void Folder::addFile(File&& file){
    m_files[file.getName()] = file;
}

void Folder::deleteFolder(std::string& name){
    if(hasFolder(name)){
        delete m_folders[name];
        this->m_folders.erase(m_folders.find(name));
    }
}

void Folder::remove(){
    if(m_parent!=nullptr){
        m_parent->deleteFolder(m_name);
    }else{
        std::cout << "Warning, try to delete root dir";
    }
}

size_t Folder::getDirCount() const{
    return m_folders.size();
}

size_t Folder::getFileCount() const{
    return m_files.size();
}

void Folder::dump(json * output){
    int k;
    json & ref = *output;
    ref["name"] = this->m_name;
    ref["dircount"] = getDirCount();
    ref["filecount"] = getFileCount();
    k=0;
    for(auto& i: m_files){
        ref[std::string("file")+std::to_string(k++)] = i.second.dump();
    }
    k=0;
    for(auto& i: m_folders){
        i.second->dump(&ref[std::string("folder")+std::to_string(k++)]);
    }
}
