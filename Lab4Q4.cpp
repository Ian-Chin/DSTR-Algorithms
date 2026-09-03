// Lab 4 - Part A, Exercise 4 : fruit juice machine
#include <iostream>
using namespace std;

class cashRegister {
private:
    int cashOnHand;

public:
    cashRegister();
    cashRegister(int amount);
    int getCurrentBalance();
    void acceptAmount(int amount);
};

cashRegister::cashRegister() {
    cashOnHand = 500;
}

cashRegister::cashRegister(int amount) {
    if (amount >= 0)
        cashOnHand = amount;
    else
        cashOnHand = 500;
}

int cashRegister::getCurrentBalance() {
    return cashOnHand;
}

void cashRegister::acceptAmount(int amount) {
    cashOnHand = cashOnHand + amount;
}

class dispenserType {
private:
    int numberOfItems;
    int cost;

public:
    dispenserType();
    dispenserType(int noOfItems, int itemCost);
    int getNoOfItems();
    int getCost();
    void makeSale();
};

dispenserType::dispenserType() {
    numberOfItems = 50;
    cost = 50;
}

dispenserType::dispenserType(int noOfItems, int itemCost) {
    if (noOfItems >= 0)
        numberOfItems = noOfItems;
    else
        numberOfItems = 50;

    if (itemCost >= 0)
        cost = itemCost;
    else
        cost = 50;
}

int dispenserType::getNoOfItems() {
    return numberOfItems;
}

int dispenserType::getCost() {
    return cost;
}

void dispenserType::makeSale() {
    numberOfItems = numberOfItems - 1;
}

void showSelection();
void sellProduct(dispenserType &product, cashRegister &counter);

int main() {
    cashRegister counter;

    dispenserType appleJuice(100, 150);
    dispenserType orangeJuice(100, 200);
    dispenserType mangoLassi(100, 250);
    dispenserType fruitPunch(100, 180);

    int choice;

    do {
        showSelection();
        cin >> choice;

        switch (choice) {
        case 1:
            sellProduct(appleJuice, counter);
            break;
        case 2:
            sellProduct(orangeJuice, counter);
            break;
        case 3:
            sellProduct(mangoLassi, counter);
            break;
        case 4:
            sellProduct(fruitPunch, counter);
            break;
        case 9:
            cout << "Thank you for using the juice machine." << endl;
            break;
        default:
            cout << "Invalid selection." << endl;
        }
        cout << endl;
    } while (choice != 9);

    return 0;
}

void showSelection() {
    cout << "*** Welcome to the Fruit Juice Machine ***" << endl;
    cout << "To select an item, enter" << endl;
    cout << "1 for apple juice" << endl;
    cout << "2 for orange juice" << endl;
    cout << "3 for mango lassi" << endl;
    cout << "4 for fruit punch" << endl;
    cout << "9 to exit" << endl;
    cout << "Your selection : ";
}

void sellProduct(dispenserType &product, cashRegister &counter) {
    if (product.getNoOfItems() <= 0) {
        cout << "Sorry, this product is sold out." << endl;
        return;
    }

    cout << "Items available : " << product.getNoOfItems() << endl;
    cout << "Please deposit " << product.getCost() << " cents" << endl;

    int amountPaid;
    cin >> amountPaid;

    // keep asking until the customer has paid enough
    while (amountPaid < product.getCost()) {
        cout << "Please deposit another " << product.getCost() - amountPaid
             << " cents" << endl;
        int extra;
        cin >> extra;
        amountPaid = amountPaid + extra;
    }

    // change is returned, only the price goes into the register
    int change = amountPaid - product.getCost();
    if (change > 0)
        cout << "Your change is " << change << " cents" << endl;

    counter.acceptAmount(product.getCost());
    product.makeSale();

    cout << "Collect your item at the bottom and enjoy." << endl;
    cout << "Cash in register : " << counter.getCurrentBalance() << " cents" << endl;
}
