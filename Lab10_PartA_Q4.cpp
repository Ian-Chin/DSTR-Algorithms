// Lab 10 - Part A, Exercise 4 : clinic queue management system using a linked list-based queue
#include <iostream>
#include <string>
using namespace std;

struct Patient {
    int number;
    string name;
    Patient *next;
};

Patient *queueFront = NULL;
Patient *queueRear = NULL;
int nextNumber = 1001;

void registerPatient();
void call();
void displayQueue();
bool isEmpty();

int main() {
    int choice;

    do {
        cout << "===== Health Center Clinic QMS =====" << endl;
        cout << "1. Register patient" << endl;
        cout << "2. Call next patient" << endl;
        cout << "3. Display queue" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        if (!(cin >> choice))
            break;
        cin.ignore(1000, '\n');
        cout << endl;

        switch (choice) {
            case 1: registerPatient(); break;
            case 2: call(); break;
            case 3: displayQueue(); break;
            case 4: cout << "Exiting QMS." << endl; break;
            default: cout << "Invalid choice!" << endl << endl;
        }
    } while (choice != 4);

    // release any patients still waiting
    while (!isEmpty()) {
        Patient *temp = queueFront;
        queueFront = queueFront->next;
        delete temp;
    }
    return 0;
}

bool isEmpty() {
    return queueFront == NULL;
}

// register is a C++ keyword, so the function is named registerPatient
void registerPatient() {
    Patient *newPatient = new Patient;
    cout << "Enter patient name: ";
    getline(cin, newPatient->name);
    newPatient->number = nextNumber++;
    newPatient->next = NULL;

    if (isEmpty())
        queueFront = newPatient;
    else
        queueRear->next = newPatient;
    queueRear = newPatient;

    cout << newPatient->name << " registered. Queue number: " << newPatient->number << endl << endl;
}

void call() {
    if (isEmpty()) {
        cout << "No patient in the queue." << endl << endl;
        return;
    }
    Patient *temp = queueFront;
    cout << "Calling number " << temp->number << ", " << temp->name << ", please proceed for treatment." << endl << endl;

    queueFront = queueFront->next;
    if (queueFront == NULL)
        queueRear = NULL;
    delete temp;
}

void displayQueue() {
    if (isEmpty()) {
        cout << "No patient in the queue." << endl << endl;
        return;
    }
    cout << "Remaining patients:" << endl;
    Patient *current = queueFront;
    int position = 1;
    while (current != NULL) {
        cout << position++ << ". [" << current->number << "] " << current->name << endl;
        current = current->next;
    }
    cout << endl;
}
