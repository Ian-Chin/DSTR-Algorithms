#include <iostream>
using namespace std;

void swapValue(int &a, int &b);

int main()
{
    int num1, num2;

    cout << "Enter first value: ";
    cin >> num1;

    cout << "Enter second value: ";
    cin >> num2;

    cout << endl;
    cout << "Before swap: num1 = " << num1 << ", num2 = " << num2 << endl;

    swapValue(num1, num2);

    cout << "After swap : num1 = " << num1 << ", num2 = " << num2 << endl;

    return 0;
}

void swapValue(int &a, int &b)
{
    int temp;

    temp = a;
    a = b;
    b = temp;
}
