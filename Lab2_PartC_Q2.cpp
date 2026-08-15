#include <iostream>
#include <string>
using namespace std;

string ConvertLetterString(string month);
int FindDaysInMonth(string month, int year);
void weatherReport(int days, int &hot, int &rainy, int &cloudy);
void displayReport(int hot, int rainy, int cloudy);

int main()
{
    string month;
    int year;
    int days;
    int hot = 0, rainy = 0, cloudy = 0;

    cout << "Enter Your Month (e.g. August 2019): ";
    cin >> month >> year;

    month = ConvertLetterString(month);
    days = FindDaysInMonth(month, year);

    while (days == 0)
    {
        cout << "Invalid month! Enter Your Month (e.g. August 2019): ";
        cin >> month >> year;
        month = ConvertLetterString(month);
        days = FindDaysInMonth(month, year);
    }

    weatherReport(days, hot, rainy, cloudy);
    displayReport(hot, rainy, cloudy);

    return 0;
}

string ConvertLetterString(string month)
{
    string newMonth = "";

    for (int i = 0; i < month.length(); i++)
    {
        char c = month[i];

        if (i == 0)
        {
            if (c >= 'a' && c <= 'z')
            {
                c = c - 32;
            }
        }
        else
        {
            if (c >= 'A' && c <= 'Z')
            {
                c = c + 32;
            }
        }

        newMonth = newMonth + c;
    }

    return newMonth;
}

int FindDaysInMonth(string month, int year)
{
    int days = 0;

    if (month == "January" || month == "March" || month == "May" ||
        month == "July" || month == "August" || month == "October" ||
        month == "December")
    {
        days = 31;
    }
    else if (month == "April" || month == "June" || month == "September" ||
             month == "November")
    {
        days = 30;
    }
    else if (month == "February")
    {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        {
            days = 29;
        }
        else
        {
            days = 28;
        }
    }

    return days;
}

void weatherReport(int days, int &hot, int &rainy, int &cloudy)
{
    char input;

    for (int i = 1; i <= days; i++)
    {
        cout << "Day " << i << " : Enter \"H\" for Hot, \"R\" for Rainy, \"C\" for Cloudy, (\"E\" to end): ";
        cin >> input;

        if (input >= 'A' && input <= 'Z')
        {
            input = input + 32;
        }

        if (input == 'e')
        {
            break;
        }
        else if (input == 'h')
        {
            hot = hot + 1;
        }
        else if (input == 'r')
        {
            rainy = rainy + 1;
        }
        else if (input == 'c')
        {
            cloudy = cloudy + 1;
        }
        else
        {
            cout << "Invalid input! Please enter again." << endl;
            i = i - 1;
        }
    }
}

void displayReport(int hot, int rainy, int cloudy)
{
    cout << endl;
    cout << "Number of hot days this month: " << hot << endl;
    cout << "Number of rainy days this month: " << rainy << endl;
    cout << "Number of cloud days this month: " << cloudy << endl;

    cout << endl;
    cout << "The analysis star design as below:" << endl;
    cout << "--------------------------------------------------" << endl;

    cout << "Hot    | ";
    for (int i = 1; i <= hot; i++)
    {
        cout << "* ";
    }
    cout << endl;

    cout << "Rainy  | ";
    for (int i = 1; i <= rainy; i++)
    {
        cout << "* ";
    }
    cout << endl;

    cout << "Cloudy | ";
    for (int i = 1; i <= cloudy; i++)
    {
        cout << "* ";
    }
    cout << endl;

    cout << "--------------------------------------------------" << endl;
}
