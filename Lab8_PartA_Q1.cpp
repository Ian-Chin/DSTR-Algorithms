// Lab 8 - Part A, Exercise 1 : insert, delete and display students in a doubly linked list
#include <iostream>
#include <limits>
#include <cstdlib>
using namespace std;

struct Student {
    int data;        // student id
    Student *prev;
    Student *next;
};

Student *createNode(int id);

void insertAtBeginning(Student *&head, Student *&tail, int id);
void insertAtEnd(Student *&head, Student *&tail, int id);
void insertSorted(Student *&head, Student *&tail, int id);

void deleteFromBeginning(Student *&head, Student *&tail);
void deleteFromEnd(Student *&head, Student *&tail);
void deleteSorted(Student *&head, Student *&tail, int id);

void displayForward(Student *head);
void displayReverse(Student *tail);

void sortList(Student *&head, Student *&tail);
int readInt(string prompt);

int main() {
    Student *head = NULL;
    Student *tail = NULL;
    int choice;

    do {
        cout << "\nMenu List:" << endl;
        cout << "--------------------------" << endl;
        cout << "1. Add student ID in the front of the list" << endl;
        cout << "2. Add student ID at the end of the list" << endl;
        cout << "3. Sort current student list based on ID and display" << endl;
        cout << "4. Delete student ID from the front of the list" << endl;
        cout << "5. Delete student ID from the end of the list" << endl;
        cout << "6. Delete student ID based on the user input" << endl;
        cout << "7. Display student list" << endl;
        cout << "8. Display the reverse student list" << endl;
        cout << "9. Exit" << endl;
        choice = readInt("\nEnter your choice: ");

        switch (choice) {
            case 1:
                insertAtBeginning(head, tail, readInt("Enter student ID: "));
                break;
            case 2:
                insertAtEnd(head, tail, readInt("Enter student ID: "));
                break;
            case 3:
                sortList(head, tail);
                displayForward(head);
                break;
            case 4:
                deleteFromBeginning(head, tail);
                break;
            case 5:
                deleteFromEnd(head, tail);
                break;
            case 6:
                // deleteSorted relies on the order, so sort first
                sortList(head, tail);
                deleteSorted(head, tail, readInt("Enter student ID to delete: "));
                break;
            case 7:
                displayForward(head);
                break;
            case 8:
                displayReverse(tail);
                break;
            case 9:
                cout << "Goodbye." << endl;
                break;
            default:
                cout << "Invalid choice, please enter 1 - 9." << endl;
        }
    } while (choice != 9);

    /* Release whatever is left so no node is leaked */
    while (head != NULL) {
        deleteFromBeginning(head, tail);
    }

    return 0;
}

Student *createNode(int id) {
    Student *newNode = new Student;
    newNode->data = id;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

/* ---------------- Insert functions ---------------- */

void insertAtBeginning(Student *&head, Student *&tail, int id) {
    Student *newNode = createNode(id);

    if (head == NULL) {
        head = tail = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertAtEnd(Student *&head, Student *&tail, int id) {
    Student *newNode = createNode(id);

    if (tail == NULL) {
        head = tail = newNode;
        return;
    }

    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
}

void insertSorted(Student *&head, Student *&tail, int id) {
    // Empty list, or the new id belongs in front of the current head
    if (head == NULL || id < head->data) {
        insertAtBeginning(head, tail, id);
        return;
    }

    // Find the first node bigger than id, the new node goes before it
    Student *current = head;
    while (current != NULL && current->data <= id) {
        current = current->next;
    }

    if (current == NULL) {
        insertAtEnd(head, tail, id);
        return;
    }

    Student *newNode = createNode(id);
    newNode->next = current;
    newNode->prev = current->prev;
    current->prev->next = newNode;
    current->prev = newNode;
}

/* ---------------- Delete functions ---------------- */

void deleteFromBeginning(Student *&head, Student *&tail) {
    if (head == NULL) {
        cout << "The list is empty, nothing to delete." << endl;
        return;
    }

    Student *temp = head;
    head = head->next;

    if (head == NULL) {
        tail = NULL;          // list is now empty
    } else {
        head->prev = NULL;
    }
    delete temp;
}

void deleteFromEnd(Student *&head, Student *&tail) {
    if (tail == NULL) {
        cout << "The list is empty, nothing to delete." << endl;
        return;
    }

    // No traversal needed, tail->prev is the second last node
    Student *temp = tail;
    tail = tail->prev;

    if (tail == NULL) {
        head = NULL;          // list is now empty
    } else {
        tail->next = NULL;
    }
    delete temp;
}

void deleteSorted(Student *&head, Student *&tail, int id) {
    if (head == NULL) {
        cout << "The list is empty, nothing to delete." << endl;
        return;
    }

    // The list is sorted, so stop as soon as we pass id
    Student *current = head;
    while (current != NULL && current->data < id) {
        current = current->next;
    }

    if (current == NULL || current->data != id) {
        cout << "Student ID " << id << " was not found." << endl;
        return;
    }

    if (current == head) {
        deleteFromBeginning(head, tail);
    } else if (current == tail) {
        deleteFromEnd(head, tail);
    } else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
    }
    cout << "Student ID " << id << " deleted." << endl;
}

/* ---------------- Display functions ---------------- */

void displayForward(Student *head) {
    if (head == NULL) {
        cout << "The list is empty." << endl;
        return;
    }

    cout << "Student list (front to end):" << endl;
    Student *current = head;
    while (current != NULL) {
        cout << "Student ID : " << current->data << endl;
        current = current->next;
    }
}

void displayReverse(Student *tail) {
    if (tail == NULL) {
        cout << "The list is empty." << endl;
        return;
    }

    cout << "Student list (end to front):" << endl;
    Student *current = tail;
    while (current != NULL) {
        cout << "Student ID : " << current->data << endl;
        current = current->prev;
    }
}

/* ---------------- Helpers ---------------- */

// Rebuild the list in ascending order by moving every id into a sorted list
void sortList(Student *&head, Student *&tail) {
    Student *sortedHead = NULL;
    Student *sortedTail = NULL;

    while (head != NULL) {
        insertSorted(sortedHead, sortedTail, head->data);
        deleteFromBeginning(head, tail);
    }

    head = sortedHead;
    tail = sortedTail;
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
