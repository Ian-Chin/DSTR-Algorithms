// Lab 6 - Part D (Homework), Exercise 1 : Music player system - insert at the beginning,
//                                         insert at the end and view the song list
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Song {
    int no;
    string artist;
    string title;
    int released;
    string genre;
    float length;
    Song *next;
};

void insertAtBeginning(Song *&head, Song *newNode);
void insertAtEnd(Song *&head, Song *newNode);
void viewList(Song *head);

Song *createSong(int no, string artist, string title, int released, string genre, float length);
Song *readSongFromUser();
void loadDefaultSongs(Song *&head);
void printHeader();
void printSong(Song *s);
void clearList(Song *&head);

int main() {
    Song *head = NULL;
    loadDefaultSongs(head);

    int choice;
    do {
        cout << "\n=============== MUSIC PLAYER ===============" << endl;
        cout << "1. Insert a song at the beginning of the list" << endl;
        cout << "2. Insert a song at the end of the list" << endl;
        cout << "3. View the song list" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        // A non numeric entry would leave cin in a failed state, so reset it
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Please enter a number from the menu." << endl;
            continue;
        }
        cin.ignore(1000, '\n');

        if (choice == 1) {
            insertAtBeginning(head, readSongFromUser());
            viewList(head);
        } else if (choice == 2) {
            insertAtEnd(head, readSongFromUser());
            viewList(head);
        } else if (choice == 3) {
            viewList(head);
        } else if (choice != 0) {
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    clearList(head);
    cout << "Goodbye." << endl;

    return 0;
}

/* ---------------- Helpers ---------------- */

Song *createSong(int no, string artist, string title, int released, string genre, float length) {
    Song *newNode = new Song;
    newNode->no = no;
    newNode->artist = artist;
    newNode->title = title;
    newNode->released = released;
    newNode->genre = genre;
    newNode->length = length;
    newNode->next = NULL;
    return newNode;
}

Song *readSongFromUser() {
    int no, released;
    float length;
    string artist, title, genre;

    cout << "Song number  : ";
    cin >> no;
    cin.ignore(1000, '\n');
    cout << "Artist       : ";
    getline(cin, artist);
    cout << "Song title   : ";
    getline(cin, title);
    cout << "Year release : ";
    cin >> released;
    cin.ignore(1000, '\n');
    cout << "Genre        : ";
    getline(cin, genre);
    cout << "Length       : ";
    cin >> length;
    cin.ignore(1000, '\n');

    return createSong(no, artist, title, released, genre, length);
}

void loadDefaultSongs(Song *&head) {
    insertAtEnd(head, createSong(1, "Celine Dion", "Just Walk Away", 1993, "Pop", 4.58f));
    insertAtEnd(head, createSong(2, "Taylor Swift", "You Belong With Me", 2008, "Pop", 3.48f));
    insertAtEnd(head, createSong(3, "The Cranberries", "Promises", 1999, "Rock", 4.30f));
}

void printHeader() {
    cout << left
         << setw(5)  << "No"
         << setw(22) << "Artist"
         << setw(34) << "Song"
         << setw(10) << "Released"
         << setw(12) << "Genre"
         << "Length" << endl;
    cout << string(89, '-') << endl;
}

void printSong(Song *s) {
    cout << left
         << setw(5)  << s->no
         << setw(22) << s->artist
         << setw(34) << s->title
         << setw(10) << s->released
         << setw(12) << s->genre
         << fixed << setprecision(2) << s->length << endl;
}

void clearList(Song *&head) {
    while (head != NULL) {
        Song *temp = head;
        head = head->next;
        delete temp;
    }
}

/* ---------------- List functionalities ---------------- */

void insertAtBeginning(Song *&head, Song *newNode) {
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(Song *&head, Song *newNode) {
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Song *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void viewList(Song *head) {
    cout << "\nCurrent song list" << endl;

    if (head == NULL) {
        cout << "The song list is empty." << endl;
        return;
    }

    printHeader();
    Song *current = head;
    while (current != NULL) {
        printSong(current);
        current = current->next;
    }
}
