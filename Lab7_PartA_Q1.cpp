// Lab 7 - Part A, Exercise 1 : delete a student from the beginning, the end
//                              and by student id in a singly linked list
#include <iostream>
using namespace std;

struct Student {
    int data;        // student id
    Student *next;
};

void insertAtBeginning(Student *&head, int id);
void insertAtEnd(Student *&head, int id);
void insertSorted(Student *&head, int id);
void display(Student *head);

void deleteFromBeginning(Student *&head);
void deleteFromEnd(Student *&head);
void deleteById(Student *&head, int id);

int main() {
    Student *head = NULL;

    /* Insert functions written in Lab 6 */
    insertAtBeginning(head, 1003);
    insertAtBeginning(head, 1002);
    insertAtEnd(head, 1005);
    insertSorted(head, 1004);

    cout << "Original list" << endl;
    display(head);

    cout << "\nAfter deleting from the beginning" << endl;
    deleteFromBeginning(head);
    display(head);

    cout << "\nAfter deleting from the end" << endl;
    deleteFromEnd(head);
    display(head);

    cout << "\nAfter deleting student id 1004" << endl;
    deleteById(head, 1004);
    display(head);

    cout << "\nAfter deleting student id 9999 (not in the list)" << endl;
    deleteById(head, 9999);
    display(head);

    /* Release whatever is left so no node is leaked */
    while (head != NULL) {
        deleteFromBeginning(head);
    }

    return 0;
}

/* ---------------- Insert functions (Lab 6) ---------------- */

void insertAtBeginning(Student *&head, int id) {
    Student *newNode = new Student;
    newNode->data = id;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(Student *&head, int id) {
    Student *newNode = new Student;
    newNode->data = id;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Student *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void insertSorted(Student *&head, int id) {
    Student *newNode = new Student;
    newNode->data = id;
    newNode->next = NULL;

    // Empty list, or the new id belongs in front of the current head
    if (head == NULL || id < head->data) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Student *current = head;
    while (current->next != NULL && current->next->data < id) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

void display(Student *head) {
    if (head == NULL) {
        cout << "The list is empty." << endl;
        return;
    }

    Student *current = head;
    while (current != NULL) {
        cout << "Student ID : " << current->data << endl;
        current = current->next;
    }
}

/* ---------------- Delete functions (Lab 7) ---------------- */

void deleteFromBeginning(Student *&head) {
    if (head == NULL) {
        cout << "The list is empty, nothing to delete." << endl;
        return;
    }

    Student *temp = head;   // hold the node before the head moves on
    head = head->next;
    delete temp;
}

void deleteFromEnd(Student *&head) {
    if (head == NULL) {
        cout << "The list is empty, nothing to delete." << endl;
        return;
    }

    // Only one node in the list
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    // Stop at the second last node so its next can be cut off
    Student *current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    delete current->next;
    current->next = NULL;
}

void deleteById(Student *&head, int id) {
    if (head == NULL) {
        cout << "The list is empty, nothing to delete." << endl;
        return;
    }

    // The node to remove is the head itself
    if (head->data == id) {
        Student *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Student *previous = head;
    while (previous->next != NULL && previous->next->data != id) {
        previous = previous->next;
    }

    if (previous->next == NULL) {
        cout << "Student ID " << id << " was not found." << endl;
        return;
    }

    Student *target = previous->next;
    previous->next = target->next;
    delete target;
}
