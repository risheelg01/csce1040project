/*
 * Name: Risheel Gunda
 * Instructor: Professor Keathly
 * Date: 3/19/21
 * Assignment: HWK3
 */

#ifndef BOOK_H
#define BOOK_H
#include "libraryitem.h"
#include <string>

using namespace std;

class Book:public LibraryItem {

    //method declarations
public:
    /*enum Status
    {
        IN,OUT,REPAIR,LOST
    };
    string enum_str[4]={"IN","OUT","REPAIR","LOST"};*/
    Book();
    Book(int l, double c, int s, int lp,string a,string t, string i,string ca);
    void setAuthor(string a);
    string getAuthor();
    void setTitle(string t);
    string getTitle();
    void setISBNNumber(string i);
    string getISBNNumber();
    /*void setLibraryIDNumber(int l);
    int getLibraryIDNumber();
    void setCost(double c);
    double getCost();
    void setCurrentStatus(int s);
    int getCurrentStatus();*/
    void setCategory(string c);
    string getCategory();
    string getType() override;
    void display() override;
    void print(ostream& out) override;

    //instance variables
private:
    string author;
    string title;
    string ISBNNumber;
    string category;





};


#endif
