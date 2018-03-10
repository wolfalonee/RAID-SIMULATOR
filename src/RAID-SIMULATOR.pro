#-------------------------------------------------
#
# Project created by QtCreator 2018-02-07T21:24:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14 c++17
CONFIG += std=c++14 std=c++11 std=c++17 std=c++1z

QMAKE_CXXFLAGS += -Wno-c++17-extensions
QMAKE_CXXFLAGS += -Wno-c++1z-extensions


QMAKE_CXXFLAGS         = -std=c++1y
QMAKE_CXXFLAGS            = -std=c++1z
QMAKE_CXXFLAGS         = -std=gnu++11
QMAKE_CXXFLAGS          = -std=gnu++1y
QMAKE_CXXFLAGS        = -std=gnu++1z


QMAKE_CFLAGS_DEBUG *= -std=c++17

TARGET = RAID-SIMULATOR
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        GUI/mainwindow.cpp \
    BACKEND/file.cpp \
    BACKEND/basedisk.cpp \
    BACKEND/folder.cpp \
    BACKEND/catalog.cpp \
    BACKEND/simpleFS/simplefilesystem.cpp \
    BACKEND/simpleFS/linkedlistallocator.cpp \
    BACKEND/simpleFS/diskformatter.cpp

HEADERS += \
        GUI/mainwindow.h \
    BACKEND/file.h \
    BACKEND/basedisk.h \
    BACKEND/size.h \
    BACKEND/bitmagic.h \
    BACKEND/metafun.h \
    BACKEND/folder.h \
    BACKEND/catalog.h \
    BACKEND/json.h \
    BACKEND/simpleFS/allocator.h \
    BACKEND/simpleFS/simplefilesystem.h \
    BACKEND/simpleFS/linkedlistallocator.h \
    BACKEND/simpleFS/diskformatter.h

FORMS += \
        GUI/mainwindow.ui
