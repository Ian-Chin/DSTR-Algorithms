// Lab 6 - Part C, Exercise 4 : Add student name and student age to the Student structure
//                              (question 3 modified, insert and display updated)
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    int age;
    Student *next;
};

Student *createStudent(int id, string name, int age);
void insertAtFront(Student *&head, int id, string name, int age);
void insertAtEnd(Student *&head, int id, string name, int age);
void display(Student *head);
void clearList(Student *&head);

int main() {
    Student *head = NULL;

    insertAtFront(head, 76218, "Ian Chin Jun Sheng", 21);
    insertAtFront(head, 76219, "Amirul Hakim", 22);

    insertAtEnd(head, 76220, "Siti Nurhaliza", 20);
    insertAtEnd(head, 76221, "Lim Wei Jie", 23);

    display(head);
    clearList(head);

    return 0;
}

Student *createStudent(int id, string name, int age) {
    Student *newNode = new Student;
    newNode->id = id;
    newNode->name = name;
    newNode->age = age;
    newNode->next = NULL;
    return newNode;
}

void insertAtFront(Student *&head, int id, string name, int age) {
    Student *newNode = createStudent(id, name, age);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(Student *&head, int id, string name, int age) {
    Student *newNode = createStudent(id, name, age);

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
    cout << "\nStudent list" << endl;

    if (head == NULL) {
        cout << "The list is empty." << endl;
        return;
    }

    cout << left
         << setw(10) << "ID"
         << setw(25) << "Name"
         << "Age" << endl;
    cout << string(38, '-') << endl;

    Student *current = head;
    while (current != NULL) {
        cout << left
             << setw(10) << current->id
             << setw(25) << current->name
             << current->age << endl;
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
