// Lab 8 - Part B, Exercise 1 : music player using a doubly linked list
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cstdlib>
using namespace std;

struct Song {
    int no;          // song number, given when the song is created
    string artist;
    string title;
    int released;
    string genre;
    double length;
    Song *prev;
    Song *next;
};

int nextSongNo = 1;  // next song number to hand out

Song *createSong(string artist, string title, int released, string genre, double length);
Song *copySong(Song *song);

void insertAtBeginning(Song *&head, Song *&tail, Song *newNode);
void insertAtEnd(Song *&head, Song *&tail, Song *newNode);
void insertAtPosition(Song *&head, Song *&tail, Song *newNode, int position);
void insertSortedByNo(Song *&head, Song *&tail, Song *newNode);

void deleteFromBeginning(Song *&head, Song *&tail);
void deleteFromEnd(Song *&head, Song *&tail);
void deleteByArtist(Song *&head, Song *&tail, string artist);
void unlinkNode(Song *&head, Song *&tail, Song *node);
void clearList(Song *&head, Song *&tail);

void printHeader();
void printSong(Song *song);
void displayList(Song *head);
void displaySortedByNo(Song *head);
void browseSongs(Song *head);
void searchByGenre(Song *head, string genre);

Song *readSongDetails();
int countSongs(Song *head);
string toLower(string text);
int readInt(string prompt);
double readDouble(string prompt);
string readLine(string prompt);

int main() {
    Song *head = NULL;
    Song *tail = NULL;
    int choice;

    /* Starting song list from the question */
    insertAtEnd(head, tail, createSong("Celine Dion", "Just Walk Away", 1993, "Pop", 4.58));
    insertAtEnd(head, tail, createSong("Taylor Swift", "You Belong With Me", 2008, "Pop", 3.48));
    insertAtEnd(head, tail, createSong("The Cranberries", "Promises", 1999, "Rock", 4.30));

    do {
        cout << "\n========== Music Player ==========" << endl;
        cout << "1.  Add new song at the beginning" << endl;
        cout << "2.  Add new song at the end" << endl;
        cout << "3.  Add new song at any position" << endl;
        cout << "4.  View song list (no sorting)" << endl;
        cout << "5.  View song list sorted by song number" << endl;
        cout << "6.  View songs one by one (previous / next)" << endl;
        cout << "7.  Delete song from the beginning" << endl;
        cout << "8.  Delete song from the end" << endl;
        cout << "9.  Delete song by artist name" << endl;
        cout << "10. Search song by genre" << endl;
        cout << "11. Exit" << endl;
        choice = readInt("Enter your choice: ");

        switch (choice) {
            case 1:
                insertAtBeginning(head, tail, readSongDetails());
                cout << "Song added at the beginning." << endl;
                break;
            case 2:
                insertAtEnd(head, tail, readSongDetails());
                cout << "Song added at the end." << endl;
                break;
            case 3: {
                int total = countSongs(head);
                int position = readInt("Enter position (1 - " + to_string(total + 1) + "): ");
                if (position < 1 || position > total + 1) {
                    cout << "Invalid position." << endl;
                    break;
                }
                insertAtPosition(head, tail, readSongDetails(), position);
                cout << "Song added at position " << position << "." << endl;
                break;
            }
            case 4:
                displayList(head);
                break;
            case 5:
                displaySortedByNo(head);
                break;
            case 6:
                browseSongs(head);
                break;
            case 7:
                deleteFromBeginning(head, tail);
                break;
            case 8:
                deleteFromEnd(head, tail);
                break;
            case 9:
                deleteByArtist(head, tail, readLine("Enter artist name: "));
                break;
            case 10:
                searchByGenre(head, readLine("Enter genre: "));
                break;
            case 11:
                cout << "Goodbye." << endl;
                break;
            default:
                cout << "Invalid choice, please enter 1 - 11." << endl;
        }
    } while (choice != 11);

    clearList(head, tail);
    return 0;
}

/* ---------------- Node creation ---------------- */

