// Lab 1 - Part C - Question 4
// Print a diamond pattern using loops

#include <iostream>
using namespace std;

int main()
{
    int rows;

    do
    {
        cout << "Enter number of rows (for diamond (triangle) dimension) : ";
        cin >> rows;
        if (cin.fail() || rows < 1)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Please enter a positive number." << endl;
            rows = 0;
        }
    } while (rows < 1);

    for (int i = 1; i <= rows; i++)
    {
        for (int space = 1; space <= rows - i; space++)
            cout << " ";
        for (int star = 1; star <= 2 * i - 1; star++)
            cout << "*";
        cout << endl;
    }

    for (int i = rows - 1; i >= 1; i--)
    {
        for (int space = 1; space <= rows - i; space++)
            cout << " ";
        for (int star = 1; star <= 2 * i - 1; star++)
            cout << "*";
        cout << endl;
    }

    return 0;
}
