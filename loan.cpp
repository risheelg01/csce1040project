//
/*
 * Name: Risheel Gunda
 * Instructor: Professor Keathly
 * Date: 4/19/21
 * Assignment: HWK4
 */

#include "loan.h"
#include <string>
using namespace std;
//implementation of methods
Loan::Loan()
{
    bookID=0;
    patronID=0;
    loanID=0;
    recheck=false;
    dueDateTime="";
    currentStatus=NORMAL;
}

Loan::Loan(int b, int p, int l, bool r, string d, int c) {
    bookID=b;
    patronID=p;
    loanID=l;
    recheck=r;
    dueDateTime=d;
    currentStatus=static_cast<Status>(c);
}

void Loan::setBookID(int b) {
    bookID=b;
}
int Loan::getBookID() {
    return bookID;
}
void Loan::setPatronID(int p) {
    patronID=p;
}
int Loan::getPatronID() {
    return patronID;
}
void Loan::setLoanID(int l) {
    loanID=l;
}
int Loan::getLoanID() {
    return loanID;
}
void Loan::setRecheck(bool r) {
    recheck=r;
}
bool Loan::getRecheck() {
    return recheck;
}
void Loan::setDueDateTime(string d) {
    dueDateTime=d;
}
string Loan::getDueDateTime() {
    return dueDateTime;
}
void Loan::setCurrentStatus(int c) {
    currentStatus=static_cast<Status>(c);
}
int Loan::getCurrentStatus() {
    return currentStatus;
}
