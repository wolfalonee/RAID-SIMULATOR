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

    void setName(const QString& name);
    QString getName() const;
    void setExtension(const QString& ext);
    QString getExtension() const;
    QString getFullName() const; //name + . + extension

    void setSize(int newSize);
    int getSize() const; //byte

    /*Váltószám = shiftNumber*/
    int sizeInMb() const;
    int sizeInKb() const;
    int sizeInGb() const;

    /*Visszadja, hogy miben lenne a legideálisabb kiiratni a méretét*/
    sizeTypeHint bestSizeType() const;

private:
    int m_size; //Bájtban értendő
    QString m_name;
    QString m_extension;

};

#endif // FILE_H
