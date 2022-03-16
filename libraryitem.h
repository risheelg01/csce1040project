
/*
 * Name: Risheel Gunda
 * Instructor: Prof. Keathly
 * Date: 4/19/21
 * Assignment: HW 4
 */
#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

class LibraryItem {

public:

    enum Status
    {
        IN,OUT,LOST
    };
    string enum_str[3]={"IN","OUT","LOST"};
    LibraryItem();
    LibraryItem(int l, double c, int s,int lp);
    void setLibraryIDNumber(int l);
    int getLibraryIDNumber();
    void setCost(double c);
    double getCost();
    void setCurrentStatus(int s);
    int getCurrentStatus();
    void setLoanPeriod(int lp);
    int getLoanPeriod();
    virtual string getType();
    virtual void display();
    virtual void print(ostream &out);
    friend ostream & operator<<(ostream &out,LibraryItem &l) {
        l.print(out);
        return out;
    }
protected:
    int libraryIDNumber;
    double cost;
    Status currentStatus;
    int loanPeriod;

};


#endif
