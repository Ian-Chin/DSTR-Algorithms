// Lab 1 - Part C - Question 1
// Calendar application

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year)
{
    switch (month)
    {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        return isLeapYear(year) ? 29 : 28;
    }
    return 0;
}

string monthName(int month)
{
    switch (month)
    {
    case 1:  return "January";
    case 2:  return "February";
    case 3:  return "March";
    case 4:  return "April";
    case 5:  return "May";
    case 6:  return "June";
    case 7:  return "July";
    case 8:  return "August";
    case 9:  return "September";
    case 10: return "October";
    case 11: return "November";
    case 12: return "December";
    }
    return "Unknown";
}

int startDayOfMonth(int month, int year)
{
    int m = month;
    int y = year;
    if (m < 3)
    {
        m += 12;
        y -= 1;
    }
    int k = y % 100;
    int j = y / 100;
    int h = (1 + (13 * (m + 1)) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;
    return (h + 6) % 7;
}

void printCalendar(int month, int year)
{
    cout << endl;
    cout << setw(45) << right << "Calendar Title : "
         << monthName(month) << " - " << year << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << setw(11) << "Sunday" << setw(11) << "Monday" << setw(11) << "Tuesday"
         << setw(11) << "Wednesday" << setw(11) << "Thursday" << setw(11) << "Friday"
         << setw(11) << "Saturday" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;

    int start = startDayOfMonth(month, year);
    int total = daysInMonth(month, year);

    for (int i = 0; i < start; i++)
        cout << setw(11) << " ";

    for (int day = 1; day <= total; day++)
    {
        cout << setw(11) << day;
        if ((start + day) % 7 == 0)
            cout << endl;
    }
    if ((start + total) % 7 != 0)
        cout << endl;

    cout << "-------------------------------------------------------------------------------" << endl;
}

int main()
{
    int year, month, choice;

    do
    {
        do
        {
            cout << "Enter calendar's year: ";
            cin >> year;
            if (cin.fail() || year < 1)
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid year! Please enter a positive year." << endl;
                year = 0;
            }
        } while (year < 1);

        do
        {
            cout << "Enter calendar's month: ";
            cin >> month;
            if (cin.fail() || month < 1 || month > 12)
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid month! Please enter 1 to 12." << endl;
                month = 0;
            }
        } while (month < 1 || month > 12);

        printCalendar(month, year);

        cout << endl << "Do you want to see other month? 1 = Yes, others = No: ";
        cin >> choice;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            choice = 0;
        }
        cout << endl;
    } while (choice == 1);

    cout << "Thank you for using the calendar application." << endl;
    return 0;
}
