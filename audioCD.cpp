/*
 * Name: Risheel Gunda
 * Instructor: Prof. Keathly
 * Date: 4/19/21
 * Assignment: HW 4
 */
#include "audioCD.h"
using namespace std;
AudioCD::AudioCD()
{
    artist="";
    title="";
    numberOfTracks=0;
    releaseDate="";
    genre="";
}

AudioCD::AudioCD(int l, double c, int s, int lp, string a, string t, int n, string r, string g):LibraryItem(l,c,s,lp) {

    artist=a;
    title=t;
    numberOfTracks=n;
    releaseDate=r;
    genre=g;
}

void AudioCD::setArtist(string a) {
    artist=a;
}

string AudioCD::getArtist() {
    return artist;

}

void AudioCD::setTitle(string t) {
    title=t;
}

string  AudioCD::getTitle() {
    return title;
}

void AudioCD::setNumberOfTracks(int n) {
    numberOfTracks=n;
}

int AudioCD::getNumberOfTracks() {
    return numberOfTracks;
}

void AudioCD::setReleaseDate(string r) {
    releaseDate=r;
}

string AudioCD::getReleaseDate() {
    return releaseDate;
}

void AudioCD::setGenre(string g) {
    genre=g;
}

string AudioCD::getGenre() {
    return genre;
}

string AudioCD::getType() {
    return "AudioCD";
}

void AudioCD::display() {
    cout<<getType()<<endl;
    cout<<"Artist: "<<getArtist()<<endl;
    cout<<"Title: "<<getTitle()<<endl;
    cout<<"Number of Tracks: "<<getNumberOfTracks()<<endl;
    cout<<"Release Date: "<<getReleaseDate()<<endl;
    cout<<"Genre: "<<getGenre()<<endl;
    LibraryItem::display();
}

void AudioCD::print(ostream &out)
{
    LibraryItem::print(out);
    out<<getType()<<endl;
    out<<getArtist()<<endl;
    out<<getTitle()<<endl;
    out<<getNumberOfTracks()<<endl;
    out<<getReleaseDate()<<endl;
    out<<getGenre()<<endl;
}