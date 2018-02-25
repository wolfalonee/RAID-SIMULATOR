#ifndef BASEDISK_H
#define BASEDISK_H


/*RAID diskek őse*/

class BaseDisk
{
public:
    BaseDisk();
    BaseDisk(int fsize,int rspeed,int wspeed);

    int getFullSize() const;
    int getReadingSpeed() const;
    int getWritingSpeed() const;

    void setFullSize(int);
    void setReadingSpeed(int);
    void setWritingSpeed(int);

private:
    int m_fullSize;
    int m_readingSpeed; /* BYTE/SEC */
    int m_writingSpeed; /* BYTE/SEC */
};

#endif // BASEDISK_H
