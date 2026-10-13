// Lab 9 - Part A, Exercise 1(c) : stack operations using an array-based stack
#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 10;

string stackArr[MAX_SIZE];
int top = -1;

void push(string value);
void pop();
bool isEmpty();
bool isFull();
void displayBaseToTop();
void displayTopToBase();

int main() {
    push("TP01");
    push("TP02");
    push("TP03");
    pop();
    pop();
    push("TP04");
    push("TP05");
    push("TP03");
    pop();
    push("TP02");

    cout << "From base to Top:" << endl;
    displayBaseToTop();
    cout << endl;

    cout << "From Top to base :" << endl;
    displayTopToBase();
    return 0;
}

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == MAX_SIZE - 1;
}

void push(string value) {
    if (isFull()) {
        cout << "Stack overflow! Cannot push " << value << endl << endl;
        return;
    }
    stackArr[++top] = value;

    cout << "Push " << value << " :" << endl;
    displayBaseToTop();
    cout << endl;
}

void pop() {
    if (isEmpty()) {
        cout << "Stack underflow! Nothing to pop." << endl << endl;
        return;
    }
    string value = stackArr[top--];

    cout << "Pop " << value << ": " << value << " is deleted!" << endl;
    displayBaseToTop();
    cout << endl;
}

void displayBaseToTop() {
    cout << "Current List: ";
    for (int i = 0; i <= top; i++)
        cout << stackArr[i] << " , ";
    cout << endl;
}

void displayTopToBase() {
    cout << "Current List: ";
    for (int i = top; i >= 0; i--)
        cout << stackArr[i] << " , ";
    cout << endl;
}
