#include <iostream>
#include <iomanip>
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
    cout << "============================================================" << endl;
    cout << "| Student Details as below:                                |" << endl;
    cout << "============================================================" << endl;
    cout << "|" <<left <<setw(25) << "Student Name:" << right << setw(33)<< name << "|" << endl;
    cout << "|" <<left <<setw(25) << "Student Age:" << right << setw(33)<< age << "|" << endl;
    cout << "|" <<left <<setw(25) << "Student Gender:" << right << setw(33)<< gender << "|" << endl;
    cout << "|" <<left <<setw(25) << "Student Home Address:" << right << setw(33)<< address << "|" << endl;
    cout << "|" <<left <<setw(25) << "E-wallet Amount:RM " << right << setw(33)<< ewallet << "|" << endl;
    cout << "============================================================" << endl;

    return 0;
}