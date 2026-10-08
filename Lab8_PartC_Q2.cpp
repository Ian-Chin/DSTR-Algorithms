// Lab 8 - Part C, Exercise 2 : cloth shopping system using doubly linked lists
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cstdlib>
using namespace std;

struct Cloth {
    string id;
    string name;
    string description;
    string color;
    int quantity;
    string category;
    Cloth *prev;
    Cloth *next;
};

struct Order {
    int orderNo;
    string customer;
    string clothId;
    string clothName;
    int quantity;
    Order *prev;
    Order *next;
};

const string ADMIN_PASSWORD = "admin123";
int nextOrderNo = 1;

/* Cloth list */
Cloth *createCloth(string id, string name, string description, string color, int quantity, string category);
Cloth *copyCloth(Cloth *cloth);
void insertClothAtEnd(Cloth *&head, Cloth *&tail, Cloth *newNode);
void insertClothSorted(Cloth *&head, Cloth *&tail, Cloth *newNode, bool (*comesBefore)(Cloth *, Cloth *));
void deleteClothById(Cloth *&head, Cloth *&tail, string id);
void clearClothList(Cloth *&head, Cloth *&tail);
Cloth *findCloth(Cloth *head, string id);

bool categoryDescending(Cloth *a, Cloth *b);
bool quantityAscending(Cloth *a, Cloth *b);

void printClothHeader();
void printCloth(Cloth *cloth);
void displayClothList(Cloth *head);
void displaySortedCloth(Cloth *head, bool (*comesBefore)(Cloth *, Cloth *));
void browseCloth(Cloth *head);
void filterByColor(Cloth *head, string color);

/* Order list */
void insertOrderAtEnd(Order *&head, Order *&tail, Order *newNode);
void clearOrderList(Order *&head, Order *&tail);
void printOrderHeader();
void printOrder(Order *order);
void displayOrders(Order *head);
void browseOrders(Order *head);

/* Menus */
void customerMenu(Cloth *&clothHead, Order *&orderHead, Order *&orderTail);
void adminMenu(Cloth *&clothHead, Cloth *&clothTail, Order *orderHead);
void placeOrder(Cloth *clothHead, Order *&orderHead, Order *&orderTail, string customer);
void addNewCloth(Cloth *&clothHead, Cloth *&clothTail);

/* Helpers */
string toLower(string text);
string toUpper(string text);
int readInt(string prompt);
string readLine(string prompt);
char readNavigation();

int main() {
    Cloth *clothHead = NULL;
    Cloth *clothTail = NULL;
    Order *orderHead = NULL;
    Order *orderTail = NULL;
    int choice;

    /* Starting cloth list from the question */
    insertClothAtEnd(clothHead, clothTail, createCloth("SRT001", "Mickey Mouse T-Shirt", "Long Sleeve", "Black", 23, "Shirt"));
    insertClothAtEnd(clothHead, clothTail, createCloth("SRT002", "Butterfly Blouse", "Short Sleeve", "White", 5, "Shirt"));
    insertClothAtEnd(clothHead, clothTail, createCloth("SKT001", "Bubble Skirt", "Short Skirt", "Yellow", 30, "Skirt"));
    insertClothAtEnd(clothHead, clothTail, createCloth("SKT002", "Jeans Skirt", "Long Skirt", "Yellow", 14, "Skirt"));
    insertClothAtEnd(clothHead, clothTail, createCloth("SKT003", "Cotton Skirt", "Long Skirt", "Black", 15, "Skirt"));
    insertClothAtEnd(clothHead, clothTail, createCloth("HAT001", "Black Hat", "With Apple", "Black", 2, "Hat"));

    do {
        cout << "\n========== Login Page ==========" << endl;
        cout << "1. Customer" << endl;
        cout << "2. Admin" << endl;
        cout << "3. Exit" << endl;
        choice = readInt("Enter your choice: ");

        switch (choice) {
            case 1:
                customerMenu(clothHead, orderHead, orderTail);
                break;
            case 2:
                if (readLine("Admin password: ") == ADMIN_PASSWORD) {
                    adminMenu(clothHead, clothTail, orderHead);
                } else {
                    cout << "Wrong password." << endl;
                }
                break;
            case 3:
                cout << "Goodbye." << endl;
                break;
            default:
                cout << "Invalid choice, please enter 1 - 3." << endl;
        }
    } while (choice != 3);

    clearClothList(clothHead, clothTail);
    clearOrderList(orderHead, orderTail);
    return 0;
}

