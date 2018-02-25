#include "size.h"

Size::Size(){}

int Size::ByteToKb(int byte){
    int res = byte / shiftNumber;
    return res==0 ? 1 : res;
}

int Size::ByteToMb(int byte){
    return byte / shiftNumber / shiftNumber;
}

int Size::ByteToGb(int byte){
    return ByteToMb(byte) / shiftNumber;
}

int Size::KbToByte(int byte){
    return byte * shiftNumber;
}

