// Lab 6 - Part C, Exercise 3 : Insert a new student at the end of the linked list
#include <iostream>
using namespace std;

struct Student {
    int id;
    Student *next;
};

void insertAtFront(Student *&head, int id);
void insertAtEnd(Student *&head, int id);
void display(Student *head);
void clearList(Student *&head);

int main() {
    Student *head = NULL;

    insertAtFront(head, 76218);
    insertAtFront(head, 76219);

    insertAtEnd(head, 76220);
    insertAtEnd(head, 76221);

    display(head);
    clearList(head);

    return 0;
}

void insertAtFront(Student *&head, int id) {
    Student *newNode = new Student;
    newNode->id = id;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(Student *&head, int id) {
    Student *newNode = new Student;
    newNode->id = id;
    newNode->next = NULL;

    // An empty list means the new node is also the head
    if (head == NULL) {
        head = newNode;
        return;
    }

    // Walk to the last node, then attach the new node behind it
    Student *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void display(Student *head) {
    cout << "Student list" << endl;

    if (head == NULL) {
        cout << "The list is empty." << endl;
        return;
    }

    Student *current = head;
    while (current != NULL) {
        cout << "Student id : " << current->id << endl;
        current = current->next;
    }
}

void clearList(Student *&head) {
    while (head != NULL) {
        Student *temp = head;
        head = head->next;
        delete temp;
    }
}
