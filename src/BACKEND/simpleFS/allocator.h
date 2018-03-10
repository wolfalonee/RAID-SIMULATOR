#ifndef ALLOCATOR_H
#define ALLOCATOR_H
/*Abstract osztály*/
#include "../file.h"
#include "../basedisk.h"

namespace simpleFS{
class Allocator{
public:
    /*Új helyet foglal és létrehozza a fájlt*/
    virtual std::string addFile(char* buffer, const unsigned long size,BaseDisk& disk) noexcept(false) = 0;

    /*Egy fájlhoz hozzáfűzi a megadott buffert*/
    virtual std::string appendToFile(const File& file,char * buffer,const unsigned long size,BaseDisk& disk) noexcept(false) = 0;

    virtual ~Allocator();

private:



};
}


#endif // ALLOCATOR_H
