#include "GUI/mainwindow.h"
#include <QApplication>
#include <iostream>
#include <stdlib.h>
#include <QDebug>
#include "BACKEND/bitmagic.h"
#include "BACKEND/simpleFS/simplefilesystem.h"
#include "BACKEND/simpleFS/linkedlistallocator.h"
#include "BACKEND/simpleFS/diskformatter.h"

int main(int __attribute__((unused)) argc, char __attribute__((unused)) *argv[])
{
    /*
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    */

    char buffi[400] ={'A','K','G'};
    memset(buffi+40,'9',360);
    BaseDisk testDisk(2048,100,100);
    simpleFS::DiskFormatter::formatDisk(testDisk,simpleFS::DiskFormatter::linkedlist,'C');


    simpleFS::LinkedListAllocator alloc;
    std::cout << alloc.countOfFreeBlock(testDisk);

    alloc.addFile(buffi,400,testDisk);


    memset(buffi+40,'5',360);
    alloc.addFile(buffi,400,testDisk);
    std::cout << alloc.countOfFreeBlock(testDisk);
    testDisk.saveData("tesztDat.dat");


    return 0;
   // return a.exec();
}
