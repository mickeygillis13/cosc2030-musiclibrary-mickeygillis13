#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct MusicTrack{
    char title[100];
    char album[100];
    char artist[100];
    int duration;
    char genre[100];
    int releaseYear;
};

// Collects details for a new music track from user input and adds it to the library.
void addTrack(vector<MusicTrack>& library);

// Displays all tracks in the library with their details formatted for easy reading.
void displayLibrary(const vector<MusicTrack>& library);

// Saves the current state of the music library to a binary file for persistent storage.
void saveLibraryToFile(const vector<MusicTrack>& library, const string& filename);

// Loads the music library from a binary file, restoring previously saved track details.
void loadLibraryFromFile(vector<MusicTrack>& library, const string& filename);

// Displays a menu with options for interacting with the music library. Users can select an option to add a track, display the library list, etc. Add an option to exit the program.
void printMenu();

int main() {

}

void addTrack(vector<MusicTrack>& library){
    MusicTrack newTrack;

    cout << "title of track:" << endl;
    cin.getline(newTrack.title, 100);

    cout << "What album is the track from?:" << endl;
    cin.getline(newTrack.album, 100);

    cout << "Artist of track:" << endl;
    cin.getline(newTrack.artist, 100);

    cout << "Duration of track:" << endl;
    cin >> newTrack.duration;
    cin.ignore();

    cout << "Genre of track:" << endl;
    cin.getline(newTrack.genre, 100);

    cout << "Release year of track:" << endl;
    cin >> newTrack.releaseYear;
    cin.ignore();

    library.push_back(newTrack);
}

void displayLibrary(const vector<MusicTrack>& library){
    for(int i = 0; i < library.size(); i++){
        cout << "Title: " << library[i].title << endl;
        cout << "Album: " << library[i].album << endl;
        cout << "Artist: " << library[i].artist << endl;
        cout << "Duration: " << library[i].duration << endl;
        cout << "Genre: " << library[i].genre << endl;
        cout << "Release Year: " << library[i].releaseYear << endl;
    }
}

void saveLibraryToFile(const vector<MusicTrack>& library, const string& filename){
    ofstream outfile(filename, ios::binary);
    for(int i = 0; i < library.size(); i++){
        outfile.write(reinterpret_cast<const char*>(&library[i]),sizeof(MusicTrack));
    }
    outfile.close();
}



