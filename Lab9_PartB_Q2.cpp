// Lab 9 - Part B, Test Yourself 2 : check balanced parentheses using an array-based stack
#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 100;

struct Stack {
    char items[MAX_SIZE];
    int top;
};

void push(Stack &s, char value);
char pop(Stack &s);
bool isEmpty(Stack &s);
bool isFull(Stack &s);
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

void push(Stack &s, char value) {
    s.items[++s.top] = value;
}

char pop(Stack &s) {
    return s.items[s.top--];
}

bool isEmpty(Stack &s) {
    return s.top == -1;
}

bool isFull(Stack &s) {
    return s.top == MAX_SIZE - 1;
}

bool isMatchingPair(char left, char right) {
    return (left == '(' && right == ')') ||
           (left == '[' && right == ']') ||
           (left == '{' && right == '}');
}

bool isBalanced(string expression) {
    Stack s;
    s.top = -1;

    for (int i = 0; i < (int)expression.length(); i++) {
        char ch = expression[i];

        // left delimiter: push onto the stack
        if (ch == '(' || ch == '[' || ch == '{') {
            if (isFull(s))
                return false;
            push(s, ch);
        }
        // right delimiter: pop and check it matches
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (isEmpty(s) || !isMatchingPair(pop(s), ch))
                return false;
        }
    }

    // balanced only if every left delimiter was closed
    return isEmpty(s);
}
