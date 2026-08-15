#include <iostream>
#include <string>
using namespace std;

bool checkInput(string time);
int processElapsedTime(string time);

int main()
{
    string time;

    cout << "Please enter your elapsed time (in HH:MM:SS format) = ";
    cin >> time;

    while (checkInput(time) == false)
    {
        cout << "Invalid time! Please enter again (in HH:MM:SS format) = ";
        cin >> time;
    }

    int seconds = processElapsedTime(time);

    cout << "Elapsed time in seconds = " << seconds << " seconds" << endl;

    return 0;
}

bool checkInput(string time)
{
    if (time.length() != 8)
    {
        return false;
    }

    if (time[2] != ':' || time[5] != ':')
    {
        return false;
    }

    for (int i = 0; i < 8; i++)
    {
        if (i != 2 && i != 5)
        {
            if (time[i] < '0' || time[i] > '9')
            {
                return false;
            }
        }
    }

    int hour = (time[0] - '0') * 10 + (time[1] - '0');
    int minute = (time[3] - '0') * 10 + (time[4] - '0');
    int second = (time[6] - '0') * 10 + (time[7] - '0');

    if (hour > 23 || minute > 59 || second > 59)
    {
        return false;
    }

    return true;
}

int processElapsedTime(string time)
{
    int hour = (time[0] - '0') * 10 + (time[1] - '0');
    int minute = (time[3] - '0') * 10 + (time[4] - '0');
    int second = (time[6] - '0') * 10 + (time[7] - '0');

    int total = hour * 3600 + minute * 60 + second;

    return total;
}