/* ================= Menus ================= */

void customerMenu(Cloth *&clothHead, Order *&orderHead, Order *&orderTail) {
    string customer = readLine("Enter your name: ");
    int choice;

    do {
        cout << "\n========== Customer Menu (" << customer << ") ==========" << endl;
        cout << "1. View all cloth" << endl;
        cout << "2. Sort cloth by category (descending)" << endl;
        cout << "3. View cloth one by one (previous / next)" << endl;
        cout << "4. Filter cloth by color" << endl;
        cout << "5. Add an order" << endl;
        cout << "6. Exit to login page" << endl;
        choice = readInt("Enter your choice: ");

        switch (choice) {
            case 1:
                displayClothList(clothHead);
                break;
            case 2:
                displaySortedCloth(clothHead, categoryDescending);
                break;
            case 3:
                browseCloth(clothHead);
                break;
            case 4:
                filterByColor(clothHead, readLine("Enter color: "));
                break;
            case 5:
                placeOrder(clothHead, orderHead, orderTail, customer);
                break;
            case 6:
                break;
            default:
                cout << "Invalid choice, please enter 1 - 6." << endl;
        }
    } while (choice != 6);
}

void adminMenu(Cloth *&clothHead, Cloth *&clothTail, Order *orderHead) {
    int choice;

    do {
        cout << "\n========== Admin Menu ==========" << endl;
        cout << "1. Add a new cloth" << endl;
        cout << "2. Delete a cloth by cloth ID" << endl;
        cout << "3. View cloth list" << endl;
        cout << "4. Sort cloth by quantity (ascending)" << endl;
        cout << "5. View all customer orders" << endl;
        cout << "6. View orders one by one (previous / next)" << endl;
        cout << "7. Exit to login page" << endl;
        choice = readInt("Enter your choice: ");

        switch (choice) {
            case 1:
                addNewCloth(clothHead, clothTail);
                break;
            case 2:
                deleteClothById(clothHead, clothTail, toUpper(readLine("Enter cloth ID to delete: ")));
                break;
            case 3:
                displayClothList(clothHead);
                break;
            case 4:
                displaySortedCloth(clothHead, quantityAscending);
                break;
            case 5:
                displayOrders(orderHead);
                break;
            case 6:
                browseOrders(orderHead);
                break;
            case 7:
                break;
            default:
                cout << "Invalid choice, please enter 1 - 7." << endl;
        }
    } while (choice != 7);
}

void placeOrder(Cloth *clothHead, Order *&orderHead, Order *&orderTail, string customer) {
    if (clothHead == NULL) {
        cout << "No cloth available." << endl;
        return;
    }

    displayClothList(clothHead);
    Cloth *cloth = findCloth(clothHead, toUpper(readLine("Enter cloth ID to order: ")));

    if (cloth == NULL) {
        cout << "Cloth ID not found." << endl;
        return;
    }
    if (cloth->quantity == 0) {
        cout << cloth->name << " is out of stock." << endl;
        return;
    }

    int quantity = readInt("Enter quantity (1 - " + to_string(cloth->quantity) + "): ");
    if (quantity < 1 || quantity > cloth->quantity) {
        cout << "Invalid quantity." << endl;
        return;
    }

    cloth->quantity -= quantity;

    Order *newNode = new Order;
    newNode->orderNo = nextOrderNo++;
    newNode->customer = customer;
    newNode->clothId = cloth->id;
    newNode->clothName = cloth->name;
    newNode->quantity = quantity;
    newNode->prev = NULL;
    newNode->next = NULL;
    insertOrderAtEnd(orderHead, orderTail, newNode);

    cout << "Order #" << newNode->orderNo << " placed: " << quantity << " x " << cloth->name << endl;
}

