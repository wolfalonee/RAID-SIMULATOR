#ifndef FILESYSTEM_H
#define FILESYSTEM_H
#include "catalog.h"
#include "allocator.h"

/* A FileSystem létrehozásához meg kell adni egy allokátor tipust
 * Fontos, hogy csak olyan tipust lehet megadni, aminek az
 * egyik őse az Allocator osztály*/

template<typename T>
struct derivedFromAllocator{
    static std::true_type magic(const Allocator* alloc);
    static std::false_type magic(...);
    static constexpr const bool value = decltype(magic(std::declval<T*>()))::value;
};

template<typename AllocatorType>
class FileSystem
{
static_assert(derivedFromAllocator<AllocatorType>::value,
             "typename AllocatorType should be derived from public Allocator abstract class");
public:
    FileSystem(){

    }

private:
    Catalog m_catalog;
};



#endif // FILESYSTEM_H
