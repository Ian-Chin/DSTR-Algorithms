// Week 7 Lecture - Class Activity 1 : Linked list implementation checked with the
//                                     program given on the slide
#include <iostream>
using namespace std;

struct Node {
    int item;
    Node *next;
};

class LinkedList {
private:
    Node *head;
    int size;

public:
    LinkedList();
    ~LinkedList();

    void insertAtBeginning(int item);
    void insertAtEnd(int item);
    void insertItemAt(int item, int index);

    void deleteFirst();
    void deleteLast();
    void deleteItemAt(int index);
    void clear();

    int getSize();
    bool isEmpty();
    void print();
};

int main() {
    LinkedList list;

    list.insertAtBeginning(1);
    list.insertAtEnd(2);
    list.insertAtBeginning(3);
    list.print();
    list.deleteFirst();
    list.print();
    list.deleteLast();
    list.print();
    list.clear();

    cout << "--- Checkpoint 1 ---" << endl;
    list.print();

    list.insertAtBeginning(5);
    list.insertAtEnd(7);
    list.insertAtEnd(8);
    list.insertAtBeginning(4);
    list.deleteItemAt(3);
    list.print();

    cout << "--- Checkpoint 2 ---" << endl;

    list.insertItemAt(6, 2);
    list.insertItemAt(3, 0);
    list.print();
    list.insertItemAt(9, list.getSize());
    list.insertItemAt(8, list.getSize() - 1);
    list.print();

    cout << "--- Checkpoint 3 ---" << endl;

    return 0;
}

/* ---------------- Constructor and destructor ---------------- */

LinkedList::LinkedList() {
    head = NULL;
    size = 0;
}

LinkedList::~LinkedList() {
    clear();
}

/* ---------------- Insertion ---------------- */

void LinkedList::insertAtBeginning(int item) {
    Node *newNode = new Node;
    newNode->item = item;
    newNode->next = head;
    head = newNode;
    size++;
}

void LinkedList::insertAtEnd(int item) {
    Node *newNode = new Node;
    newNode->item = item;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    size++;
}

// The index is zero based, so index 0 is the front and index size is the back
void LinkedList::insertItemAt(int item, int index) {
    if (index < 0 || index > size) {
        cout << "Index " << index << " is out of range, nothing was inserted." << endl;
        return;
    }

    if (index == 0) {
        insertAtBeginning(item);
        return;
    }

    if (index == size) {
        insertAtEnd(item);
        return;
    }

    // Stop at the node just before the target position
    Node *previous = head;
    for (int i = 0; i < index - 1; i++) {
        previous = previous->next;
    }

    Node *newNode = new Node;
    newNode->item = item;
    newNode->next = previous->next;
    previous->next = newNode;
    size++;
}

/* ---------------- Deletion ---------------- */

void LinkedList::deleteFirst() {
    if (head == NULL) {
        cout << "The list is empty, nothing to delete." << endl;
        return;
    }

    Node *temp = head;
    head = head->next;
    delete temp;
    size--;
}

void LinkedList::deleteLast() {
    if (head == NULL) {
        cout << "The list is empty, nothing to delete." << endl;
        return;
    }

    // Only one node in the list
    if (head->next == NULL) {
        delete head;
        head = NULL;
        size--;
        return;
    }

    // Stop at the second last node so its next can be cut off
    Node *current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    delete current->next;
    current->next = NULL;
    size--;
}

void LinkedList::deleteItemAt(int index) {
    if (index < 0 || index >= size) {
        cout << "Index " << index << " is out of range, nothing was deleted." << endl;
        return;
    }

    if (index == 0) {
        deleteFirst();
        return;
    }

    Node *previous = head;
    for (int i = 0; i < index - 1; i++) {
        previous = previous->next;
    }

    Node *target = previous->next;
    previous->next = target->next;
    delete target;
    size--;
}

void LinkedList::clear() {
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    size = 0;
}

/* ---------------- Accessors ---------------- */

int LinkedList::getSize() {
    return size;
}

bool LinkedList::isEmpty() {
    return head == NULL;
}

void LinkedList::print() {
    if (head == NULL) {
        cout << "The list is empty. (size = 0)" << endl;
        return;
    }

    Node *current = head;
    while (current != NULL) {
        cout << current->item;
        if (current->next != NULL) {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << "  (size = " << size << ")" << endl;
}
