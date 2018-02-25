#ifndef SIZE_H
#define SIZE_H

#define shiftNumber 1000 //Méret váltáshoz, arch. függő.

/*File/RAID disk mérethez*/
class Size
{
public:
    Size();

    static int ByteToMb(int byte);
    static int ByteToKb(int byte);
    static int ByteToGb(int byte);

    static int KbToByte(int byte);

};

#endif // SIZE_H
