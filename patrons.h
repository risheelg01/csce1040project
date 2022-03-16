/*
 * Name: Risheel Gunda
 * Instructor: Professor Keathly
 * Date: 4/19/21
 * Assignment: HWK4
 */

#ifndef PATRONS_H
#define PATRONS_H
#include <vector>
#include <string>
#include <fstream>
#include "patron.h"
using namespace std;
class Patrons {
    //declare vector to hold Patron objects
private:
    vector<Patron> patronlist;
    //method declarations
public:
    void addPatron(Patron p);
    void deletePatron(int ID);
    void editPatron(int ID,int numBooks);
    Patron findPatron(int ID);
    void printPatronList();
    void printPatronDetails(int ID);
    void payFines(int ID, double fine);
    void outputToFile(ofstream& fout);
    void inputFile();
};


#endif
