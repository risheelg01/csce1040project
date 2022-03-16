/*
 * Name: Risheel Gunda
 * Instructor: Prof. Keathly
 * Date: 4/19/21
 * Assignment: HW 4
 */
#ifndef DVD_H
#define DVD_H
#include "libraryitem.h"
using namespace std;

class DVD:public LibraryItem {
private:
    string title;
    string category;
    string runtime;
    string studio;
    string releaseDate;
public:
    DVD(int l, double c, int s, int lp,string t, string ca , string r,string st, string d);
    DVD();
    void setTitle(string t);
    string getTitle();
    void setCategory(string ca);
    string getCategory();
    void setRuntime(string r);
    string getRuntime();
    void setStudio(string st);
    string getStudio();
    void setReleaseDate(string d);
    string getReleaseDate();
    string getType() override;
    void display() override;
    void print(ostream &out) override;
};


#endif
