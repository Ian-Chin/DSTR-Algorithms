// Lab 7 - Part A, Exercise 2 : deleteItemAt() - delete the node at a given index
#include <iostream>
using namespace std;

struct Student {
    int data;        // student id
    Student *next;
};

void insertAtEnd(Student *&head, int id);
void display(Student *head);
void deleteItemAt(Student *&head, int index);   // index starts at 0

int main() {
    Student *head = NULL;

    insertAtEnd(head, 1001);
    insertAtEnd(head, 1002);
    insertAtEnd(head, 1003);
    insertAtEnd(head, 1004);

    cout << "Original list" << endl;
    display(head);

    cout << "\nAfter deleteItemAt(2)" << endl;
    deleteItemAt(head, 2);
    display(head);

    cout << "\nAfter deleteItemAt(0)" << endl;
    deleteItemAt(head, 0);
    display(head);

    cout << "\nAfter deleteItemAt(7) - index out of range" << endl;
    deleteItemAt(head, 7);
    display(head);

    while (head != NULL) {
        deleteItemAt(head, 0);
    }

    return 0;
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

void display(Student *head) {
    if (head == NULL) {
        cout << "The list is empty." << endl;
        return;
    }

    int index = 0;
    Student *current = head;
    while (current != NULL) {
        cout << "Index " << index << " : Student ID " << current->data << endl;
        current = current->next;
        index++;
    }
}

void deleteItemAt(Student *&head, int index) {
    if (head == NULL) {
        cout << "The list is empty, nothing to delete." << endl;
        return;
    }

    if (index < 0) {
        cout << "Index " << index << " is not valid." << endl;
        return;
    }

    // Deleting the first node just moves the head forward
    if (index == 0) {
        Student *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    // Walk to the node sitting just before the requested index
    Student *previous = head;
    for (int i = 0; i < index - 1 && previous->next != NULL; i++) {
        previous = previous->next;
    }

    if (previous->next == NULL) {
        cout << "Index " << index << " is out of range." << endl;
        return;
    }

    Student *target = previous->next;
    previous->next = target->next;
    delete target;
}
