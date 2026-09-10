// Lab 5 - Part A, Exercise 2 : create, initialize and use a pointer variable
#include <iostream>
using namespace std;

int main() {
    int num = 10;
    int *ptr;

    /* Stores the address of num to pointer type */
    ptr = &num;

    cout << "Address of num = " << &num << endl;
    cout << "Value of num = " << num << endl << endl;

    cout << "Address of ptr = " << &ptr << endl;
    cout << "Value of ptr = " << ptr << endl;
    cout << "Value pointed by ptr = " << *ptr << endl;

    return 0;
}
