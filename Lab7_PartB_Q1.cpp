// Lab 7 - Part B, Exercise 1 : SearchStudent() - search the linked list by student id
#include <iostream>
using namespace std;

struct Student {
    int data;        // student id
    Student *next;
};

void insertAtEnd(Student *&head, int id);
void display(Student *head);
bool SearchStudent(Student *head, int id);
void deleteFromBeginning(Student *&head);

int main() {
    Student *head = NULL;

    insertAtEnd(head, 1001);
    insertAtEnd(head, 1002);
    insertAtEnd(head, 1003);
    insertAtEnd(head, 1004);

    cout << "Student record" << endl;
    display(head);

    cout << endl;
    SearchStudent(head, 1003);   // exists
    SearchStudent(head, 9999);   // does not exist

    /* Let the user try a search of their own */
    int id;
    cout << "\nEnter a student id to search : ";
    cin >> id;
    SearchStudent(head, id);

    while (head != NULL) {
        deleteFromBeginning(head);
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

    Student *current = head;
    while (current != NULL) {
        cout << "Student ID : " << current->data << endl;
        current = current->next;
    }
}

bool SearchStudent(Student *head, int id) {
    Student *current = head;

    while (current != NULL) {
        if (current->data == id) {
            cout << "Student found : " << id << endl;
            return true;
        }
        current = current->next;
    }

    cout << "Student not found : " << id << endl;
    return false;
}

void deleteFromBeginning(Student *&head) {
    if (head == NULL) {
        return;
    }

    Student *temp = head;
    head = head->next;
    delete temp;
}
