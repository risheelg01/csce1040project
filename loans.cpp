/*
 * Name: Risheel Gunda
 * Instructor: Professor Keathly
 * Date: 4/19/21
 * Assignment: HWK4
 */

#include "loans.h"
#include <vector>
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;

//Use findPatron method to access the Patron object
//Check if there are any overdue books or if the patron has 6 books
//	If either condition is true, patron cannot check out a book
//Use findBook method to access the Book object
//Check the book’s current status if it is out, repair, or lost
//	If either condition is true, patron cannot check out this book
//		If lost, use reportLost method
//
//If both checks are passed
//	 use editBook method to update the book info
//	use editPatron method to update the patron info
//	Create a Loan object
//	Populate Loan object
//	Add Loan object to collection
void Loans::checkOutItem(LibraryItems& items,Patrons& patrons, int bookID, int patronID, int loanID) {

    Patron p=patrons.findPatron(patronID);
    if(p.getCurrentNumberBooksOut()==6||p.getFineBalance()>0)
    {
        cout<<p.getName()<<" cannot check out an item."<<endl;

    }
    else
    {
        LibraryItem* li=items.findItem(bookID);
        if (li->getCurrentStatus()!=LibraryItem::IN)
        {
            cout<<p.getName()<<" cannot check out an item."<<endl;
            if(li->getCurrentStatus()==LibraryItem::LOST)
            {
                reportLost(patrons,items,bookID);
            }
        }
        else{
            items.editItem(bookID,LibraryItem::OUT);
            patrons.editPatron(patronID,p.getCurrentNumberBooksOut()+1);
            //time reference
            //citation: https://www.daniweb.com/programming/software-development/threads/165479/c-add-days-to-date

            time_t now = time(NULL);
            struct tm* tm = localtime(&now);
            tm->tm_mday += items.findItem(bookID)->getLoanPeriod();
            time_t later = mktime(tm);
            string stringTime =ctime(&later);


            Loan l(bookID,patronID,loanID,false,stringTime,0);
            loanlist.push_back(l);

        }
    }

}
//Use findBook method to access the Book object
//Check if the Book is overdue with currentStatus
//If it is overdue, use the payFine method to charge the Patron a fine
//Update the book info with editBook
//Use findPatron method to access the Patron object
//		Update the patron info with editPatron
//
//Delete the Loan object from the list using erase() method
void Loans::checkInItem(LibraryItems &items, Patrons &patrons, int bookID, int patronID, int loanID) {
    LibraryItem* li=items.findItem(bookID);
    Loan l=findLoan(loanID);
    Patron p=patrons.findPatron(patronID);
    if(l.getCurrentStatus()==Loan::OVERDUE)
    {
        //citation: https://www.daniweb.com/programming/software-development/threads/165479/c-add-days-to-date
        time_t rawtime=time(&rawtime);
        string stringTime=ctime(&rawtime);
        int currDay=stoi(stringTime.substr(8,2));
        int dueDay=stoi(l.getDueDateTime().substr(8,2));
        double fine=0.25*(currDay-dueDay);

        patrons.payFines(patronID,fine);

    }
    items.editItem(bookID,LibraryItem::IN);
    patrons.editPatron(patronID,p.getCurrentNumberBooksOut()-1);
    for(int i=0;i<loanlist.size();i++)
    {
        if(loanlist.at(i).getLoanID()==loanID)
        {
            loanlist.erase(loanlist.begin()+i);
            break;
        }
    }

}

//Use a for loop to iterate through the loanlist
//For each iteration, check if the Loan object is overdue with currentStatus
//If overdue, use findPatron method to access the Patron object
//Print out the Patron object’s info with print Specific Patron method
//Print out the book info with print specific book method
void Loans::listAllOverdueBooks(Patrons &patrons, LibraryItems &items) {
    for(int i=0;i<loanlist.size();i++)
    {
        if(loanlist.at(i).getCurrentStatus()==Loan::OVERDUE)
        {
            patrons.printPatronDetails(loanlist.at(i).getPatronID());
            cout<<endl;
            items.printItemDetails(loanlist.at(i).getBookID());
            cout<<endl;
        }

    }
}
//Use a for loop to iterate through the loanlist
//For each iteration, check if the Loan object’s Patron ID matches user input
//		If true, print out the book info with print Specific Book method
void Loans::listBooksForPatron(LibraryItems& items, int patronID) {

    for(int i=0;i<loanlist.size();i++)
    {
        if(loanlist.at(i).getPatronID()==patronID)
        {
            items.printItemDetails(loanlist.at(i).getBookID());
            cout<<endl;
        }

    }
}
//If clock passes 10 days since book was loaned change currentStatus to overdue with edit Loan method
void Loans::updateLoanStatus(int loanID) {

    //citation: https://www.daniweb.com/programming/software-development/threads/165479/c-add-days-to-date
    time_t rawtime=time(&rawtime);
    string stringTime=ctime(&rawtime);
    int currDay=stoi(stringTime.substr(8,2));
    int dueDay;
    for(int i=0;i<loanlist.size();i++)
    {
        if(loanlist.at(i).getLoanID()==loanID)
        {
            dueDay=stoi(loanlist.at(i).getDueDateTime().substr(8,2));
            if(currDay>dueDay)
                editLoan(loanID,Loan::OVERDUE);
            break;
        }

    }


}

