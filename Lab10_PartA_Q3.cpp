// Lab 10 - Part A, Exercise 3 : palindrome check using an array-based queue and stack
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

const int MAX_SIZE = 100;

struct Queue {
    char items[MAX_SIZE];
    int front;
    int rear;
    int count;
};

struct Stack {
    char items[MAX_SIZE];
    int top;
};

void enqueue(Queue &q, char value);
char dequeue(Queue &q);
void push(Stack &s, char value);
char pop(Stack &s);
bool isPalindrome(string text);

int main() {
    string text;

    cout << "Enter a line of text: ";
    getline(cin, text);
    cout << endl;

    if (isPalindrome(text))
        cout << "\"" << text << "\" is a palindrome." << endl;
    else
        cout << "\"" << text << "\" is not a palindrome." << endl;

    return 0;
}

// circular array: rear wraps back to index 0 when it reaches the end
void enqueue(Queue &q, char value) {
    q.rear = (q.rear + 1) % MAX_SIZE;
    q.items[q.rear] = value;
    q.count++;
}

char dequeue(Queue &q) {
    char value = q.items[q.front];
    q.front = (q.front + 1) % MAX_SIZE;
    q.count--;
    return value;
}

void push(Stack &s, char value) {
    s.items[++s.top] = value;
}

char pop(Stack &s) {
    return s.items[s.top--];
}

bool isPalindrome(string text) {
    Queue q;
    q.front = 0;
    q.rear = MAX_SIZE - 1;
    q.count = 0;

    Stack s;
    s.top = -1;

    // keep letters and digits only, lowercased, in both structures
    for (int i = 0; i < (int)text.length() && q.count < MAX_SIZE; i++) {
        char ch = text[i];
        if (isalnum(ch)) {
            ch = tolower(ch);
            enqueue(q, ch);
            push(s, ch);
        }
    }

    // queue gives letters forward, stack gives them backward
    while (q.count > 0) {
        if (dequeue(q) != pop(s))
            return false;
    }
    return true;
}
