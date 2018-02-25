#include "raid0_disk.h"

RAID0_Disk::RAID0_Disk(int fsize, int rspeed, int wspeed,int strikeSize):
    BaseDisk(fsize,rspeed,wspeed),m_strikeSize(strikeSize)  {

}

int RAID0_Disk::getStrikeSize() const{
    return this->m_strikeSize;
}
