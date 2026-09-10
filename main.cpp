#include <iostream>

using namespace std;

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
