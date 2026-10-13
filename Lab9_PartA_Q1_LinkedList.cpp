// Lab 9 - Part A, Exercise 1(b) : stack operations using a linked list-based stack
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node *next;
};

Node *top = NULL;

void push(string value);
void pop();
bool isEmpty();
void displayBaseToTop(Node *current);
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
    cout << "Current List: ";
    displayBaseToTop(top);
    cout << endl << endl;

    cout << "From Top to base :" << endl;
    displayTopToBase();

    // release the remaining nodes
    while (!isEmpty()) {
        Node *temp = top;
        top = top->next;
        delete temp;
    }
    return 0;
}

bool isEmpty() {
    return top == NULL;
}

void push(string value) {
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = top;     // new node sits on top of the old top
    top = newNode;

    cout << "Push " << value << " :" << endl;
    cout << "Current List: ";
    displayBaseToTop(top);
    cout << endl << endl;
}

void pop() {
    if (isEmpty()) {
        cout << "Stack underflow! Nothing to pop." << endl << endl;
        return;
    }
    Node *temp = top;
    string value = temp->data;
    top = top->next;
    delete temp;

    cout << "Pop " << value << ": " << value << " is deleted!" << endl;
    cout << "Current List: ";
    displayBaseToTop(top);
    cout << endl << endl;
}

// recursion reaches the base first, then prints on the way back up
void displayBaseToTop(Node *current) {
    if (current == NULL)
        return;
    displayBaseToTop(current->next);
    cout << current->data << " , ";
}

void displayTopToBase() {
    cout << "Current List: ";
    Node *current = top;
    while (current != NULL) {
        cout << current->data << " , ";
        current = current->next;
    }
    cout << endl;
}
