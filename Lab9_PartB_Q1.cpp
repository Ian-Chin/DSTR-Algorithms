// Lab 9 - Part B, Test Yourself 1 : print a sequence of characters in reverse using a stack
//                                    (linked list-based and array-based)
#include <iostream>
#include <string>
using namespace std;

/* ---------- Linked list-based stack ---------- */
struct Node {
    char data;
    Node *next;
};

void listPush(Node *&top, char value);
char listPop(Node *&top);
bool listIsEmpty(Node *top);

/* ---------- Array-based stack ---------- */
const int MAX_SIZE = 100;

struct ArrayStack {
    char items[MAX_SIZE];
    int top;
};

void arrayPush(ArrayStack &s, char value);
char arrayPop(ArrayStack &s);
bool arrayIsEmpty(ArrayStack &s);
bool arrayIsFull(ArrayStack &s);

int main() {
    string input;

    cout << "Enter a sequence of characters: ";
    getline(cin, input);

    // linked list version
    Node *listTop = NULL;
    for (int i = 0; i < (int)input.length(); i++)
        listPush(listTop, input[i]);

    cout << "\nReverse (linked list stack) : ";
    while (!listIsEmpty(listTop))
        cout << listPop(listTop);
    cout << endl;

    // array version
    ArrayStack arrStack;
    arrStack.top = -1;
    for (int i = 0; i < (int)input.length(); i++)
        arrayPush(arrStack, input[i]);

    cout << "Reverse (array stack)       : ";
    while (!arrayIsEmpty(arrStack))
        cout << arrayPop(arrStack);
    cout << endl;

    return 0;
}

void listPush(Node *&top, char value) {
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

char listPop(Node *&top) {
    Node *temp = top;
    char value = temp->data;
    top = top->next;
    delete temp;
    return value;
}

bool listIsEmpty(Node *top) {
    return top == NULL;
}

void arrayPush(ArrayStack &s, char value) {
    if (arrayIsFull(s)) {
        cout << "Stack overflow! " << value << " is not pushed." << endl;
        return;
    }
    s.items[++s.top] = value;
}

char arrayPop(ArrayStack &s) {
    return s.items[s.top--];
}

bool arrayIsEmpty(ArrayStack &s) {
    return s.top == -1;
}

bool arrayIsFull(ArrayStack &s) {
    return s.top == MAX_SIZE - 1;
}
