/*
 * Name: Risheel Gunda
 * Instructor: Professor Keathly
 * Date: 4/19/21
 * Assignment: HWK4
 */

#include "patrons.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

//implementation of patrons methods


/*
 * Prompt user for ID
   Prompt user for name
   Create Patron Object
   Populate Patron Object
   Add object to collection

 */
void Patrons::addPatron(Patron p) {
    patronlist.push_back(p);
}

//Delete the Patron object in the list using erase() method
void Patrons::deletePatron(int ID) {
    for(int i=0;i<patronlist.size();i++)
    {
        if(patronlist.at(i).getIDNumber()==ID)
        {
            patronlist.erase(patronlist.begin()+i);
            break;
        }
    }
}

//Replace specified Patron object instance variables with new values
void Patrons::editPatron(int ID,int numBooks) {

    for(int i=0;i<patronlist.size();i++)
    {
        if(patronlist.at(i).getIDNumber()==ID)
        {
            patronlist.at(i).setCurrentNumberBooksOut(numBooks);
            break;
        }
    }
}
/*
 * Use for loop to iterate through the list
 * Return the Patron object with matching ID

 */
Patron Patrons::findPatron(int ID) {
    for(int i=0;i<patronlist.size();i++)
    {
        if(patronlist.at(i).getIDNumber()==ID)
        {
            return patronlist.at(i);
        }
    }
}

//Print all instance variables of the specific Patron
void Patrons::printPatronDetails(int ID) {
    Patron p=findPatron(ID);
    cout<<"Patron info:"<<endl;
    cout<<"ID Number: "<<p.getIDNumber()<<endl;
    cout<<"Name: "<<p.getName()<<endl;
    cout<<"Fine Balance: "<<p.getFineBalance()<<endl;
    cout<<"Current # of books out: "<<p.getCurrentNumberBooksOut()<<endl;

}

/*
 * Use for loop to iterate through the list
 * For each iteration, print out all the instance variables of the ith Patron object with Print Specific Patron method

 */
void Patrons::printPatronList() {
    for (int i = 0; i < patronlist.size(); ++i) {
        printPatronDetails(patronlist.at(i).getIDNumber());
        cout<<endl;
    }
}
//Add the fine to the Patron’s fines based on the days overdue
void Patrons::payFines(int ID, double fine)
{
    for(int i=0;i<patronlist.size();i++)
    {
        if(patronlist.at(i).getIDNumber()==ID)
        {
            patronlist.at(i).setFineBalance(patronlist.at(i).getFineBalance()+fine);
            break;
        }
    }
}
//Iterate through vector, fout the info for each iteration
void Patrons::outputToFile(ofstream &fout) {
    for(int i=0;i<patronlist.size();i++)
    {
        fout<<patronlist.at(i).getIDNumber()<<endl;
        fout<<patronlist.at(i).getName()<<endl;
        fout<<patronlist.at(i).getFineBalance()<<endl;
        fout<<patronlist.at(i).getCurrentNumberBooksOut()<<endl;
    }
}
//Check if file exists already
//	If exists, fin the object info and add to vector
void Patrons::inputFile()
{
    ifstream fin("patron.txt");
    int ID;
    string name;
    double fine;
    int books;
    if(!fin.fail())
    {

        while(!fin.eof()) {
            fin >> ID;
            if(fin.eof())
                break;
            fin.ignore();
            getline(fin, name);
            fin >> fine;
            fin >> books;
            Patron p(ID,name,fine,books);
            addPatron(p);
        }
        remove("patron.txt");
    }
}
