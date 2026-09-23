// Class Activity 3: C++ structure named Patient
#include <iostream>
#include <string>
using namespace std;

struct Patient {
    string name;
    char gender;
    double height;
    int age;
    double weight;
    Patient *next;
};

int main() {
    Patient p;
    p.name = "John";
    p.gender = 'M';
    p.height = 157.60;
    p.age = 45;
    p.weight = 67.8;
    p.next = NULL;

    cout << "Name   : " << p.name << endl;
    cout << "Gender : " << p.gender << endl;
    cout << "Height : " << p.height << endl;
    cout << "Age    : " << p.age << endl;
    cout << "Weight : " << p.weight << endl;
    cout << "Next   : " << p.next << endl;

    return 0;
}
