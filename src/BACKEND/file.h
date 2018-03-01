#ifndef FILE_H
#define FILE_H
#include <QString>
#include "size.h"

class File
{
public:
    enum sizeTypeHint{
        BYTE,
        KB,
        MB,
        GB
    };
    File();

    File& setName(const std::string& name);
    std::string getName() const;
    void setExtension(const std::string& ext);
    std::string getExtension() const;
    std::string getFullName() const; //name + . + extension

    File& setSize(int newSize);
    int getSize() const; //byte

    /*Váltószám = shiftNumber*/
    int sizeInMb() const;
    int sizeInKb() const;
    int sizeInGb() const;

    /*Visszadja, hogy miben lenne a legideálisabb kiiratni a méretét*/
    sizeTypeHint bestSizeType() const;

private:
    int m_size; //Bájtban értendő
    std::string m_name;
    std::string m_extension;

};

#endif // FILE_H
