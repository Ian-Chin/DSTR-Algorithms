// Lab 9 - Part A, Exercise 2 : check balanced parentheses using a linked list-based stack
#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node *next;
};

void push(Node *&top, char value);
char pop(Node *&top);
bool isEmpty(Node *top);
bool isMatchingPair(char left, char right);
bool isBalanced(string expression);

int main() {
    string equation;

    cout << "Enter your equation here: ";
    getline(cin, equation);
    cout << endl;

    if (isBalanced(equation))
        cout << "The parenthesis of the equation is balance. Thus equation correct in term of writing." << endl;
    else
        cout << "The parenthesis of the equation is not balance. Thus equation is not correct in term of writing." << endl;

    return 0;
}

void push(Node *&top, char value) {
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

char pop(Node *&top) {
    Node *temp = top;
    char value = temp->data;
    top = top->next;
    delete temp;
    return value;
}

bool isEmpty(Node *top) {
    return top == NULL;
}

bool isMatchingPair(char left, char right) {
    return (left == '(' && right == ')') ||
           (left == '[' && right == ']') ||
           (left == '{' && right == '}');
}

bool isBalanced(string expression) {
    Node *top = NULL;
    bool balanced = true;

    for (int i = 0; i < (int)expression.length() && balanced; i++) {
        char ch = expression[i];

        // left delimiter: push onto the stack
        if (ch == '(' || ch == '[' || ch == '{') {
            push(top, ch);
        }
        // right delimiter: pop and check it matches
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (isEmpty(top) || !isMatchingPair(pop(top), ch))
                balanced = false;
        }
    }

    // any left delimiter still on the stack was never closed
    if (!isEmpty(top))
        balanced = false;

    while (!isEmpty(top))
        pop(top);

    return balanced;
}
