// Lab 6 - Part C, Exercise 1 : Struct declaration for a linked list node holding a student id
#include <iostream>
using namespace std;

struct Student {
    int id;         // student id
    Student *next;  // points to the next structure in the list
};

int main() {
    Student *node = new Student;
    node->id = 76218;
    node->next = NULL;

    cout << "Student id   : " << node->id << endl;
    cout << "Next address : " << node->next << endl;

    delete node;

    return 0;
}
