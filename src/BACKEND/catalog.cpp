#include "catalog.h"
#include "json.h"
#include "stdio.h"

using namespace nlohmann;

Catalog::Catalog(){}

void Catalog::saveCatalog(){
    CatalogParser::save(rootDirectory,this->_catalogName);
}

void Catalog::loadCatalog(){
    json data;
    CatalogParser::loadJSON(&data,this->_catalogName);
    CatalogParser::loadrootdir(rootDirectory,data);
}

Folder& Catalog::getRootDir(){
    return this->rootDirectory;}


void CatalogParser::save(Folder& rootdir,const std::string& outputname){
    json output;
    rootdir.dump(&output);
    FILE *outfile;
    outfile=fopen(outputname.c_str(),"w");
    if(!outfile){
        std::cout << "output file error,catalogparser save";
        return;
    }
    fprintf(outfile,"%s",output.dump().c_str());
    fclose(outfile);
}

void CatalogParser::loadJSON(json * output,const std::string& filename){
    FILE *inpfile;
    inpfile=fopen(filename.c_str(),"r");

    fseek(inpfile,0,SEEK_END);
    long filesize = ftell(inpfile);

    char * buffer = static_cast<char*>(malloc((sizeof(char)*static_cast<unsigned long>(filesize)) + 1 ));
    if(!buffer){
        std::cout << "MEMORY ALLOC FAILED CATALOG PARSER LOAD\n";
        return;
    }
    fseek(inpfile,0,SEEK_SET);

    size_t read=fread(buffer,filesize,1,inpfile);
    buffer[filesize] ='\0';

    if(read!=1){
        printf("Catalog parser read error!");
    }

    free(buffer);
    fclose(inpfile);

    std::string str(buffer);
    *output = json::parse(str);
}

void CatalogParser::loadrootdir(Folder& dir, json& data){
    int filecount = data["filecount"];
    int dircount = data["dircount"];
    std::string name;
    for(int i = 0; i < filecount;i++){
        name = "file"+std::to_string(i);
        dir.addFile(File::loadFromJson(data[name]));
    }
    for(int k = 0; k < dircount;k++){
        dir.addFolder(data["folder"+std::to_string(k)]["name"]);
        loadDir(dir.getFolder(data["folder"+std::to_string(k)]["name"]),data["folder"+std::to_string(k)]);
    }
}

void CatalogParser::loadDir(Folder& dir, json& data){
    int filecount = data["filecount"];
    int dircount = data["dircount"];
    std::string name;
    for(int i = 0; i < filecount;i++){
        name = "file"+std::to_string(i);
        dir.addFile(File::loadFromJson(data[name]));
    }
    for(int k = 0; k < dircount;k++){
        dir.addFolder(data["folder"+std::to_string(k)]["name"]);
        loadDir(dir.getFolder(data["folder"+std::to_string(k)]["name"]),data["folder"+std::to_string(k)]);
    }
}
