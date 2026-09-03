// Lab 4 - Part A, Exercise 2 : cashRegister class for a candy machine
#include <iostream>
using namespace std;

class cashRegister {
private:
    int cashOnHand;

public:
    cashRegister();             // default constructor, initial balance 500
    cashRegister(int amount);   // constructor with parameter
    void acceptAmount(int amount);
    void printBalance();
    int getCurrentBalance();
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

void cashRegister::acceptAmount(int amount) {
    if (amount < 0) {
        cout << "Invalid amount. Nothing accepted." << endl;
        return;
    }
    cashOnHand = cashOnHand + amount;
}

void cashRegister::printBalance() {
    cout << "Current balance in register : " << cashOnHand << endl;
}

int cashRegister::getCurrentBalance() {
    return cashOnHand;
}

int main() {
    cashRegister candyMachine;   // starts with 500

    candyMachine.printBalance();

    int amount;
    cout << "Enter amount from customer : ";
    cin >> amount;
    candyMachine.acceptAmount(amount);

    candyMachine.printBalance();

    return 0;
}
