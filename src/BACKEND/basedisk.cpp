#include "basedisk.h"
#include <string>
#include <iostream>
#include "BACKEND/bitmagic.h"

BaseDisk::BaseDisk(unsigned long dsize,int rspeed,int wspeed):m_size(dsize/512*512),m_readingSpeed(rspeed),m_writingSpeed(wspeed){
    unsigned long sectorcount = dsize/512;
    this->data = new char*[sectorcount];
    for(unsigned long i = 0; i < sectorcount;i++){
        this->data[i] = new char[512];
        memset(data[i],0,512);
    }
}

BaseDisk::BaseDisk(const std::string& name, int rspeed,int wspeed):m_readingSpeed(rspeed),m_writingSpeed(wspeed){
    FILE * f = fopen(name.c_str(),"r");
    if(!f){
       std::cout <<"Cant open file";
       return;
    }

    fseek(f,0,SEEK_END);
    long cur = ftell(f);
    if(cur < 7){
        std::cout << "Invalid file";
        fclose(f);
        return;
    }

    fseek(f,0,SEEK_SET);
    fread(static_cast<void*>(&this->m_size),8,1,f);
    this->data=new char*[m_size/512];
    for(unsigned long i = 0; i < m_size/512;i++){
        this->data[i] = new char[512];
        fread(static_cast<void*>(this->data[i]),512,1,f);
    }

    fclose(f);
}

BaseDisk::~BaseDisk(){
    if(this->data){
        for(unsigned long i = 0; i < m_size/512;i++){
            delete[] data[i]; //pointer to data array
        }
        delete[] data; // pointer to pointers array
    }
}

unsigned long BaseDisk::getSize() const{
    return this->m_size;
}

int BaseDisk::getReadingSpeed() const{
    std::lock_guard<std::recursive_mutex> locki(this->mut);
    return this->m_readingSpeed;
}

int BaseDisk::getWritingSpeed() const{
    std::lock_guard<std::recursive_mutex> locki(this->mut);
    return this->m_writingSpeed;
}

void BaseDisk::setReadingSpeed(int s ){
    std::lock_guard<std::recursive_mutex> locki(this->mut);
    this->m_readingSpeed = s;
}

void BaseDisk::setWritingSpeed(int s){
    std::lock_guard<std::recursive_mutex> locki(this->mut);
    this->m_writingSpeed = s;
}

void BaseDisk::writeSector(char * buffer,int index){
    for(int i = 0;i < 512;i++){
        this->data[index][i] = buffer[i];
    }
}

char* BaseDisk::getSector(unsigned long index) const{
    return this->data[index];
}

unsigned long BaseDisk::getSectorCount() const{
    return this->m_size/512;
}

void BaseDisk::saveData(const std::string& filename){
    FILE* file = fopen(filename.c_str(),"w");
    fwrite(static_cast<void*>(&m_size),8,1,file);
    for(unsigned long i = 0; i < this->getSectorCount();i++){
        fwrite(this->data[i],512,1,file);
    }
    fclose(file);
}
