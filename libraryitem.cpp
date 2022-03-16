/*
 * Name: Risheel Gunda
 * Instructor: Prof. Keathly
 * Date: 4/19/21
 * Assignment: HW 4
 */
#include "libraryitem.h"
#include <iostream>
#include <string>
using namespace std;

LibraryItem::LibraryItem()
{
    libraryIDNumber=0;
    cost=0;
    currentStatus=Status::IN;
    loanPeriod=0;
}

LibraryItem::LibraryItem(int l, double c, int s, int lp)
{
    libraryIDNumber=l;
    cost=c;
    currentStatus=static_cast<Status>(s);
    loanPeriod=lp;
}
void LibraryItem::setLibraryIDNumber(int l) {
    libraryIDNumber=l;
}
int LibraryItem::getLibraryIDNumber() {
    return libraryIDNumber;
}
void LibraryItem::setCost(double c) {
    cost=c;
}
double LibraryItem::getCost() {
    return cost;
}

void LibraryItem::setCurrentStatus(int s) {
    currentStatus=static_cast<Status>(s);
}

int LibraryItem::getCurrentStatus() {
    return currentStatus;
}

void LibraryItem::setLoanPeriod(int lp) {
    loanPeriod=lp;

}
int LibraryItem::getLoanPeriod() {
    return loanPeriod;
}

string LibraryItem::getType() {
    return "LibraryItem";
}

void LibraryItem::display() {
    cout<<"Library ID Number: "<<getLibraryIDNumber()<<endl;
    cout<<"Cost: "<<getCost()<<endl;
    cout<<"Current Status: "<<enum_str[getCurrentStatus()]<<endl;
    cout<<"Loan Period: "<<getLoanPeriod()<<endl;

}

void LibraryItem::print(ostream& out)
{
    out<<getLibraryIDNumber()<<endl;
    out<<getCost()<<endl;
    out<<getCurrentStatus()<<endl;
    out<<getLoanPeriod()<<endl;
}