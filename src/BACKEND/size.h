#ifndef SIZE_H
#define SIZE_H

#define shiftNumber 1024 //Méret váltáshoz, arch. függő.

/*File/RAID disk mérethez*/
class Size
{
public:
    Size();

    static unsigned long ByteToMb(unsigned long byte);
    static unsigned long ByteToKb(unsigned long byte);
    static unsigned long ByteToGb(unsigned long byte);

    static unsigned long KbToByte(unsigned long byte);

};

#endif // SIZE_H
