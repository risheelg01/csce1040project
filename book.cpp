//
/*
 * Name: Risheel Gunda
 * Instructor: Professor Keathly
 * Date: 4/19/21
 * Assignment: HWK3
 */

#include "book.h"
#include <string>
using namespace std;
//implementation of methods
Book::Book() {
    author="";
    title="";
    ISBNNumber="";
    category="";
}
Book::Book(int l, double c, int s, int lp,string a, string t, string i, string ca):LibraryItem(l,c,s,lp) {

    author=a;
    title=t;
    ISBNNumber=i;
    category=ca;
}

void Book::setAuthor(string a) {
    author=a;
}
string Book::getAuthor() {
    return author;
}

void Book::setTitle(string t) {
    title=t;
}
string Book::getTitle() {
    return title;
}
void Book::setISBNNumber(string i) {
    ISBNNumber=i;
}
string Book::getISBNNumber() {
    return ISBNNumber;
}
/*void Book::setLibraryIDNumber(int l) {
    libraryIDNumber=l;
}
int Book::getLibraryIDNumber() {
    return libraryIDNumber;
}
void Book::setCost(double c) {
    cost=c;
}
double Book::getCost() {
    return cost;
}

void Book::setCurrentStatus(int s) {
    currentStatus=static_cast<Status>(s);
}

int Book::getCurrentStatus() {
    return currentStatus;
}*/

void Book::setCategory(string c) {
    category=c;
}

string Book::getCategory() {
    return category;
}

string Book::getType() {
    return "Book";
}

void Book::display() {
    cout<<getType()<<endl;

    cout<<"Title: "<<getTitle()<<endl;
    cout<<"Author: "<<getAuthor()<<endl;
    cout<<"ISBN Number: "<<getISBNNumber()<<endl;
    cout<<"Category: "<<getCategory()<<endl;
    LibraryItem::display();
}

void Book::print(ostream &out) {
    LibraryItem::print(out);
    out<<getType()<<endl;
    out<<getTitle()<<endl;
    out<<getAuthor()<<endl;
    out<<getISBNNumber()<<endl;
    out<<getCategory()<<endl;

}