Song *createSong(string artist, string title, int released, string genre, double length) {
    Song *newNode = new Song;
    newNode->no = nextSongNo++;
    newNode->artist = artist;
    newNode->title = title;
    newNode->released = released;
    newNode->genre = genre;
    newNode->length = length;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Same details and song number, but its own links
Song *copySong(Song *song) {
    Song *newNode = new Song;
    *newNode = *song;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

/* ---------------- Insert functions ---------------- */

void insertAtBeginning(Song *&head, Song *&tail, Song *newNode) {
    if (head == NULL) {
        head = tail = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertAtEnd(Song *&head, Song *&tail, Song *newNode) {
    if (tail == NULL) {
        head = tail = newNode;
        return;
    }

    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
}

// position starts from 1; position = count + 1 means the end
void insertAtPosition(Song *&head, Song *&tail, Song *newNode, int position) {
    if (position <= 1 || head == NULL) {
        insertAtBeginning(head, tail, newNode);
        return;
    }

    // Walk to the node currently sitting at that position
    Song *current = head;
    for (int i = 1; i < position && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        insertAtEnd(head, tail, newNode);
        return;
    }

    newNode->next = current;
    newNode->prev = current->prev;
    current->prev->next = newNode;
    current->prev = newNode;
}

void insertSortedByNo(Song *&head, Song *&tail, Song *newNode) {
    Song *current = head;
    while (current != NULL && current->no <= newNode->no) {
        current = current->next;
    }

    if (current == NULL) {
        insertAtEnd(head, tail, newNode);
    } else if (current == head) {
        insertAtBeginning(head, tail, newNode);
    } else {
        newNode->next = current;
        newNode->prev = current->prev;
        current->prev->next = newNode;
        current->prev = newNode;
    }
}

/* ---------------- Delete functions ---------------- */

// Detach node from the list and free it
void unlinkNode(Song *&head, Song *&tail, Song *node) {
    if (node->prev == NULL) {
        head = node->next;
    } else {
        node->prev->next = node->next;
    }

    if (node->next == NULL) {
        tail = node->prev;
    } else {
        node->next->prev = node->prev;
    }
    delete node;
}

void deleteFromBeginning(Song *&head, Song *&tail) {
    if (head == NULL) {
        cout << "The song list is empty, nothing to delete." << endl;
        return;
    }

    cout << "Deleted: " << head->title << " by " << head->artist << endl;
    unlinkNode(head, tail, head);
}

void deleteFromEnd(Song *&head, Song *&tail) {
    if (tail == NULL) {
        cout << "The song list is empty, nothing to delete." << endl;
        return;
    }

    cout << "Deleted: " << tail->title << " by " << tail->artist << endl;
    unlinkNode(head, tail, tail);
}

// Removes the first song by that artist (case insensitive)
void deleteByArtist(Song *&head, Song *&tail, string artist) {
    if (head == NULL) {
        cout << "The song list is empty, nothing to delete." << endl;
        return;
    }

    string target = toLower(artist);
    Song *current = head;
    while (current != NULL && toLower(current->artist) != target) {
        current = current->next;
    }

    if (current == NULL) {
        cout << "No song by \"" << artist << "\" was found." << endl;
        return;
    }

    cout << "Deleted: " << current->title << " by " << current->artist << endl;
    unlinkNode(head, tail, current);
}

void clearList(Song *&head, Song *&tail) {
    while (head != NULL) {
        unlinkNode(head, tail, head);
    }
}

/* ---------------- Display functions ---------------- */

void printHeader() {
    cout << left << setw(5) << "No" << setw(18) << "Artist" << setw(22) << "Song"
         << setw(10) << "Released" << setw(8) << "Genre" << "Length" << endl;
    cout << string(69, '-') << endl;
}

void printSong(Song *song) {
    cout << left << setw(5) << song->no << setw(18) << song->artist << setw(22) << song->title
         << setw(10) << song->released << setw(8) << song->genre
         << fixed << setprecision(2) << song->length << endl;
}

void displayList(Song *head) {
    if (head == NULL) {
        cout << "The song list is empty." << endl;
        return;
    }

    printHeader();
    for (Song *current = head; current != NULL; current = current->next) {
        printSong(current);
    }
}

// Sort a copy so the original play order stays as it is
void displaySortedByNo(Song *head) {
    Song *sortedHead = NULL;
    Song *sortedTail = NULL;

    for (Song *current = head; current != NULL; current = current->next) {
        insertSortedByNo(sortedHead, sortedTail, copySong(current));
    }

    displayList(sortedHead);
    clearList(sortedHead, sortedTail);
}

void browseSongs(Song *head) {
    if (head == NULL) {
        cout << "The song list is empty." << endl;
        return;
    }

    int total = countSongs(head);
    int index = 1;
    Song *current = head;
    string command;

    while (true) {
        cout << "\n--- Song " << index << " of " << total << " ---" << endl;
        cout << "Song No  : " << current->no << endl;
        cout << "Artist   : " << current->artist << endl;
        cout << "Song     : " << current->title << endl;
        cout << "Released : " << current->released << endl;
        cout << "Genre    : " << current->genre << endl;
        cout << "Length   : " << fixed << setprecision(2) << current->length << endl;

        command = toLower(readLine("[P] Previous  [N] Next  [Q] Back to menu: "));

        if (command == "q") {
            return;
        } else if (command == "n") {
            if (current->next == NULL) {
                cout << "This is the last song." << endl;
            } else {
                current = current->next;
                index++;
            }
        } else if (command == "p") {
            if (current->prev == NULL) {
                cout << "This is the first song." << endl;
            } else {
                current = current->prev;
                index--;
            }
        } else {
            cout << "Invalid option." << endl;
        }
    }
}

void searchByGenre(Song *head, string genre) {
    string target = toLower(genre);
    bool found = false;

    for (Song *current = head; current != NULL; current = current->next) {
        if (toLower(current->genre) == target) {
            if (!found) {
                printHeader();
                found = true;
            }
            printSong(current);
        }
    }

    if (!found) {
        cout << "No song with genre \"" << genre << "\" was found." << endl;
    }
}

/* ---------------- Helpers ---------------- */

Song *readSongDetails() {
    string artist = readLine("Artist   : ");
    string title = readLine("Song     : ");
    int released = readInt("Released : ");
    string genre = readLine("Genre    : ");
    double length = readDouble("Length   : ");
    return createSong(artist, title, released, genre, length);
}

int countSongs(Song *head) {
    int count = 0;
    for (Song *current = head; current != NULL; current = current->next) {
        count++;
    }
    return count;
}

string toLower(string text) {
    for (size_t i = 0; i < text.length(); i++) {
        text[i] = (char)tolower((unsigned char)text[i]);
    }
    return text;
}

int readInt(string prompt) {
    int value;
    cout << prompt;
    while (!(cin >> value)) {
        if (cin.eof()) exit(0);   // input closed, nothing more to read
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a number: ";
    }
    return value;
}

double readDouble(string prompt) {
    double value;
    cout << prompt;
    while (!(cin >> value)) {
        if (cin.eof()) exit(0);
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a number: ";
    }
    return value;
}

// Skips the newline left behind by cin >> and reads a full line
string readLine(string prompt) {
    string text;
    cout << prompt;
    cin >> ws;
    if (!getline(cin, text)) exit(0);
    return text;
}
