// Lab 5 - Part C, Question 1 : convert inches to centimeters through a pointer
// Note: main() is declared int (void main is not valid C++); the body is unchanged.
#include <iostream>
#include <iomanip>
using namespace std;

// Write your function prototype here
void convert(double *val);

int main() {
    double measurement;

    cout << "Enter a length in inches, and I will convert\n";
    cout << "it to centimeters: ";
    cin >> measurement;
    convert(&measurement);
    cout << fixed << setprecision(4);
    cout << "Value in centimeters: " << measurement << endl;

    return 0;
}

// Write your function convert here
void convert(double *val) {
    *val = *val * 2.54;   // 1 inch = 2.54 cm
}
