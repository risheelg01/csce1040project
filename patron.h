/*
 * Name: Risheel Gunda
 * Instructor: Professor Keathly
 * Date: 4/19/21
 * Assignment: HWK4
 */

#ifndef PATRON_H
#define PATRON_H
#include <string>
using namespace std;

class Patron {
    //instance variables
private:
    int IDNumber;
    string name;
    double fineBalance;
    int currentnumBooksOut;
    //methods defined
public:
    Patron();
    Patron(int i, string n, double f, int c);
    void setIDNumber(int i);
    int getIDNumber();
    void setName(string n);
    string getName();
    void setFineBalance(double f);
    double getFineBalance();
    void setCurrentNumberBooksOut(int c);
    int getCurrentNumberBooksOut();



};


#endif
