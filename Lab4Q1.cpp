// Lab 4 - Part A, Exercise 1 : BankAccount class
#include <iostream>
#include <iomanip>
using namespace std;

class BankAccount {
private:
    double balance;
    double interest_rate;

public:
    BankAccount();
    void set(int dollars, int cents);   // account balance is set to $dollars.cents
    void update();                      // one year of simple interest added to balance
    double get_balance();               // return current account balance
    double get_rate();                  // return current interest rate
    void set_rate(int rate);            // rate is set to interest rate
};

BankAccount::BankAccount() {
    balance = 0.0;
    interest_rate = 0.0;
}

void BankAccount::set(int dollars, int cents) {
    if (dollars < 0 || cents < 0 || cents > 99) {
        cout << "Invalid amount. Balance not changed." << endl;
        return;
    }
    balance = dollars + cents / 100.0;
}

void BankAccount::update() {
    balance = balance + balance * (interest_rate / 100.0);
}

double BankAccount::get_balance() {
    return balance;
}

double BankAccount::get_rate() {
    return interest_rate;
}

void BankAccount::set_rate(int rate) {
    if (rate < 0) {
        cout << "Invalid rate. Rate not changed." << endl;
        return;
    }
    interest_rate = rate;
}

int main() {
    BankAccount account;

    int dollars, cents, rate;

    cout << "Enter dollars : ";
    cin >> dollars;
    cout << "Enter cents   : ";
    cin >> cents;
    account.set(dollars, cents);

    cout << "Enter interest rate (%) : ";
    cin >> rate;
    account.set_rate(rate);

    cout << fixed << setprecision(2);
    cout << "\nBefore update" << endl;
    cout << "Balance       : $" << account.get_balance() << endl;
    cout << "Interest rate : " << account.get_rate() << "%" << endl;

    account.update();

    cout << "\nAfter one year of simple interest" << endl;
    cout << "Balance       : $" << account.get_balance() << endl;
    cout << "Interest rate : " << account.get_rate() << "%" << endl;

    return 0;
}
