#ifndef FILE_H
#define FILE_H
#include <QString>
#include "size.h"
#include "json.h"
#include "metafun.h"


namespace metafun{
    GENERATE_ALL_CHECKS(dump);
    GENERATE_ALL_CHECKS(loadFromJson);
}

using namespace nlohmann;


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

    File& setSize(unsigned long newSize);
    unsigned long getSize() const; //byte

    /*Váltószám = shiftNumber*/
    unsigned long sizeInMb() const;
    unsigned long sizeInKb() const;
    unsigned long sizeInGb() const;

    /*Visszadja, hogy miben lenne a legideálisabb kiiratni a méretét*/
    sizeTypeHint bestSizeType() const;
    std::string getSizeTypeAsString() const;


    json dump();
    static File loadFromJson(const json&);

private:
    unsigned long m_size; //Bájtban értendő
    std::string m_name;
    std::string m_extension;
    void _self_test(){
        static_assert(metafun::hasFunction_dump<File>::value,"JSON Dump functiom need");
    }
};

#endif // FILE_H
