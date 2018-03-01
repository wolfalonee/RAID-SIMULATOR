#ifndef CATALOG_H
#define CATALOG_H
#include "folder.h"
#define makeStringFromDefine(x) (#x)
#define _catalog_filename catalog.dat


/* A katalógus osztály továbbfejlesztési lehetősége,
   hogy egy valós B-treet építsen a diskre.
   A katalógus jelenleg szimplán egy c++os adatszerkezet
   mely egy adott struktúra alapján töldődik be a memóriába.

   A program leállításakor ez a valós diskre mentődik,
   majd onnan is töltődik be.

   Pont, mint a fájlrendszer data részlege, viszont az valós modellt követ.

   _catalog_filename-ban definiált fájl névből tölti be.
   Ennek a fájlnak a bináris könyvtárában
    lévő data/_catalog_filename.dat-ban kell lennie
*/

class Catalog
{
public:
    Catalog();
    void saveCatalog();
    void loadCatalog();


private:
    std::string _catalogName=makeStringFromDefine(_catalog_filename);
    Folder rootDirectory{nullptr,"root"};
};

#endif // CATALOG_H
