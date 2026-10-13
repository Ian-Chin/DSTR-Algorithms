// Lab 9 - Part B, Test Yourself 3 : convert an infix expression to postfix using a stack
#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node *next;
};

void push(Node *&top, char value);
char pop(Node *&top);
char peek(Node *top);
bool isEmpty(Node *top);
int precedence(char op);
bool isOperand(char ch);
string infixToPostfix(string infix);

int main() {
    string equation;

    cout << "Enter your equation here: ";
    getline(cin, equation);
    cout << endl;

    cout << "The postfix of the equation = " << infixToPostfix(equation) << endl;
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

char peek(Node *top) {
    return top->data;
}

bool isEmpty(Node *top) {
    return top == NULL;
}

// ^ > * = / > + = -
int precedence(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

bool isOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}

string infixToPostfix(string infix) {
    Node *top = NULL;
    string postfix = "";

    for (int i = 0; i < (int)infix.length(); i++) {
        char ch = infix[i];

        if (ch == ' ')
            continue;

        if (isOperand(ch)) {
            // operands go straight to the output
            postfix += ch;
        }
        else if (ch == '(') {
            push(top, ch);
        }
        else if (ch == ')') {
            // pop until the matching left parenthesis
            while (!isEmpty(top) && peek(top) != '(')
                postfix += pop(top);
            if (!isEmpty(top))
                pop(top);    // discard '('
        }
        else {
            // operator: pop operators with higher or equal precedence first
            // (right associativity of ^ is ignored, as stated in the question)
            while (!isEmpty(top) && peek(top) != '(' && precedence(peek(top)) >= precedence(ch))
                postfix += pop(top);
            push(top, ch);
        }
    }

    while (!isEmpty(top))
        postfix += pop(top);

    return postfix;
}
