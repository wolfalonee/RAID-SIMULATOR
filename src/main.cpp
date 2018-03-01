#include "GUI/mainwindow.h"
#include <QApplication>
#include <iostream>
#include <QDebug>
#include "BACKEND/metafun.h"
#include "BACKEND/bitmagic.h"
#include "BACKEND/folder.h"
#include <stdlib.h>


int main(int __attribute__((unused)) argc, char __attribute__((unused)) *argv[])
{
    /*
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    */

    qDebug() << "RAID-SIMULATOR-START\n";
    Folder root(nullptr,"root");
    root.addFolder("tesztelek");
    std::cout << root.getDirCount();
    root.getFolder("tesztelek").addFile(File().setName("keci").setSize(50));

    root.getFolder("tesztelek").remove();
    std::cout << root.getDirCount();

    return 0;
   // return a.exec();
}
