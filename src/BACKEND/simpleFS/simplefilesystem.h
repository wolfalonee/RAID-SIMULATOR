#ifndef SIMPLEFILESYSTEM_H
#define SIMPLEFILESYSTEM_H
#include "../catalog.h"
#include "allocator.h"
/* Nem lehet disket mountolni mappába
 * egy disknek külön labelen kell lennie */

namespace simpleFS{
template<typename T>
struct derivedFromAllocator{
    static std::true_type magic(const Allocator* alloc);
    static std::false_type magic(...);
    static constexpr const bool value = decltype(magic(std::declval<T*>()))::value;
};

template<typename FSAlloc>
class FileSystem
{
static_assert(derivedFromAllocator<FSAlloc>::value,
             "typename FSAlloc should be derived from public Allocator abstract class");
public:
    FileSystem(){

    }

private:
    Catalog m_catalog;
    FSAlloc fileAllocator;
};
} //simpleFS


#endif // SIMPLEFILESYSTEM_H
