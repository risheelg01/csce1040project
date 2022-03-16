/*
 * Name: Risheel Gunda
 * Instructor: Prof. Keathly
 * Date: 4/19/21
 * Assignment: HW 4
 */
#ifndef AUDIOCD_H
#define AUDIOCD_H
#include "libraryitem.h"
using namespace std;
class AudioCD:public LibraryItem  {
private:
    string artist;
    string title;
    int numberOfTracks;
    string releaseDate;
    string genre;

public:
    AudioCD();
    AudioCD(int l, double c, int s,int lp,string a, string t, int n, string r, string g);
    void setArtist(string a);
    string getArtist();
    void setTitle(string t);
    string getTitle();
    void setNumberOfTracks(int n);
    int getNumberOfTracks();
    void setReleaseDate(string r);
    string getReleaseDate();
    void setGenre(string g );
    string getGenre();
    string getType() override;
    void display() override;
    void print(ostream& out) override;

};


#endif