//Use a for loop to iterate through the loanlist
//If the book ID matches the book ID of a Loan object
//		Check if the recheck variable is already true
//			If true, book cannot be rechecked
//			If false, change recheck to true and edit the loan using the edit Loan method
//		Terminate loop because book has been found
void Loans::recheckBook(int bookID, LibraryItems& items) {
    for(int i=0;i<loanlist.size();i++)
    {
        if(loanlist.at(i).getBookID()==bookID)
        {
            if(!loanlist.at(i).getRecheck())
            {
                //citation: https://www.daniweb.com/programming/software-development/threads/165479/c-add-days-to-date
                loanlist.at(i).setRecheck(true);
                LibraryItem* li=items.findItem(bookID);
                time_t now = time(NULL);
                struct tm* tm = localtime(&now);
                tm->tm_mday += li->getLoanPeriod();
                time_t later = mktime(tm);
                string stringTime =ctime(&later);
                loanlist.at(i).setDueDateTime(stringTime);

            }
            else
            {
                cout<<"Item cannot be rechecked."<<endl;
            }
            break;
        }


    }

}
//Replace specified Loan object instance variables with new values
void Loans::editLoan(int loanID, int currentStatus) {
    for(int i=0;i<loanlist.size();i++)
    {
        if(loanlist.at(i).getLoanID()==loanID)
        {
            loanlist.at(i).setCurrentStatus(currentStatus);
            break;
        }
    }
}

//Use the find Patron method to access the Patron object
//For each iteration, check if the patron ID from the Loan of the missing book matches the Patron ID of the Patron object
//		If true, use the find Book method to access the Book object
//			Add the cost of the book to the Patron’s fines
//			Terminate loop because patron has been found
void Loans::reportLost(Patrons &patrons,LibraryItems &items, int bookID) {
    for(int i=0;i<loanlist.size();i++)
    {
        if(loanlist.at(i).getBookID()==bookID)
        {
            LibraryItem* li=items.findItem(bookID);
            patrons.payFines(loanlist.at(i).getPatronID(),li->getCost());
            break;
        }
    }
}

//Use for loop to iterate through the list
//Return the Loan object with matching ID
Loan Loans::findLoan(int loanID) {
    for(int i=0;i<loanlist.size();i++)
    {
        if(loanlist.at(i).getLoanID()==loanID)
            return loanlist.at(i);
    }
}

//Iterate through vector, fout the info for each iteration
void Loans::outputToFile(ofstream &fout) {
    for(int i=0;i<loanlist.size();i++)
    {
        fout<<loanlist.at(i).getBookID()<<endl;
        fout<<loanlist.at(i).getPatronID()<<endl;
        fout<<loanlist.at(i).getLoanID()<<endl;
        fout<<loanlist.at(i).getRecheck()<<endl;
        fout<<loanlist.at(i).getDueDateTime();
        fout<<loanlist.at(i).getCurrentStatus()<<endl;
    }
}

//Check if file exists already
//	If exists, fin the object info and add to vector
void Loans::inputFile() {
    ifstream fin("loan.txt");
    int bookID,patronID,loanID;
    bool recheck;
    string time;
    int status;
    if(!fin.fail())
    {
        while(!fin.eof())
        {
            fin>>bookID;
            if(fin.eof())
                break;
            fin>>patronID;
            fin>>loanID;
            fin>>recheck;
            fin.ignore();
            getline(fin,time);
            //fin.ignore();
            fin>>status;
            Loan l(bookID,patronID,loanID,recheck,time+"\n",status);
            loanlist.push_back(l);
        }
        remove("loan.txt");
    }
}

