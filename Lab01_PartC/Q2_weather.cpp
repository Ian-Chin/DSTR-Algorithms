// Lab 1 - Part C - Question 2
// Weather forecast tracker for one month (no array allowed)

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int monthNumber(string name)
{
    for (unsigned int i = 0; i < name.length(); i++)
        name[i] = tolower(name[i]);

    if (name == "january")   return 1;
    if (name == "february")  return 2;
    if (name == "march")     return 3;
    if (name == "april")     return 4;
    if (name == "may")       return 5;
    if (name == "june")      return 6;
    if (name == "july")      return 7;
    if (name == "august")    return 8;
    if (name == "september") return 9;
    if (name == "october")   return 10;
    if (name == "november")  return 11;
    if (name == "december")  return 12;
    return 0;
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

int main()
{
    string monthText;
    int year = 0;
    int month = 0;

    do
    {
        cout << "Enter Your Month (e.g. August 2019): ";
        cin >> monthText >> year;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input!" << endl;
            month = 0;
            continue;
        }

        month = monthNumber(monthText);
        if (month == 0 || year < 1)
            cout << "Invalid input!" << endl;

    } while (month == 0 || year < 1);

    int totalDays = daysInMonth(month, year);
    int hot = 0, rainy = 0, cloudy = 0;
    char forecast;

    for (int day = 1; day <= totalDays; day++)
    {
        cout << "Day " << day
             << " : Enter \"H\" for Hot, \"R\" for Rainy, \"C\" for Cloudy, (\"E\" to end): ";
        cin >> forecast;
        forecast = toupper(forecast);

        if (forecast == 'E')
            break;
        else if (forecast == 'H')
            hot++;
        else if (forecast == 'R')
            rainy++;
        else if (forecast == 'C')
            cloudy++;
        else
        {
            cout << "Invalid input! Please enter H, R, C or E." << endl;
            day--;
        }
    }

    cout << "Number of hot days this month: " << hot << endl;
    cout << "Number of rainy days this month: " << rainy << endl;
    cout << "Number of cloud days this month: " << cloudy << endl;

    return 0;
}
