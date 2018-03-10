#ifndef LINKEDLISTALLOCATOR_H
#define LINKEDLISTALLOCATOR_H
#include "allocator.h"

/*
    ___Láncolt listás fájl allokáció___

    Egy láncolt listában tároljuk a szabad szektorokat
    Láncolt listát allokáció csak abban az esetben működik ha a disket ehhez formázzuk.
    Ekkor az összes szektor első 8 bájtjába írásra kerül a következő szabad blokk.

    A disk első szektorában tároljuk az információkat a lemezről.
    - Szabad blokkkokat tartalmazó láncolt lista első eleme. (8 byte ulong)
    - Disk Label. (1 byte char)

    Fájl foglalás:
    Lefoglaljuk a szükséges területet, majd a lista első elemének a címét átállítjuk az utoljára foglalt
    elem által címzett blokkra.

    Felszabadításkor a szabad lista első eleme lesz a felszabadított elem első eleme
    majd az utolsó elemet hozzáfűzzűk az előző szabad lista első elemére.

    Előnyök~:
    Nem fregmentálódik a disk, mindig ki tudjuk használni a rendelkezésre álló szabad területet

    Hátrányok~:
    Lassú, hiszen az írófej nem tud folyamatosan, lineárisan olvasni, ide-oda kell ugrálnia egy fájl beolvasásakor.
*/

namespace simpleFS{
class LinkedListAllocator : Allocator
{
public:
    ~LinkedListAllocator(){;}
    virtual std::string addFile(char* buffer, const unsigned long size,BaseDisk& disk) noexcept(false) = 0;
    virtual std::string appendToFile(const File& file,char * buffer,const unsigned long size,BaseDisk& disk) noexcept(false) = 0;


    unsigned long readNextFreeBlock(char * sector);
    unsigned long getFreeSectorIndex(BaseDisk& disk);
    void setFreeSectorIndex(BaseDisk& disk, unsigned long newIndex);



private:




};
} //simpleFS


#endif // LINKEDLISTALLOCATOR_H
