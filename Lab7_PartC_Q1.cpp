// Lab 7 - Part C, Exercise 1 : Music player system - insertion, deletion and searching
//                              on a singly linked list of songs
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

/* Lab 5 functionalities */
void insertAtBeginning(Song *&head, Song *newNode);
void insertAtEnd(Song *&head, Song *newNode);
void viewList(Song *head);
void viewSortedByNumber(Song *head);

/* Lab 7 functionalities */
void deleteFromBeginning(Song *&head);
void deleteFromEnd(Song *&head);
void deleteByArtist(Song *&head, string artist);
void deleteByNumber(Song *&head, int no);
void searchByGenre(Song *head, string genre);

/* Helpers */
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
        cout << "4. View the song list sorted by song number" << endl;
        cout << "5. Delete a song from the beginning of the list" << endl;
        cout << "6. Delete a song from the end of the list" << endl;
        cout << "7. Delete a song by artist name" << endl;
        cout << "8. Delete a song by song number" << endl;
        cout << "9. Search a song by genre" << endl;
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
        } else if (choice == 4) {
            viewSortedByNumber(head);
        } else if (choice == 5) {
            deleteFromBeginning(head);
            viewList(head);
        } else if (choice == 6) {
            deleteFromEnd(head);
            viewList(head);
        } else if (choice == 7) {
            string artist;
            cout << "Enter the artist name to delete : ";
            getline(cin, artist);
            deleteByArtist(head, artist);
            viewList(head);
        } else if (choice == 8) {
            int no;
            cout << "Enter the song number to delete : ";
            cin >> no;
            cin.ignore(1000, '\n');
            deleteByNumber(head, no);
            viewList(head);
        } else if (choice == 9) {
            string genre;
            cout << "Enter the genre to search : ";
            getline(cin, genre);
            searchByGenre(head, genre);
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

/* ---------------- Lab 5 functionalities ---------------- */

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

void viewSortedByNumber(Song *head) {
    cout << "\nSong list sorted by song number" << endl;

    if (head == NULL) {
        cout << "The song list is empty." << endl;
        return;
    }

    /* Build a second list with the insert to sorted list concept so the
       original order of the song list is not changed */
    Song *sorted = NULL;
    Song *current = head;

    while (current != NULL) {
        Song *copy = createSong(current->no, current->artist, current->title,
                                current->released, current->genre, current->length);

        if (sorted == NULL || copy->no < sorted->no) {
            copy->next = sorted;
            sorted = copy;
        } else {
            Song *previous = sorted;
            while (previous->next != NULL && previous->next->no < copy->no) {
                previous = previous->next;
            }
            copy->next = previous->next;
            previous->next = copy;
        }
        current = current->next;
    }

    printHeader();
    Song *node = sorted;
    while (node != NULL) {
        printSong(node);
        node = node->next;
    }

    clearList(sorted);
}

/* ---------------- Lab 7 functionalities ---------------- */

void deleteFromBeginning(Song *&head) {
    if (head == NULL) {
        cout << "The song list is empty, nothing to delete." << endl;
        return;
    }

    Song *temp = head;
    cout << "Deleted : " << temp->title << " by " << temp->artist << endl;
    head = head->next;
    delete temp;
}

void deleteFromEnd(Song *&head) {
    if (head == NULL) {
        cout << "The song list is empty, nothing to delete." << endl;
        return;
    }

    // Only one song in the list
    if (head->next == NULL) {
        cout << "Deleted : " << head->title << " by " << head->artist << endl;
        delete head;
        head = NULL;
        return;
    }

    // Stop at the second last node so its next can be cut off
    Song *current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    cout << "Deleted : " << current->next->title << " by " << current->next->artist << endl;
    delete current->next;
    current->next = NULL;
}

void deleteByArtist(Song *&head, string artist) {
    if (head == NULL) {
        cout << "The song list is empty, nothing to delete." << endl;
        return;
    }

    // The song to remove is the first one
    if (head->artist == artist) {
        Song *temp = head;
        head = head->next;
        cout << "Deleted : " << temp->title << " by " << temp->artist << endl;
        delete temp;
        return;
    }

    Song *previous = head;
    while (previous->next != NULL && previous->next->artist != artist) {
        previous = previous->next;
    }

    if (previous->next == NULL) {
        cout << "Artist \"" << artist << "\" was not found." << endl;
        return;
    }

    Song *target = previous->next;
    previous->next = target->next;
    cout << "Deleted : " << target->title << " by " << target->artist << endl;
    delete target;
}

void deleteByNumber(Song *&head, int no) {
    if (head == NULL) {
        cout << "The song list is empty, nothing to delete." << endl;
        return;
    }

    if (head->no == no) {
        Song *temp = head;
        head = head->next;
        cout << "Deleted : " << temp->title << " by " << temp->artist << endl;
        delete temp;
        return;
    }

    Song *previous = head;
    while (previous->next != NULL && previous->next->no != no) {
        previous = previous->next;
    }

    if (previous->next == NULL) {
        cout << "Song number " << no << " was not found." << endl;
        return;
    }

    Song *target = previous->next;
    previous->next = target->next;
    cout << "Deleted : " << target->title << " by " << target->artist << endl;
    delete target;
}

void searchByGenre(Song *head, string genre) {
    cout << "\nSearch result for genre \"" << genre << "\"" << endl;

    int found = 0;
    Song *current = head;

    while (current != NULL) {
        if (current->genre == genre) {
            if (found == 0) {
                printHeader();
            }
            printSong(current);
            found++;
        }
        current = current->next;
    }

    if (found == 0) {
        cout << "No song with the genre \"" << genre << "\" was found." << endl;
    } else {
        cout << found << " song(s) found." << endl;
    }
}
