#include "folder.h"

Folder::Folder(Folder* parent,const std::string& name):parent(parent),name(name){}

/*Rekurzív törlés*/
Folder::~Folder(){
    for(auto& i : this->folders){
        delete i.second;
    }
}

bool Folder::isRootDir() const{
    return parent==nullptr;
}

bool Folder::hasFolder(const std::string& name) const noexcept(true){
    return folders.find(name) != folders.end();
}

/*Ez a jelenlegi mappában is megnézi*/
bool Folder::hasSubFolder(const std::string& name) const noexcept(true){
    if(hasFolder(name)) return true;
    for(auto& i: folders){
        if(i.second->hasSubFolder(name)) return true;
    }
    return false;
}

bool Folder::hasFile(const std::string& name) const noexcept(true){
    return files.find(name) != files.end();
}

File& Folder::getFile(const std::string& name) noexcept(false){
    return files.at(name);
}

Folder& Folder::getFolder(const std::string& name){
    return *(folders.at(name));
}

std::list<std::string> Folder::getDirectoryList() const{
    std::list<std::string> ret;
    for(auto& i: folders){
        ret.push_back(i.first);
    }
    return ret;
}

std::list<std::string> Folder::getFileList() const{
    std::list<std::string> ret;
    for(auto& i: files){
        ret.push_back(i.first);
    }
    return ret;
}

bool Folder::addFolder(const std::string& name){
    if(hasFolder(name)){
        return false;
    }else{
        folders[name] = new Folder(this,name);
        return true;
    }
}

void Folder::addFile(File& file){
    files[file.getName()] = file;
}

void Folder::addFile(File&& file){
    files[file.getName()] = file;
}

void Folder::deleteFolder(std::string& name){
    if(hasFolder(name)){
        delete folders[name];
        this->folders.erase(folders.find(name));
    }
}

void Folder::remove(){
    if(parent!=nullptr){
        parent->deleteFolder(name);
    }else{
        std::cout << "Warning, try to delete root dir";
    }
}

size_t Folder::getDirCount() const{
    return folders.size();
}

size_t Folder::getFileCount() const{
    return files.size();
}
