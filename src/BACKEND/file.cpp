#include "file.h"

File::File(){
    this->m_size =0;
    this->m_name = "unknown";
    this->m_extension = "";
}

File& File::setName(const std::string &name){
    this->m_name = name;
    return *this;
}

std::string File::getName() const{
    return this->m_name;
}

std::string File::getExtension() const{
    return this->m_extension;
}

void File::setExtension(const std::string& ext){
    this->m_extension = ext;
}

std::string File::getFullName() const{
    return this->m_extension == "" ? this->m_name :
           this->m_name + "." + this->m_extension;
}

File& File::setSize(int newSize){
    this->m_size = newSize;
    return *this;
}

int File::getSize() const{
    return this->m_size;
}

int File::sizeInMb() const{
    return Size::ByteToMb(this->m_size);
}

int File::sizeInKb() const{
    return Size::ByteToKb(this->m_size);
}

int File::sizeInGb() const{
    return Size::ByteToGb(this->m_size);
}

auto File::bestSizeType() const -> sizeTypeHint {
    if(m_size < 1001){
        return sizeTypeHint::BYTE;
    }

    if(Size::ByteToKb(m_size) < 2000){
        return sizeTypeHint::KB;
    }

    if(Size::ByteToMb(m_size) < 1000){
        return sizeTypeHint::MB;
    }

    return sizeTypeHint::GB;
}
