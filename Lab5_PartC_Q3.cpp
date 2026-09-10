// Lab 5 - Part C, Question 3 : test scores in a dynamically allocated array
#include <iostream>
#include <iomanip>
using namespace std;

double calcAverage(const double *scores, int size);
double findLowest(const double *scores, int size);

int main() {
    int subjects;

    cout << "Enter the total number of subjects : ";
    cin >> subjects;
    while (subjects <= 0) {
        cout << "Do not accept a negative number. Re-enter : ";
        cin >> subjects;
    }

    // dynamically allocated array of test scores
    double *scores = new double[subjects];

    for (int i = 0; i < subjects; i++) {
        cout << "Enter the score for subject " << (i + 1) << " : ";
        cin >> *(scores + i);
        while (*(scores + i) < 0) {
            cout << "Do not accept a negative number. Re-enter : ";
            cin >> *(scores + i);
        }
    }

    cout << fixed << setprecision(2);
    cout << "\nAverage score = " << calcAverage(scores, subjects) << endl;
    cout << "Lowest score  = " << findLowest(scores, subjects) << endl;

    delete[] scores;
    return 0;
}

double calcAverage(const double *scores, int size) {
    double total = 0;
    for (int i = 0; i < size; i++) {
        total += *(scores + i);
    }
    return total / size;
}

double findLowest(const double *scores, int size) {
    double lowest = *scores;
    for (int i = 1; i < size; i++) {
        if (*(scores + i) < lowest) {
            lowest = *(scores + i);
        }
    }
    return lowest;
}
