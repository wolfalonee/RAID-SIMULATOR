#ifndef RAID0_DISK_H
#define RAID0_DISK_H
#include "../basedisk.h"
#include "strike.h"

class RAID0_Disk : public BaseDisk
{
public:
    RAID0_Disk(int fullsize, int rspeed,int wspeed,int strikeSize);

    int getStrikeSize() const;
    void initDisk(); //init null strike

private:
    const int m_strikeSize;
    Strike* *m_strikes;


};

#endif // RAID0_DISK_H
