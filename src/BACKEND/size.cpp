#include "size.h"

Size::Size(){}

unsigned long Size::ByteToKb(unsigned long byte){
    unsigned long res = byte / shiftNumber;
    return res==0 ? 1 : res;
}

unsigned long Size::ByteToMb(unsigned long byte){
    return byte / shiftNumber / shiftNumber;
}

unsigned long Size::ByteToGb(unsigned long byte){
    return ByteToMb(byte) / shiftNumber;
}

unsigned long Size::KbToByte(unsigned long byte){
    return byte * shiftNumber;
}

