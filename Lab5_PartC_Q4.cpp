// Lab 5 - Part C, Exercise 4 : Driver's License Exam
#include <iostream>
#include <cctype>
using namespace std;

const int QUESTIONS = 20;
const int PASS_MARK = 15;

void gradeExam(const char *correct, const char *student, int size);

int main() {
    char correct[QUESTIONS] = {
        'B', 'D', 'A', 'A', 'C',
        'A', 'B', 'A', 'C', 'D',
        'B', 'C', 'D', 'A', 'D',
        'C', 'C', 'B', 'D', 'A'
    };
    char student[QUESTIONS];

    cout << "Enter the student's answers for the " << QUESTIONS << " questions." << endl;
    for (int i = 0; i < QUESTIONS; i++) {
        cout << "Question " << (i + 1) << " : ";
        cin >> student[i];
        student[i] = toupper(student[i]);

        // Input validation: only accept the letters A, B, C or D
        while (student[i] != 'A' && student[i] != 'B' &&
               student[i] != 'C' && student[i] != 'D') {
            cout << "Only A, B, C or D is accepted. Re-enter question "
                 << (i + 1) << " : ";
            cin >> student[i];
            student[i] = toupper(student[i]);
        }
    }

    gradeExam(correct, student, QUESTIONS);

    return 0;
}

void gradeExam(const char *correct, const char *student, int size) {
    int right = 0;

    for (int i = 0; i < size; i++) {
        if (*(student + i) == *(correct + i)) {
            right++;
        }
    }

    int wrong = size - right;

    cout << "\nCorrect answers   : " << right << endl;
    cout << "Incorrect answers : " << wrong << endl;

    cout << "Questions missed  : ";
    if (wrong == 0) {
        cout << "none";
    } else {
        for (int i = 0; i < size; i++) {
            if (*(student + i) != *(correct + i)) {
                cout << (i + 1) << " ";
            }
        }
    }
    cout << endl;

    if (right >= PASS_MARK) {
        cout << "The student PASSED the exam." << endl;
    } else {
        cout << "The student FAILED the exam." << endl;
    }
}
