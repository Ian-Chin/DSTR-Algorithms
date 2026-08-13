// Lab 1 - Part C - Question 7
// Compare the areas of two rectangles

#include <iostream>
using namespace std;

int main()
{
    double widthA, heightA, widthB, heightB;
    double areaA, areaB;

    cout << "Rectangle A:" << endl;
    cout << "Width = ";
    cin >> widthA;
    cout << "Height = ";
    cin >> heightA;

    cout << endl << "Rectangle B:" << endl;
    cout << "Width = ";
    cin >> widthB;
    cout << "Height = ";
    cin >> heightB;

    if (cin.fail() || widthA <= 0 || heightA <= 0 || widthB <= 0 || heightB <= 0)
    {
        cout << "Invalid input! Width and height must be positive numbers." << endl;
        return 1;
    }

    areaA = widthA * heightA;
    areaB = widthB * heightB;

    cout << endl;
    if (areaA > areaB)
        cout << "Area in rectangle A is bigger rectangle B." << endl;
    else if (areaB > areaA)
        cout << "Area in rectangle B is bigger rectangle A." << endl;
    else
        cout << "Area in rectangle A and rectangle B are the same." << endl;

    return 0;
}
