#ifndef BASEDISK_H
#define BASEDISK_H

#include <mutex>


/*  DiskSize: in byte
    ReadingSpeed: byte/sec
    WritingSpeed: byte/sed
*/

class BaseDisk
{
public:
    BaseDisk(unsigned long DiskSize,int readingspeed,int writingspeed);
    BaseDisk(const std::string& loadFileName,int readingspeed,int writingspeed); //Load from file

    virtual ~BaseDisk();

    unsigned long getSize() const;
    int getReadingSpeed() const;
    int getWritingSpeed() const;

    void setReadingSpeed(int);
    void setWritingSpeed(int);

    /*out of range: Undef*/
    unsigned long getSectorCount() const;
    char* getSector(int index) const;
    void writeSector(char * buffer, int index);

    void saveData(const std::string& filename);

    mutable std::recursive_mutex mut;
private:
    char** data = nullptr;

    unsigned long m_size; //Byte
    int m_readingSpeed; /* BYTE/SEC */
    int m_writingSpeed; /* BYTE/SEC */
};

#endif // BASEDISK_H
