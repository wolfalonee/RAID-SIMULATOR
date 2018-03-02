#ifndef CATALOG_H
#define CATALOG_H
#include "folder.h"
#include "json.h"

#define _catalog_filename "catalog.dat"

/* A katalógus osztály továbbfejlesztési lehetősége,
   hogy egy valós B-treet építsen a diskre.
   A katalógus jelenleg szimplán egy c++os adatszerkezet
   mely egy adott struktúra alapján töldődik be a memóriába.

   A program leállításakor ez a valós diskre mentődik,
   majd onnan is töltődik be.

   Pont, mint a fájlrendszer data részlege, viszont az valós modellt követ.

   _catalog_filename-ban definiált fájl névből tölti be.
   Ennek a fájlnak a bináris könyvtárában
    lévő _catalog_filename.dat-ban kell lennie

   A feldolgozás mélységi bejárással történik.
*/

class Catalog
{
public:
    Catalog();
    void saveCatalog();
    void loadCatalog();
    Folder& getRootDir();

private:
    const std::string _catalogName=(_catalog_filename);
    Folder rootDirectory{nullptr,"root"};
};


/*JSON input/output feldolgozó*/
class CatalogParser{
public:
    CatalogParser(){;}
    static void save(Folder& rootdir,const std::string& outputname);
    static void loadJSON(json * ,const std::string& filename);
    static void loadFromRootDir(Folder&,json&);
};

#endif // CATALOG_H
