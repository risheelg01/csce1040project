/*
 * Name: Risheel Gunda
 * Instructor: Professor Keathly
 * Date: 4/19/21
 * Assignment: HWK4
 */

#ifndef LOAN_H
#define LOAN_H
#include<string>
using namespace std;

class Loan {
    //method declarations
public:
    Loan();
    Loan(int b, int p, int l, bool r,string d,int c);
    void setBookID(int b);
    int getBookID();
    void setPatronID(int p);
    int getPatronID();
    void setLoanID(int l);
    int getLoanID();
    void setRecheck(bool r);
    bool getRecheck();
    void setDueDateTime(string d);
    string getDueDateTime();
    void setCurrentStatus(int c);
    int getCurrentStatus();
    enum Status{NORMAL,OVERDUE};
    //instance variables
private:
    int bookID;
    int patronID;
    int loanID;
    bool recheck;
    string dueDateTime;
    Status currentStatus;


};


#endif
