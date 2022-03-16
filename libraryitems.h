/*
 * Name: Risheel Gunda
 * Instructor: Prof. Keathly
 * Date: 4/19/21
 * Assignment: HW 4
 */
#ifndef LIBRARYITEMS_H
#define LIBRARYITEMS_H
#include "libraryitems.h"
#include "dvd.h"
#include "audioCD.h"
#include "book.h"
#include <vector>
#include <cstdlib>
#include <fstream>
#include <iomanip>

class LibraryItems {
public:
    vector<LibraryItem*> libraryItemList;
    void addBook(Book* b);
    void addDVD(DVD* d);
    void addAudioCD(AudioCD* a);
    void editItem(int ID, int currStatus);
    void removeItem(int ID);
    LibraryItem* findItem(int ID);
    void printItemList();
    void printItemDetails(int ID);

    void outputToFile(ofstream &fout);
    void inputFile();

};


#endif
