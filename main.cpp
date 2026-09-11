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
    bool running = true;
    vector<MusicTrack> library;
    while (running) {
        int userChoice = 0;
        printMenu();
        cin >> userChoice;
        cin.ignore();
        if (userChoice == 1) {
            addTrack(library);
        } else if (userChoice == 2) {
            displayLibrary(library);
        } else if (userChoice == 3) {
            string filename;
            cout << "Enter the filename to save the library: ";
            cin >> filename;
            saveLibraryToFile(library, filename);
        } else if (userChoice == 4) {
            string filename;
            cout << "Enter the filename to load the library from: ";
            cin >> filename;
            loadLibraryFromFile(library, filename);
        } else if (userChoice == 5) {
            running = false;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void addTrack(vector<MusicTrack>& library){
    MusicTrack newTrack;

    cout << "Title of track:";
    cin.getline(newTrack.title, 100);

    cout << "\nWhat album is the track from?:";
    cin.getline(newTrack.album, 100);

    cout << "\nArtist of track:";
    cin.getline(newTrack.artist, 100);

    cout << "\nDuration of track:";
    cin >> newTrack.duration;
    cin.ignore();

    cout << "\nGenre of track:";
    cin.getline(newTrack.genre, 100);

    cout << "\nRelease year of track:";
    cin >> newTrack.releaseYear;
    cin.ignore();

    library.push_back(newTrack);
}

void displayLibrary(const vector<MusicTrack>& library){
    if (library.size() == 0) {
        cout << "Library is empty." << endl;
        return;
    }
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

void loadLibraryFromFile(vector<MusicTrack>& library, const string& filename){
    ifstream infile(filename, ios::binary);
    if (!infile) {
        cout << "Could not open file: " << filename << endl;
        return;
    }
    MusicTrack temp;
    while (infile.read(reinterpret_cast<char*>(&temp),sizeof(MusicTrack))){
        library.push_back(temp);
    }
    infile.close();
}

void printMenu(){
    cout << "================================================" << endl;
    cout << "Enter the number you would like to proceed with: " << endl;
    cout << "1. Add a new track to the library" << endl;
    cout << "2. Display the library list" << endl;
    cout << "3. Save the library to a file" << endl;
    cout << "4. Load the library from a file" << endl;
    cout << "5. Exit the program" << endl;
    cout << "================================================" << endl;
    cout << "Choice: ";
}




