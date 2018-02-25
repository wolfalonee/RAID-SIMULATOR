#include "basedisk.h"

BaseDisk::BaseDisk(){
    this->m_fullSize = 0;
    this->m_readingSpeed = 0;
    this->m_writingSpeed = 0;
}

BaseDisk::BaseDisk(int fsize, int rspeed, int wspeed){
    this->m_fullSize = fsize;
    this->m_readingSpeed = rspeed;
    this->m_writingSpeed = wspeed;
}

int BaseDisk::getFullSize() const{
    return this->m_fullSize;
}

int BaseDisk::getReadingSpeed() const{
    return this->m_readingSpeed;
}

int BaseDisk::getWritingSpeed() const{
    return this->m_writingSpeed;
}

void BaseDisk::setFullSize(int s){
    this->m_fullSize = s;
}

void BaseDisk::setReadingSpeed(int s ){
    this->m_readingSpeed = s;
}

void BaseDisk::setWritingSpeed(int s){
    this->m_writingSpeed = s;
}

