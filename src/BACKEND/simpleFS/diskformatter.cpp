#include "diskformatter.h"
#include"BACKEND/bitmagic.h"

namespace simpleFS{

void DiskFormatter::formatDisk(BaseDisk& disk,DiskFormatter::type t,char labelID){
    switch(t){
        case linkedlist:
            formatLinkedList(disk,labelID);
            break;
    }
}

void DiskFormatter::formatLinkedList(BaseDisk& disk,char label){
    unsigned long tmp = 1;
    BitMagic::copyBytes(tmp,disk.getSector(0),8);
    BitMagic::copyBytes(label,disk.getSector(0)+8,1);
    tmp++;
    for(unsigned long i = 1;i < disk.getSectorCount();i++){
        BitMagic::copyBytes(tmp,disk.getSector(i),8);
        tmp++;
    }

    tmp=0;

    BitMagic::copyBytes(tmp,disk.getSector(disk.getSectorCount()-1),8);
}
}//simpleFS
