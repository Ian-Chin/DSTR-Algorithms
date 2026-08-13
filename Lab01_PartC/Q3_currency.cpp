// Lab 1 - Part C - Question 3
// Financials: currency exchange (USD <-> RMB)

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double rate, amount, result;
    int option;

    cout << "Enter the exchange rate from dollars to RMB: ";
    cin >> rate;

    if (cin.fail() || rate <= 0)
    {
        cout << "Invalid exchange rate!" << endl;
        return 1;
    }

    cout << "Enter 0 to convert dollars to RMB and 1 vice versa: ";
    cin >> option;

    if (cin.fail())
    {
        cout << "Invalid input!" << endl;
        return 1;
    }

    cout << fixed << setprecision(1);

    if (option == 0)
    {
        cout << "Enter the dollar amount: ";
        cin >> amount;
        result = amount * rate;
        cout << "$" << amount << " is " << result << " yuan" << endl;
    }
    else if (option == 1)
    {
        cout << "Enter the RMB amount: ";
        cin >> amount;
        result = amount / rate;
        cout << amount << " yuan is $" << setprecision(2) << result << endl;
    }
    else
    {
        cout << "Incorrect input" << endl;
    }

    return 0;
}
