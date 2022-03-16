/*
 * Name: Risheel Gunda
 * Instructor: Professor Keathly
 * Date: 4/19/21
 * Assignment: HWK4
 */

#include "patron.h"
#include <string>
using namespace std;
//implementation of patron methods
Patron::Patron() {
    IDNumber=0;
    name="";
    fineBalance=0;
    currentnumBooksOut=0;
}
Patron::Patron(int i, string n,double f,int c)
{
    IDNumber=i;
    name=n;
    fineBalance=f;
    currentnumBooksOut=c;
}

void Patron::setIDNumber(int i) {
    IDNumber=i;
}
int Patron::getIDNumber() {
    return IDNumber;
}
void Patron::setName(string n) {
    name=n;
}
string Patron::getName() {
    return name;
}
void Patron::setFineBalance(double f) {
    fineBalance=f;
}
double Patron::getFineBalance() {
    return fineBalance;
}
void Patron::setCurrentNumberBooksOut(int c) {
    currentnumBooksOut=c;
}

int Patron::getCurrentNumberBooksOut() {
    return currentnumBooksOut;
}

