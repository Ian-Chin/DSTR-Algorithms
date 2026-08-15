#include <iostream>
using namespace std;

void averageNoReturnNoParameter();
void averageNoReturnWithParameter(int num1, int num2, int num3);
double averageWithReturnNoParameter();
double averageWithReturnWithParameter(int num1, int num2, int num3);

int main()
{
    int num1, num2, num3;
    double average;

    cout << "Enter three integers: ";
    cin >> num1 >> num2 >> num3;

    cout << endl;

    cout << "Function without return without parameters" << endl;
    averageNoReturnNoParameter();

    cout << endl;
    cout << "Function without return with parameters" << endl;
    averageNoReturnWithParameter(num1, num2, num3);

    cout << endl;
    cout << "Function with return without parameters" << endl;
    average = averageWithReturnNoParameter();
    cout << "Average = " << average << endl;

    cout << endl;
    cout << "Function with return with parameters" << endl;
    average = averageWithReturnWithParameter(num1, num2, num3);
    cout << "Average = " << average << endl;

    return 0;
}

void averageNoReturnNoParameter()
{
    int num1, num2, num3;
    double average;

    cout << "Enter three integers: ";
    cin >> num1 >> num2 >> num3;

    average = (num1 + num2 + num3) / 3.0;

    cout << "Average = " << average << endl;
}

void averageNoReturnWithParameter(int num1, int num2, int num3)
{
    double average = (num1 + num2 + num3) / 3.0;

    cout << "Average = " << average << endl;
}

double averageWithReturnNoParameter()
{
    int num1, num2, num3;
    double average;

    cout << "Enter three integers: ";
    cin >> num1 >> num2 >> num3;

    average = (num1 + num2 + num3) / 3.0;

    return average;
}

double averageWithReturnWithParameter(int num1, int num2, int num3)
{
    double average = (num1 + num2 + num3) / 3.0;

    return average;
}
