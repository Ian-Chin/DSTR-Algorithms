// Lab 1 - Part C - Question 6
// Determine a student's grade from quiz, mid-term and final scores

#include <iostream>
using namespace std;

int main()
{
    double quiz, midTerm, final, average;
    char grade;

    cout << "Enter 3 scores (quiz, mid-term, and final) vales separated by space:";
    cin >> quiz >> midTerm >> final;

    if (cin.fail())
    {
        cout << "Invalid input!" << endl;
        return 1;
    }

    if (quiz < 0 || quiz > 100 || midTerm < 0 || midTerm > 100 || final < 0 || final > 100)
    {
        cout << "Invalid score! Each score must be between 0 and 100." << endl;
        return 1;
    }

    average = (quiz + midTerm + final) / 3;

    if (average >= 90)
        grade = 'A';
    else if (average >= 70)
        grade = 'B';
    else if (average >= 50)
        grade = 'C';
    else
        grade = 'F';

    cout << "Grade " << grade << endl;

    return 0;
}
