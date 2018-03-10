#ifndef BASEDISK_H
#define BASEDISK_H

#include <mutex>

/*  DiskSize: in byte
    ReadingSpeed: byte/sec
    WritingSpeed: byte/sec
*/

class BaseDisk
{
public:
    BaseDisk(unsigned long diskSize,int readingspeed,int writingspeed);
    BaseDisk(const std::string& loadFileName,int readingspeed,int writingspeed); //Fájlból betöltés

    virtual ~BaseDisk();

    unsigned long getSize() const;
    int getReadingSpeed() const;
    int getWritingSpeed() const;

    void setReadingSpeed(int);
    void setWritingSpeed(int);

    unsigned long getSectorCount() const;

    /*out of range: Undef*/
    char* getSector(unsigned long index) const;
    void writeSector(char * buffer, int index);

    /*Lementi a disk tartalmát a megadott fájlnévbe.*/
    void saveData(const std::string& filename);

    /*Védelem, ha egy szál épp akkor olvas amikor a másik változtatni akar a disk sebességén*/
    /*Nem történik sokszor változtatás, ezért ennyi költség belefér.*/
    mutable std::recursive_mutex mut;
private:
    char** data = nullptr;

    unsigned long m_size; //Byte
    int m_readingSpeed; /* BYTE/SEC */
    int m_writingSpeed; /* BYTE/SEC */
};

#endif // BASEDISK_H
