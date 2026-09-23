// Lab 6 - Part A, Exercise 1 : Use a pointer to access structure members
#include <iostream>
using namespace std;

struct Point {
    int x, y;
};

int main() {
    // p1 is a pointer to a new Point structure
    Point *p1 = new Point;

    // To access the new structure members using pointer
    p1->x = 3; // insert value
    p1->y = 4;

    cout << p1->x << " " << p1->y << endl; // to display

    delete p1;

    return 0;
}
