// Lab 1 - Part C - Question 5
// Print the even numbers between 1 and 50, five numbers per line

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int count = 0;

    for (int i = 1; i <= 50; i++)
    {
        if (i % 2 == 0)
        {
            cout << setw(4) << i;
            count++;
            if (count % 5 == 0)
                cout << endl;
        }
    }

    return 0;
}
