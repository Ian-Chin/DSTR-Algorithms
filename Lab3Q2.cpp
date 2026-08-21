#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX = 1000;
const int GROUPS = 5;

void GenerateNumbers(int numbers[], int size);
void DisplayNumbers(int numbers[], int size);
void CountGroups(int numbers[], int size, int counter[GROUPS]);
void DrawGraph(int counter[GROUPS]);
void VerifyGroup(int numbers[], int size, int group);

int main() {
    int numbers[MAX];
    int counter[GROUPS];
    int size;

    srand(time(0));

    cout << "Enter how many random numbers you want to do an analysis? ";
    cin >> size;

    while (size < 1 || size > MAX) {
        cout << "Please enter a number between 1 and " << MAX << ": ";
        cin >> size;
    }

    GenerateNumbers(numbers, size);

    cout << endl << "The random numbers (between 1 - 50) as below:" << endl;
    DisplayNumbers(numbers, size);

    CountGroups(numbers, size, counter);

    cout << endl << "The analysis star design as below:" << endl;
    DrawGraph(counter);

    int group;
    cout << endl << "Which group do you want to verify? (1 = 1-10, 2 = 11-20, "
         << "3 = 21-30, 4 = 31-40, 5 = 41-50, 0 = exit): ";
    cin >> group;

    while (group != 0) {
        if (group >= 1 && group <= GROUPS) {
            VerifyGroup(numbers, size, group);
        } else {
            cout << "Invalid group! Please choose 0 - 5." << endl;
        }
        cout << endl << "Choose another group (0 = exit): ";
        cin >> group;
    }

    cout << "Program ended." << endl;
    return 0;
}

void GenerateNumbers(int numbers[], int size) {
    for (int i = 0; i < size; i++) {
        numbers[i] = rand() % 50 + 1;
    }
}

void DisplayNumbers(int numbers[], int size) {
    for (int i = 0; i < size; i++) {
        cout << left << setw(6) << numbers[i];
        if ((i + 1) % 10 == 0)
            cout << endl;
    }
    if (size % 10 != 0)
        cout << endl;
}

void CountGroups(int numbers[], int size, int counter[GROUPS]) {
    for (int i = 0; i < GROUPS; i++) {
        counter[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        int group = (numbers[i] - 1) / 10;
        counter[group]++;
    }
}

void DrawGraph(int counter[GROUPS]) {
    cout << "-------------------------------------------------------------------" << endl;
    for (int i = 0; i < GROUPS; i++) {
        int low = i * 10 + 1;
        int high = i * 10 + 10;

        cout << right << setw(2) << low << " - " << setw(2) << high << " | ";
        for (int j = 0; j < counter[i]; j++) {
            cout << "* ";
        }
        cout << " (" << counter[i] << ")" << endl;
    }
    cout << "-------------------------------------------------------------------" << endl;
}

void VerifyGroup(int numbers[], int size, int group) {
    int low = (group - 1) * 10 + 1;
    int high = (group - 1) * 10 + 10;
    int count = 0;

    cout << endl << "To verify the graph is correct: (display numbers of "
         << low << " - " << high << ")" << endl;
    cout << "-------------------------------------------------------------------" << endl;

    for (int i = 0; i < size; i++) {
        if (numbers[i] >= low && numbers[i] <= high) {
            cout << left << setw(6) << numbers[i];
            count++;
            if (count % 10 == 0)
                cout << endl;
        }
    }
    if (count % 10 != 0)
        cout << endl;

    cout << "Total numbers in this group: " << count << endl;
}