void addNewCloth(Cloth *&clothHead, Cloth *&clothTail) {
    string id = toUpper(readLine("Cloth ID    : "));
    if (findCloth(clothHead, id) != NULL) {
        cout << "Cloth ID " << id << " already exists." << endl;
        return;
    }

    string name = readLine("Cloth Name  : ");
    string description = readLine("Description : ");
    string color = readLine("Color       : ");
    int quantity = readInt("Quantity    : ");
    if (quantity < 0) {
        cout << "Quantity cannot be negative." << endl;
        return;
    }
    string category = readLine("Category    : ");

    insertClothAtEnd(clothHead, clothTail, createCloth(id, name, description, color, quantity, category));
    cout << "Cloth " << id << " added." << endl;
}

/* ================= Cloth list ================= */

Cloth *createCloth(string id, string name, string description, string color, int quantity, string category) {
    Cloth *newNode = new Cloth;
    newNode->id = id;
    newNode->name = name;
    newNode->description = description;
    newNode->color = color;
    newNode->quantity = quantity;
    newNode->category = category;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Same details, but its own links
Cloth *copyCloth(Cloth *cloth) {
    Cloth *newNode = new Cloth;
    *newNode = *cloth;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertClothAtEnd(Cloth *&head, Cloth *&tail, Cloth *newNode) {
    if (tail == NULL) {
        head = tail = newNode;
        return;
    }

    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
}

// Goes before the first node it should come before; equal items keep their order
void insertClothSorted(Cloth *&head, Cloth *&tail, Cloth *newNode, bool (*comesBefore)(Cloth *, Cloth *)) {
    Cloth *current = head;
    while (current != NULL && !comesBefore(newNode, current)) {
        current = current->next;
    }

    if (current == NULL) {
        insertClothAtEnd(head, tail, newNode);
    } else if (current == head) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    } else {
        newNode->next = current;
        newNode->prev = current->prev;
        current->prev->next = newNode;
        current->prev = newNode;
    }
}

void deleteClothById(Cloth *&head, Cloth *&tail, string id) {
    Cloth *target = findCloth(head, id);

    if (target == NULL) {
        cout << "Cloth ID " << id << " was not found." << endl;
        return;
    }

    if (target->prev == NULL) {
        head = target->next;
    } else {
        target->prev->next = target->next;
    }

    if (target->next == NULL) {
        tail = target->prev;
    } else {
        target->next->prev = target->prev;
    }

    cout << "Deleted " << target->id << " (" << target->name << ")." << endl;
    delete target;
}

void clearClothList(Cloth *&head, Cloth *&tail) {
    while (head != NULL) {
        Cloth *temp = head;
        head = head->next;
        delete temp;
    }
    tail = NULL;
}

Cloth *findCloth(Cloth *head, string id) {
    for (Cloth *current = head; current != NULL; current = current->next) {
        if (current->id == id) {
            return current;
        }
    }
    return NULL;
}

bool categoryDescending(Cloth *a, Cloth *b) {
    return toLower(a->category) > toLower(b->category);
}

bool quantityAscending(Cloth *a, Cloth *b) {
    return a->quantity < b->quantity;
}

void printClothHeader() {
    cout << left << setw(9) << "ID" << setw(23) << "Cloth Name" << setw(15) << "Description"
         << setw(9) << "Color" << setw(10) << "Quantity" << "Category" << endl;
    cout << string(74, '-') << endl;
}

void printCloth(Cloth *cloth) {
    cout << left << setw(9) << cloth->id << setw(23) << cloth->name << setw(15) << cloth->description
         << setw(9) << cloth->color << setw(10) << cloth->quantity << cloth->category << endl;
}

void displayClothList(Cloth *head) {
    if (head == NULL) {
        cout << "The cloth list is empty." << endl;
        return;
    }

    printClothHeader();
    for (Cloth *current = head; current != NULL; current = current->next) {
        printCloth(current);
    }
}

// Sort a copy so the original list order stays as it is
void displaySortedCloth(Cloth *head, bool (*comesBefore)(Cloth *, Cloth *)) {
    Cloth *sortedHead = NULL;
    Cloth *sortedTail = NULL;

    for (Cloth *current = head; current != NULL; current = current->next) {
        insertClothSorted(sortedHead, sortedTail, copyCloth(current), comesBefore);
    }

    displayClothList(sortedHead);
    clearClothList(sortedHead, sortedTail);
}

void browseCloth(Cloth *head) {
    if (head == NULL) {
        cout << "The cloth list is empty." << endl;
        return;
    }

    Cloth *current = head;
    while (true) {
        cout << "\n--- Cloth ---" << endl;
        cout << "Cloth ID    : " << current->id << endl;
        cout << "Cloth Name  : " << current->name << endl;
        cout << "Description : " << current->description << endl;
        cout << "Color       : " << current->color << endl;
        cout << "Quantity    : " << current->quantity << endl;
        cout << "Category    : " << current->category << endl;

        char command = readNavigation();
        if (command == 'q') {
            return;
        } else if (command == 'n') {
            if (current->next == NULL) cout << "This is the last cloth." << endl;
            else current = current->next;
        } else if (command == 'p') {
            if (current->prev == NULL) cout << "This is the first cloth." << endl;
            else current = current->prev;
        }
    }
}

void filterByColor(Cloth *head, string color) {
    string target = toLower(color);
    bool found = false;

    for (Cloth *current = head; current != NULL; current = current->next) {
        if (toLower(current->color) == target) {
            if (!found) {
                printClothHeader();
                found = true;
            }
            printCloth(current);
        }
    }

    if (!found) {
        cout << "No cloth with color \"" << color << "\" was found." << endl;
    }
}

/* ================= Order list ================= */

void insertOrderAtEnd(Order *&head, Order *&tail, Order *newNode) {
    if (tail == NULL) {
        head = tail = newNode;
        return;
    }

    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
}

void clearOrderList(Order *&head, Order *&tail) {
    while (head != NULL) {
        Order *temp = head;
        head = head->next;
        delete temp;
    }
    tail = NULL;
}

void printOrderHeader() {
    cout << left << setw(10) << "Order No" << setw(18) << "Customer" << setw(10) << "Cloth ID"
         << setw(23) << "Cloth Name" << "Quantity" << endl;
    cout << string(69, '-') << endl;
}

void printOrder(Order *order) {
    cout << left << setw(10) << order->orderNo << setw(18) << order->customer << setw(10) << order->clothId
         << setw(23) << order->clothName << order->quantity << endl;
}

void displayOrders(Order *head) {
    if (head == NULL) {
        cout << "There are no customer orders yet." << endl;
        return;
    }

    printOrderHeader();
    for (Order *current = head; current != NULL; current = current->next) {
        printOrder(current);
    }
}

void browseOrders(Order *head) {
    if (head == NULL) {
        cout << "There are no customer orders yet." << endl;
        return;
    }

    Order *current = head;
    while (true) {
        cout << "\n--- Order ---" << endl;
        cout << "Order No   : " << current->orderNo << endl;
        cout << "Customer   : " << current->customer << endl;
        cout << "Cloth ID   : " << current->clothId << endl;
        cout << "Cloth Name : " << current->clothName << endl;
        cout << "Quantity   : " << current->quantity << endl;

        char command = readNavigation();
        if (command == 'q') {
            return;
        } else if (command == 'n') {
            if (current->next == NULL) cout << "This is the last order." << endl;
            else current = current->next;
        } else if (command == 'p') {
            if (current->prev == NULL) cout << "This is the first order." << endl;
            else current = current->prev;
        }
    }
}

/* ================= Helpers ================= */

string toLower(string text) {
    for (size_t i = 0; i < text.length(); i++) {
        text[i] = (char)tolower((unsigned char)text[i]);
    }
    return text;
}

string toUpper(string text) {
    for (size_t i = 0; i < text.length(); i++) {
        text[i] = (char)toupper((unsigned char)text[i]);
    }
    return text;
}

int readInt(string prompt) {
    int value;
    cout << prompt;
    while (!(cin >> value)) {
        if (cin.eof()) exit(0);   // input closed, nothing more to read
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a number: ";
    }
    return value;
}

// Skips the newline left behind by cin >> and reads a full line
string readLine(string prompt) {
    string text;
    cout << prompt;
    cin >> ws;
    if (!getline(cin, text)) exit(0);
    return text;
}

// Returns 'p', 'n' or 'q'
char readNavigation() {
    while (true) {
        string command = toLower(readLine("[P] Previous  [N] Next  [Q] Back to menu: "));
        if (command == "p" || command == "n" || command == "q") {
            return command[0];
        }
        cout << "Invalid option." << endl;
    }
}
