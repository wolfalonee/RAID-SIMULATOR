#ifndef DISKFORMATTER_H
#define DISKFORMATTER_H
#include "BACKEND/basedisk.h"


namespace simpleFS{
class DiskFormatter
{
public:
    enum type{
        linkedlist
    };
    static void formatDisk(BaseDisk& disk, type,char);

private:
    static void formatLinkedList(BaseDisk& disk,char);
};
}

#endif // DISKFORMATTER_H
