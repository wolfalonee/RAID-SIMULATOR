#include "strike.h"

Strike::Strike(int size){
    this->m_data = new char[size];
}

char * Strike::getDataPointer(){
    return this->m_data;
}

Strike::~Strike(){
    delete[] this->m_data;
}

