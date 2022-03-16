/*
 * Name: Risheel Gunda
 * Instructor: Professor Keathly
 * Date: 4/19/21
 * Assignment: HWK4
 */
#include "loans.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void libraryMenu();


Patrons patrons;
LibraryItems items;
Loans loans;


int main() {
    //load files
    patrons.inputFile();
    items.inputFile();
    loans.inputFile();
    cout<<"Welcome to library!"<<endl<<endl;
    //execute menu
    libraryMenu();
    //save changes to files
    ofstream pout ("patron.txt");
    ofstream iout ("libraryitems.txt");
    ofstream lout ("loan.txt");
    patrons.outputToFile(pout);
    items.outputToFile(iout);
    loans.outputToFile(lout);
    return 0;
}
void libraryMenu()
{
    int ID;
    string name;
    double fineBalance;
    int booksOut;
    string option;
    string author;
    string title;
    string ISBN;
    string category;
    double cost;
    string genre;
    int lp;
    int option2;
    int patronID,bookID,loanID;
    string artist;
    int tracks;
    string release;
    string runtime;
    string studio;

    do {
        cout<<"Library Menu"<<endl;
        cout<<"ap- Add Patron"<<endl;
        cout<<"ab- Add Library Item"<<endl;
        cout<<"dp- Delete Patron"<<endl;
        cout<<"db- Delete Library Item"<<endl;
        cout<<"p1p- Print a Patron's info"<<endl;
        cout<<"b1p- Print a Library Item's info"<<endl;
        cout<<"pp- Print all Patrons info"<<endl;
        cout<<"bb- Print all Library Items' info"<<endl;
        cout<<"co- Check out a item"<<endl;
        cout<<"ci- Check in a item"<<endl;
        cout<<"lo- List all overdue items"<<endl;
        cout<<"lb- List all items for a particular patron"<<endl;
        cout<<"ul- Update loan status based on system clock"<<endl;
        cout<<"rc- Re-Check an item"<<endl;
        cout<<"qu- Quit"<<endl<<endl;
        cout<<"Choose an option:"<<endl;

        getline(cin,option);

        if(option=="ap") {
            cout<<"ADD PATRON"<<endl;
            cout<<"Enter the ID of the patron:"<<endl;
            cin>>ID;
            cin.ignore();
            cout<<"Enter the name of the patron:"<<endl;
            getline(cin, name);
            cout<<"Enter the patron's fine balance:"<<endl;
            cin>>fineBalance;
            cout<<"Enter the patron's number of books out:"<<endl;
            cin>>booksOut;
            Patron p(ID,name,fineBalance,booksOut);
            patrons.addPatron(p);
            //pout<<ID<<" "<<name<<" "<<fineBalance<<" "<<booksOut<<endl;
            cout<<endl;
            cin.ignore();

        }
        else if (option=="ab")
        {
            //status=0;
            cout<<"ADD ITEM"<<endl;
            cout<<"Enter the library ID of the item:"<<endl;
            cin>>ID;
            cout<<"Enter the cost of the item:"<<endl;
            cin>>cost;
            cout<<"Enter the loan period of the item:"<<endl;
            cin>>lp;
            cout<<endl;
            cout<<"Which Library Item do you want to add {0=Book, 1=Audio CD, 2=DVD}:"<<endl;
            cin>>option2;
            cin.ignore();
            if(option2==0) {
                cout << "ADD BOOK" << endl;
                cout << "Enter the author of the book:" << endl;
                getline(cin, author);
                cout << "Enter the title of the book:" << endl;
                getline(cin, title);
                cout << "Enter the ISBN of the book:" << endl;
                getline(cin, ISBN);
                cout<<"Enter the category of the book:"<<endl;
                getline(cin,category);
                Book *b=new Book(ID, cost, 0, lp,author, title, ISBN,category);
                items.addBook(b);
            }
            else if(option2==1)
            {
                cout<<"ADD AUDIO CD"<<endl;
                cout<<"Enter the artist of the audio CD:"<<endl;
                getline(cin,artist);
                cout<<"Enter the title of the audio CD:"<<endl;
                getline(cin, title);
                cout<<"Enter the number of tracks of the audio CD:"<<endl;
                cin>>tracks;
                cin.ignore();
                cout<<"Enter the release date of the audio CD:"<<endl;
                getline(cin, release);
                cout<<"Enter the genre of the audio CD:"<<endl;
                getline(cin, genre);
                AudioCD* a=new AudioCD(ID,cost,0,lp,artist, title, tracks,release, genre);
                items.addAudioCD(a);

            }
            else
            {
                cout<<"ADD DVD"<<endl;
                cout<<"Enter the title of the DVD:"<<endl;
                getline(cin, title);
                cout<<"Enter the category of the DVD:"<<endl;
                getline(cin, category);
                cout<<"Enter the runtime of the DVD:"<<endl;
                getline(cin, runtime);
                cout<<"Enter the studio of the DVD:"<<endl;
                getline(cin, studio);
                cout<<"Enter the release date of the DVD:"<<endl;
                getline(cin, release);
                DVD* d=new DVD(ID,cost,0,lp,title,category,runtime,studio,release);
                items.addDVD(d);

            }
            //bout<<author<<" "<<title<<" "<<ISBN<<" "<<ID<<" "<<cost<<" "<<b.enum_str[0]<<endl;
            cout<<endl;
            //cin.ignore();
        }

        else if(option=="dp")
        {
            cout<<"DELETE PATRON"<<endl;
            cout<<"Enter the ID of the patron you want to delete:"<<endl;
            cin>>ID;
            Patron p=patrons.findPatron(ID);
            patrons.deletePatron(ID);
            cout<<p.getName()<<" deleted."<<endl<<endl;
            cin.ignore();

        }

        else if(option=="db")
        {
            cout<<"DELETE ITEM"<<endl;
            cout<<"Enter the ID of the item you want to delete:"<<endl;
            cin>>ID;
            LibraryItem* li=items.findItem(ID);
            items.removeItem(ID);
            cout<<"Item deleted."<<endl<<endl;
            cin.ignore();
        }

        else if (option=="p1p")
        {
            cout<<"PRINT A PATRON'S INFO"<<endl;
            cout<<"Enter the ID of the patron:"<<endl;
            cin>>ID;
            cout<<endl;
            patrons.printPatronDetails(ID);
            cout<<endl;
            cin.ignore();
        }

        else if(option=="b1p")
        {
            cout<<"PRINT AN ITEMS INFO"<<endl;
            cout<<"Enter the ID of the item:"<<endl;
            cin>>ID;
            cout<<endl;
            items.printItemDetails(ID);
            cout<<endl;
            cin.ignore();
        }

        else if(option=="pp")
        {
            cout<<"PRINT ALL PATRONS INFO"<<endl;
            patrons.printPatronList();
        }

        else if(option=="bb")
        {
            cout<<"PRINT ALL ITEMS INFO"<<endl;
            items.printItemList();
        }

        else if(option=="co")
        {
            cout<<"CHECK OUT AN ITEM"<<endl;
            cout<<"Enter the patron ID:"<<endl;
            cin>>patronID;
            cout<<"Enter the item ID:"<<endl;
            cin>>bookID;
            cout<<"Enter the loan ID:"<<endl;
            cin>>loanID;
            loans.checkOutItem(items,patrons,bookID,patronID,loanID);
            cout<<endl;
            cin.ignore();
        }

        else if(option=="ci")
        {
            cout<<"CHECK IN AN ITEM"<<endl;
            cout<<"Enter the patron ID:"<<endl;
            cin>>patronID;
            cout<<"Enter the item ID:"<<endl;
            cin>>bookID;
            cout<<"Enter the loan ID:"<<endl;
            cin>>loanID;
            loans.checkInItem(items,patrons,bookID,patronID,loanID);
            cout<<endl;
            cin.ignore();
        }

        else if(option=="lo")
        {
            cout<<"LIST ALL OVERDUE"<<endl;
            loans.listAllOverdueBooks(patrons,items);
            cout<<endl;
        }

        else if(option=="lb")
        {
            cout<<"LIST ALL ITEMS FOR A PARTICULAR PATRON"<<endl;
            cout<<"Enter the patron's ID:"<<endl;
            cin>>ID;
            loans.listBooksForPatron(items,ID);
            cout<<endl;
            cin.ignore();
        }

        else if (option=="ul")
        {
            cout<<"UPDATE LOAN STATUS BASED ON SYSTEM CLOCK"<<endl;
            cout<<"Enter the loan ID:"<<endl;
            cin>>ID;
            loans.updateLoanStatus(ID);
            cout<<endl;
            cin.ignore();
        }

        else if(option=="rc")
        {
            cout<<"RE-CHECK A BOOK"<<endl;
            cout<<"Enter the book ID:"<<endl;
            cin>>ID;
            loans.recheckBook(ID,items);
            cout<<endl;
            cin.ignore();
        }

        else if(option=="qu")
            break;
        else
        {
            cout<<"Invalid option, try again."<<endl<<endl;
        }
        //cin.ignore();

    }while(option!="qu");
}

