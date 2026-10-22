// Lab 10 - Part A, Exercise 2 : move the Nth element of a linked list-based queue to the front
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

class linkedQueueType {
private:
    Node *queueFront;
    Node *queueRear;

public:
    linkedQueueType() {
        queueFront = NULL;
        queueRear = NULL;
    }

    ~linkedQueueType() {
        while (!isEmpty())
            dequeue();
    }

    bool isEmpty() {
        return queueFront == NULL;
    }

    void enqueue(int value) {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;

        if (isEmpty())
            queueFront = newNode;
        else
            queueRear->next = newNode;
        queueRear = newNode;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow! Nothing to dequeue." << endl;
            return 0;
        }
        Node *temp = queueFront;
        int value = temp->data;
        queueFront = queueFront->next;
        if (queueFront == NULL)
            queueRear = NULL;
        delete temp;
        return value;
    }

    int size() {
        int count = 0;
        Node *current = queueFront;
        while (current != NULL) {
            count++;
            current = current->next;
        }
        return count;
    }

    // pull the Nth element out, enqueue it, then rotate the others behind it
    void moveNthFront(int n) {
        int count = size();
        if (n < 1 || n > count) {
            cout << "Invalid N! Queue has " << count << " element(s)." << endl;
            return;
        }

        // pass 1: cycle every element once, holding back the Nth one
        int nthValue = 0;
        for (int i = 1; i <= count; i++) {
            int value = dequeue();
            if (i == n)
                nthValue = value;
            else
                enqueue(value);
        }

        // pass 2: Nth goes to the rear, then the rest cycle behind it
        enqueue(nthValue);
        for (int i = 1; i < count; i++)
            enqueue(dequeue());
    }

    void display() {
        cout << "{";
        Node *current = queueFront;
        while (current != NULL) {
            cout << current->data;
            if (current->next != NULL)
                cout << ", ";
            current = current->next;
        }
        cout << "}" << endl;
    }
};

int main() {
    linkedQueueType queue;
    int values[] = {5, 11, 34, 67, 43, 55};
    for (int i = 0; i < 6; i++)
        queue.enqueue(values[i]);

    int n;
    cout << "queue = ";
    queue.display();
    cout << "Enter N: ";
    cin >> n;

    queue.moveNthFront(n);

    cout << "After moveNthFront(" << n << "):" << endl;
    cout << "queue = ";
    queue.display();

    return 0;
}
