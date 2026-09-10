// Lab 5 - Part B, Exercise 1 : input and print array elements using a pointer
#include <iostream>
using namespace std;

int main() {
    int size;

    cout << "Enter the size of array: ";
    cin >> size;

    while (size <= 0) {
        cout << "Size must be a positive number. Enter the size of array: ";
        cin >> size;
    }

    // dynamically allocated array
    int *arr = new int[size];

    cout << "\nNow, build an array with " << size << " columns." << endl;
    cout << "Enter elements in the developed array:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> *(arr + i);
    }

    cout << "The array elements = ";
    for (int i = 0; i < size; i++) {
        cout << *(arr + i) << " , ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}
