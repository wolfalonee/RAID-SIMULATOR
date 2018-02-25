#ifndef BITMAGIC_TPP
#define BITMAGIC_TPP

#include <QDebug>
#include <iostream>

class BitMagic{
public:
    template<typename T>
    static char* getByte(const T& obj, int index){
        T * tmp = &(const_cast<T&>(obj));
        return static_cast<char*>(tmp) + index;
    }

    template<typename T,size_t SIZE_N>
    static char* getByte(T (&obj)[SIZE_N], int index){
        return static_cast<char*>(const_cast<char*>((&obj[0]))) + index;
    }


    template<typename T>
    static bool getBit(const T& obj, int index){
        int targetByte = index / 8;
        int targetIndex = index - targetByte * 8;
        char * thisTByte = getByte(obj,targetByte);
        return static_cast<bool>((*thisTByte & (1 << targetIndex)) >> targetIndex);
    }

    template<typename T>
    static void setBit(const T& obj, int index, bool newvalue){
        int targetByte = index / 8;
        char& tmp = *(getByte(obj,targetByte));
        tmp ^= (-newvalue ^ tmp) & (1 << (index - targetByte*8));
    }

    template<typename T>
    static void setByte(const T& obj, int index, char newValue){
        static_cast<char*>(&obj)[index] = newValue;
    }

    template<typename T>
    static void write(const T& obj, char * target){
        constexpr size_t size = sizeof(obj);
        for(size_t i = 0; i < size; i++){
            target[i] = (reinterpret_cast<char*>(&const_cast<T&>(obj)))[i];
        }
    }

    /*Kiiratás pl:
     * 7 = 1. byte:
     *     0 0 0 0 0 1 1 1
     * Tehát helyiérték szerint a legnagyobb helyiértékkel kezdődik
    */
    template<typename T>
    static void printBits(const T& obj){
        int size = sizeof(obj);
        for(int i = 0; i < size;i++){
            qDebug() << i+1 << ". byte: ";
            char * tmp = getByte(obj,i);
            QDebug debuggernew(qDebug());
            for(int b = 7; b >= 0;b--){
                debuggernew << qPrintable(getBit(*tmp,b) ? "1" :"0");
            }
        }
    }

    template<typename T>
    static void printBits(const T& obj,int size){
        qDebug() << "------------\n";
        qDebug() << "[8] [7] [6] [5] [4] [3] [2] [1]";
        for(int i = 0; i < size;i++){
            qDebug() << "\n" << i+1 << ". byte: ";
            char * tmp = getByte(obj,i);
            QDebug debuggernew(qDebug());
            for(int b = 7; b >= 0;b--){
                debuggernew << qPrintable(getBit(*tmp,b) ? "[1]" :"[0]");
            }
        }
    }
};

#endif


