#include <iostream>
using namespace std;

int factorial(int x);

int main()
{
    int x;

    cout << "Enter the value of x: ";
    cin >> x;

    while (x < 0)
    {
        cout << "Negative number is not allowed! Enter the value of x: ";
        cin >> x;
    }

    cout << "Factorial of " << x << " = " << factorial(x) << endl;

    return 0;
}

int factorial(int x)
{
    if (x == 0 || x == 1)
    {
        return 1;
    }
    else
    {
        return x * factorial(x - 1);
    }
}
