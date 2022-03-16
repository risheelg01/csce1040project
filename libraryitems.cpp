
/*
 * Name: Risheel Gunda
 * Instructor: Prof. Keathly
 * Date: 4/19/21
 * Assignment: HW 4
 */
#include "libraryitems.h"
#include <iostream>
using namespace std;


void LibraryItems::addBook(Book *b) {
    libraryItemList.push_back(b);
}

void LibraryItems::addAudioCD(AudioCD *a) {
    libraryItemList.push_back(a);
}

void LibraryItems::addDVD(DVD *d) {
    libraryItemList.push_back(d);
}

void LibraryItems::removeItem(int ID) {
    for(int i=0;i<libraryItemList.size();i++)
    {
        if(libraryItemList.at(i)->getLibraryIDNumber()==ID) {
            libraryItemList.erase(libraryItemList.begin() + i);
            break;
        }

    }

}

LibraryItem* LibraryItems::findItem(int ID) {
    for(int i=0;i<libraryItemList.size();i++)
    {
        if(libraryItemList.at(i)->getLibraryIDNumber()==ID)
        {
            return libraryItemList.at(i);
        }
    }
}

void LibraryItems::editItem(int ID, int currStatus) {
    for(int i=0;i<libraryItemList.size();i++)
    {
        if(libraryItemList.at(i)->getLibraryIDNumber()==ID)
        {
            libraryItemList.at(i)->setCurrentStatus(currStatus);
            break;
        }
    }
}

void LibraryItems::printItemDetails(int ID) {
    for(int i=0;i<libraryItemList.size();i++)
    {
        if(libraryItemList.at(i)->getLibraryIDNumber()==ID)
        {
            libraryItemList.at(i)->display();
            break;
        }
    }
}

void LibraryItems::printItemList() {
    for(int i=0;i<libraryItemList.size();i++)
    {
        libraryItemList.at(i)->display();
        cout<<endl;
    }
}

void LibraryItems::outputToFile(ofstream &fout) {
    for(int i=0;i<libraryItemList.size();i++)
    {

        fout<<*(libraryItemList.at(i));

    }
}

void LibraryItems::inputFile() {
    ifstream fin("libraryitems.txt");
    int l;
    double c;
    int s;
    int lp;
    string type;
    while(!fin.fail())
    {
        fin>>l;
        if(fin.eof())
            break;
        fin>>c;
        fin>>s;
        fin>>lp;
        fin.ignore();
        getline(fin,type);
        if(type=="Book")
        {
            string t,a,i,ca;
            getline(fin,t);
            getline(fin, a);
            getline(fin, i);
            getline(fin, ca);
            libraryItemList.push_back(new Book(l,c,s,lp,a,t,i,ca));
        }
        else if (type=="AudioCD")
        {
            string a,t,r,g;
            int n;
            getline(fin,a);
            getline(fin,t);
            fin>>n;
            fin.ignore();
            getline(fin, r);
            getline(fin,g);
            libraryItemList.push_back(new AudioCD(l,c,s,lp,a,t,n,r,g));
        }
        else if(type=="DVD")
        {
            string t,ca,r,st,d;
            getline(fin,t);
            getline(fin,ca);
            getline(fin,r);
            getline(fin,st);
            getline(fin,d);
            libraryItemList.push_back(new DVD(l,c,s,lp,t,ca,r,st,d));
        }

        remove("libraryitems.txt");
    }
}