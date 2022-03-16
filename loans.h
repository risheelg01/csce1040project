/*
 * Name: Risheel Gunda
 * Instructor: Professor Keathly
 * Date: 4/19/21
 * Assignment: HWK4
 */

#ifndef LOANS_H
#define LOANS_H
#include <vector>
#include <string>
#include <fstream>
#include "loan.h"
#include "libraryitems.h"
#include "patrons.h"

class Loans {
    //instance variables
private:
    vector<Loan> loanlist;
    //method declaration
public:
    void checkInItem(LibraryItems& items,Patrons& patrons, int bookID, int patronID, int loanID);
    void checkOutItem(LibraryItems& items,Patrons& patrons, int bookID, int patronID, int loanID);
    void listAllOverdueBooks(Patrons &patrons, LibraryItems &items);
    void listBooksForPatron(LibraryItems& items,int patronID);
    void updateLoanStatus(int loanID);
    void recheckBook(int bookID, LibraryItems& items);
    void editLoan(int loanID, int currentStatus);
    Loan findLoan(int loanID);
    void reportLost(Patrons& patrons, LibraryItems& items, int bookID);
    void outputToFile(ofstream& fout);
    void inputFile();

};


#endif
