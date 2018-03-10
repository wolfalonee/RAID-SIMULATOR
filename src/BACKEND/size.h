#ifndef SIZE_H
#define SIZE_H

#define shiftNumber 1024 //Méret váltáshoz, arch. függő.

/*File/RAID disk mérethez*/
class Size
{
public:
    static constexpr unsigned long ByteToKb(unsigned long byte){
        unsigned long res = byte / shiftNumber;
        return res==0 ? 1 : res;
    }

    static constexpr unsigned long ByteToMb(unsigned long byte){
        return byte / shiftNumber / shiftNumber;
    }

    static constexpr unsigned long ByteToGb(unsigned long byte){
        return ByteToMb(byte) / shiftNumber;
    }

    static constexpr unsigned long KbToByte(unsigned long byte){
        return byte * shiftNumber;
    }
};

#endif // SIZE_H
