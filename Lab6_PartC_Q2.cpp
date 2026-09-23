// Lab 6 - Part C, Exercise 2 : Insert a new student at the front of the linked list
#include <iostream>
using namespace std;

struct Student {
    int id;
    Student *next;
};

void insertAtFront(Student *&head, int id);
void display(Student *head);
void clearList(Student *&head);

int main() {
    Student *head = NULL;

    insertAtFront(head, 76218);
    insertAtFront(head, 76219);
    insertAtFront(head, 76220);

    display(head);
    clearList(head);

    return 0;
}

void insertAtFront(Student *&head, int id) {
    Student *newNode = new Student;
    newNode->id = id;

    // The new node points to the old first node, then becomes the new head
    newNode->next = head;
    head = newNode;
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
