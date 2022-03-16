/*
 * Name: Risheel Gunda
 * Instructor: Prof. Keathly
 * Date: 4/19/21
 * Assignment: HW 4
 */
#include "dvd.h"

DVD::DVD() {

    title="";
    category="";
    runtime="";
    studio="";
    releaseDate="";

}

DVD::DVD(int l, double c, int s, int lp, string t, string ca, string r, string st, string d):LibraryItem(l,c,s,lp) {

    title=t;
    category=ca;
    runtime=r;
    studio=st;
    releaseDate=d;
}

void DVD::setTitle(string t) {
    title=t;
}

string DVD::getTitle() {
    return title;
}

void DVD::setCategory(string ca) {
    category=ca;
}

string DVD::getCategory() {

    return category;
}

void DVD::setRuntime(string r) {
    runtime=r;
}

string DVD::getRuntime() {
    return runtime;
}

void DVD::setStudio(string st) {
    studio=st;
}

string DVD::getStudio() {
    return studio;
}

void DVD::setReleaseDate(string d) {
    releaseDate=d;
}

string DVD::getReleaseDate() {
    return releaseDate;
}

string DVD::getType() {
    return "DVD";
}

void DVD::display() {
    cout<<getType()<<endl;
    cout<<"Title: "<<getTitle()<<endl;
    cout<<"Category: "<<getCategory()<<endl;
    cout<<"Runtime: "<<getRuntime()<<endl;
    cout<<"Studio: "<<getStudio()<<endl;
    cout<<"Release Date: "<<getReleaseDate()<<endl;
    LibraryItem::display();
}

void DVD::print(ostream &out)
{
    LibraryItem::print(out);
    out<<getType()<<endl;
    out<<getTitle()<<endl;
    out<<getCategory()<<endl;
    out<<getRuntime()<<endl;
    out<<getStudio()<<endl;
    out<<getReleaseDate()<<endl;
}

