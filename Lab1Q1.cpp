#include <iostream>
using namespace std;

int main()
{
    string name, gender, address;
    int age;
    float ewallet;


    cout << "Enter Student Name: ";
    getline(cin, name);

    cout << "Enter Student Gender: ";
    getline(cin, gender);

    cout << "Enter Student Age: ";
    cin >> age;

    cin.ignore();

    cout << "Enter Student Home Address: ";
    getline(cin, address);

    cout << "Enter E-wallet Amount (RM): ";
    cin >> ewallet;
    
    cout << endl;
    cout << "Student Name          :" << name << endl;
    cout << "Student Gender        :" << gender << endl;
    cout << "Student Age           :" << age << endl;
    cout << "Student Home Address  :" << address << endl;
    cout << "E-wallet Amount       :RM " << ewallet << endl;

    cout << endl;
    cout << "Student details as below:" << endl;
    cout << "==================================================================================" << endl;
    cout << "| Name               | Age | Gender | Address        | E-wallet Amount |" << endl;
    cout << "==================================================================================" << endl;
    cout << "| " << name
         << " | " << age
         << " | " << gender
         << " | " << address
         << " | RM" << ewallet
         << " |" << endl;
    cout << "==================================================================================" << endl;

    return 0;
}