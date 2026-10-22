// Lab 10 - Part A, Exercise 1 : sum of all elements in three linked list-based queues
#include <iostream>
using namespace std;

struct Node {
    double data;
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

    void enqueue(double value) {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;

        if (isEmpty())
            queueFront = newNode;
        else
            queueRear->next = newNode;
        queueRear = newNode;
    }

    double dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow! Nothing to dequeue." << endl;
            return 0;
        }
        Node *temp = queueFront;
        double value = temp->data;
        queueFront = queueFront->next;
        if (queueFront == NULL)
            queueRear = NULL;
        delete temp;
        return value;
    }

    double sum() {
        double total = 0;
        Node *current = queueFront;
        while (current != NULL) {
            total += current->data;
            current = current->next;
        }
        return total;
    }
};

int main() {
    linkedQueueType Q1, Q2, Q3;

    Q1.enqueue(34.5); Q1.enqueue(22.5);
    Q1.enqueue(44.5); Q2.enqueue(10.4);
    Q2.enqueue(35.7); Q2.enqueue(38.7);
    Q2.enqueue(19.7); Q3.enqueue(Q2.dequeue());
    Q3.enqueue(Q2.dequeue()); Q3.enqueue(Q1.dequeue());
    Q2.enqueue(66.7);
    cout << Q1.sum() << ", " << Q2.sum() << ", " << Q3.sum() << "." << endl;

    return 0;
}
