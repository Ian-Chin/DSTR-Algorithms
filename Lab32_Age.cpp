#include <iostream>
using namespace std;

void ageNoReturnNoParameter();
void ageNoReturnWithParameter(int birthYear, int birthMonth, int birthDay, int nowYear, int nowMonth, int nowDay);
int ageWithReturnNoParameter();
int ageWithReturnWithParameter(int birthYear, int birthMonth, int birthDay, int nowYear, int nowMonth, int nowDay);

int main()
{
    int birthYear, birthMonth, birthDay;
    int nowYear, nowMonth, nowDay;
    int age;

    cout << "Enter your birth date (day month year): ";
    cin >> birthDay >> birthMonth >> birthYear;

    cout << "Enter today's date (day month year): ";
    cin >> nowDay >> nowMonth >> nowYear;

    cout << endl;

    cout << "Function without return without parameters" << endl;
    ageNoReturnNoParameter();

    cout << endl;
    cout << "Function without return with parameters" << endl;
    ageNoReturnWithParameter(birthYear, birthMonth, birthDay, nowYear, nowMonth, nowDay);

    cout << endl;
    cout << "Function with return without parameters" << endl;
    age = ageWithReturnNoParameter();
    cout << "Your age = " << age << endl;

    cout << endl;
    cout << "Function with return with parameters" << endl;
    age = ageWithReturnWithParameter(birthYear, birthMonth, birthDay, nowYear, nowMonth, nowDay);
    cout << "Your age = " << age << endl;

    return 0;
}

void ageNoReturnNoParameter()
{
    int birthYear, birthMonth, birthDay;
    int nowYear, nowMonth, nowDay;
    int age;

    cout << "Enter your birth date (day month year): ";
    cin >> birthDay >> birthMonth >> birthYear;

    cout << "Enter today's date (day month year): ";
    cin >> nowDay >> nowMonth >> nowYear;

    age = nowYear - birthYear;

    if (nowMonth < birthMonth)
    {
        age = age - 1;
    }
    else if (nowMonth == birthMonth && nowDay < birthDay)
    {
        age = age - 1;
    }

    cout << "Your age = " << age << endl;
}

void ageNoReturnWithParameter(int birthYear, int birthMonth, int birthDay, int nowYear, int nowMonth, int nowDay)
{
    int age = nowYear - birthYear;

    if (nowMonth < birthMonth)
    {
        age = age - 1;
    }
    else if (nowMonth == birthMonth && nowDay < birthDay)
    {
        age = age - 1;
    }

    cout << "Your age = " << age << endl;
}

int ageWithReturnNoParameter()
{
    int birthYear, birthMonth, birthDay;
    int nowYear, nowMonth, nowDay;
    int age;

    cout << "Enter your birth date (day month year): ";
    cin >> birthDay >> birthMonth >> birthYear;

    cout << "Enter today's date (day month year): ";
    cin >> nowDay >> nowMonth >> nowYear;

    age = nowYear - birthYear;

    if (nowMonth < birthMonth)
    {
        age = age - 1;
    }
    else if (nowMonth == birthMonth && nowDay < birthDay)
    {
        age = age - 1;
    }

    return age;
}

int ageWithReturnWithParameter(int birthYear, int birthMonth, int birthDay, int nowYear, int nowMonth, int nowDay)
{
    int age = nowYear - birthYear;

    if (nowMonth < birthMonth)
    {
        age = age - 1;
    }
    else if (nowMonth == birthMonth && nowDay < birthDay)
    {
        age = age - 1;
    }

    return age;
}
