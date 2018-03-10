#include "linkedlistallocator.h"
#include "BACKEND/bitmagic.h"


namespace simpleFS{

std::string LinkedListAllocator::addFile(char* buffer, const unsigned long size,BaseDisk& disk){
    unsigned long requestedSectorCount = (size/(512-16));
    unsigned long startIndex = getFreeSectorIndex(disk);
    unsigned long nextFreeBlock = startIndex;


    for(unsigned long i = 0; i < requestedSectorCount;i++){
        if(!i){
            BitMagic::copyBytes(buffer,disk.getSector(nextFreeBlock)+16,512-16);
        }else{
            BitMagic::copyBytes(buffer+(512*i),disk.getSector(nextFreeBlock)+8,512-8);
        }
        nextFreeBlock = readNextFreeBlock(disk.getSector(nextFreeBlock));
    }

    if(requestedSectorCount == 0){
        BitMagic::copyBytes(buffer+16,disk.getSector(nextFreeBlock),size%(512-16));
    }else{
        BitMagic::copyBytes(buffer+(512*requestedSectorCount),disk.getSector(nextFreeBlock),size%(512-8));
    }


    setFreeSectorIndex(disk,readNextFreeBlock(disk.getSector(nextFreeBlock)));

    BitMagic::copyBytes(nextFreeBlock,disk.getSector(startIndex)+8,8);
    memcpy(disk.getSector(nextFreeBlock),0,8);

    return std::to_string(startIndex);
}

unsigned long LinkedListAllocator::readNextFreeBlock(char * sector){
    unsigned long ret;
    BitMagic::copyBytes(sector,ret,8);
    return ret;
}

unsigned long LinkedListAllocator::getFreeSectorIndex(BaseDisk& disk){
    unsigned long ret;
    char * firstSector = disk.getSector(0);
    BitMagic::copyBytes(firstSector,ret,8);
    return ret;
}

void LinkedListAllocator::setFreeSectorIndex(BaseDisk& disk,unsigned long newindex){
    char * firstsector = disk.getSector(0);
    BitMagic::copyBytes(newindex,firstsector,8);
}


} //simpleFS
