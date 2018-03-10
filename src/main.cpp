#include "GUI/mainwindow.h"
#include <QApplication>
#include <iostream>
#include <stdlib.h>
#include <QDebug>

#include "BACKEND/simpleFS/simplefilesystem.h"


int main(int __attribute__((unused)) argc, char __attribute__((unused)) *argv[])
{
    /*
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    */

    Folder asd{nullptr,"root"};

    for(auto& i : asd){
        std::cout << i.getFullName();
    }


    return 0;
   // return a.exec();
}
