// Lab 5 - Part C, Question 2 : rectangle area
#include <iostream>
#include <iomanip>
using namespace std;

double getLength();
double getWidth();
double getArea(double length, double width);
void displayData(double &length, double &width, double &area);

int main() {
    double length = getLength();
    double width = getWidth();
    double area = getArea(length, width);

    displayData(length, width, area);

    return 0;
}

double getLength() {
    double length;
    cout << "Enter the rectangle's length : ";
    cin >> length;
    while (length <= 0) {
        cout << "Length must be greater than 0. Re-enter : ";
        cin >> length;
    }
    return length;
}

double getWidth() {
    double width;
    cout << "Enter the rectangle's width  : ";
    cin >> width;
    while (width <= 0) {
        cout << "Width must be greater than 0. Re-enter : ";
        cin >> width;
    }
    return width;
}

double getArea(double length, double width) {
    return length * width;
}

void displayData(double &length, double &width, double &area) {
    cout << fixed << setprecision(2);
    cout << "\nThe rectangle's length is " << length << endl;
    cout << "The rectangle's width  is " << width << endl;
    cout << "The rectangle's area   is " << area << endl;
}
