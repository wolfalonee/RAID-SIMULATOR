#ifndef FOLDER_H
#define FOLDER_H

#include <map>
#include "file.h"
#include <exception>
#include <list>
#include <iostream>
#include "json.h"
#include "metafun.h"

using namespace nlohmann;


/*Root directory parent = nullptr*/

class Folder
{
struct file_not_found : std::exception {};
public:
    class iterator{ //Fájlokon
    public:
        iterator(const iterator& it): obj(it.obj){}
        iterator(std::map<std::string,File>::iterator r):obj(r){}
        iterator& operator++(){
            obj++;
            return *this;
        }

        iterator operator++(int){
            iterator back = *this;
            obj++;
            return back;
        }

        bool operator!=(const iterator it){
            return obj != it.obj;
        }

        File& operator*(){
            return obj->second;
        }

    private:
        std::map<std::string,File>::iterator obj;
    };


    Folder(Folder* parent,const std::string& name);

    ~Folder(); //Rekúrzív törlés, felszabadul az összes fájl és mappa.

    bool isRootDir() const;

    /*Egy szinttel lejjebb lévő foldereket nézi csak*/
    bool hasFolder(const std::string& name) const noexcept(true);

    /*Rekurzívan megnézi, hogy van-e ilyen mappa*/
    bool hasSubFolder(const std::string& name) const noexcept(true);

    bool hasFile(const std::string& name) const noexcept(true) ;

    /*Ellenőrzi, hogy létezik-e a fájl. Ha nem exceptiont dob.
      Mielőtt egy fájlt kérdezünk le célszerű hasFile-al megnézni
      vagy legalább egy try blockba foglalni*/
    File& getFile(const std::string& fileName) noexcept(false);

    Folder& getFolder(const std::string& name);

    std::list<std::string> getDirectoryList() const;
    std::list<std::string> getFileList() const;

    /*Hamisat ad vissza, ha létezett már a mappa*/
    bool addFolder(const std::string& name);

    void addFile(File& file);
    void addFile(File&& file);

    /*A megadott mappát törli, ha létezik*/
    void deleteFolder(std::string& name);

    /*Törli magát a szülőn keresztül*/
    void remove();

    /*Megadja, hogy miből mennyit tartalmaz*/
    size_t getDirCount() const;
    size_t getFileCount() const;

    /*json dump a kapott json objectbe*/
    void dump(json * output);
    void loadFromJson(json& input);

    iterator begin(){
        return iterator(m_files.begin());
    }
    iterator end(){
        return iterator(m_files.end());
    }

private:
    std::map<std::string,Folder*> m_folders; //key = name
    std::map<std::string,File> m_files;
    Folder* m_parent;
    std::string m_name;

    /*Mindenképp szükséges függvények*/
    static void _self_test(){
        static_assert(metafun::hasFunction_dump<Folder>::value,"JSON Dump functiom need");
        static_assert(metafun::hasFunction_loadFromJson<Folder>::value,"loadFromJson function need");
    }
};

#endif // FOLDER_H
