// Lab 5 - Part A, Test yourself 1 : add two numbers using pointers
#include <iostream>
using namespace std;

int main() {
    // variable sum - store the answer from the pointers' summation operation.
    int num1, num2, sum;

    // use these pointers to do the summation operation.
    int *ptr1, *ptr2;

    cout << "Enter any two numbers : ";
    cin >> num1 >> num2;

    cout << "Address of num1 = " << &num1 << " ; Value of num1 = " << num1 << endl;
    cout << "Address of num2 = " << &num2 << " ; Value of num2 = " << num2 << endl << endl;

    // point the pointers at the two numbers
    ptr1 = &num1;
    ptr2 = &num2;

    cout << "Address of ptr1 = " << ptr1 << " ; Value of ptr1 = " << *ptr1 << endl;
    cout << "Address of ptr2 = " << ptr2 << " ; Value of ptr2 = " << *ptr2 << endl << endl;

    // summation done through the pointers
    sum = *ptr1 + *ptr2;

    cout << "Sum = " << sum << endl;

    return 0;
}
