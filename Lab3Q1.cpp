#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int STUDENTS = 5;
const int SUBJECTS = 3;

void ChangeQuizScoreToPercentage(int marks[STUDENTS][SUBJECTS], double quizPercent[STUDENTS]);
void ChangeMidTermScoreToPercentage(int marks[STUDENTS][SUBJECTS], double midPercent[STUDENTS]);
void ChangeFinalScoreToPercentage(int marks[STUDENTS][SUBJECTS], double finalPercent[STUDENTS]);
char Check_Grade(double total);

int main() {
    string names[STUDENTS] = {
        "Tan Chi Yong",
        "Lim Jie Jing",
        "Jason Leong",
        "Monday Johnny",
        "Holiday James"
    };

    string tp[STUDENTS] = {
        "TP001234",
        "TP001235",
        "TP001236",
        "TP001237",
        "TP001238"
    };

    int marks[STUDENTS][SUBJECTS] = {
        {70, 88, 45},
        {88, 66, 70},
        {45, 55, 66},
        {22, 66, 34},
        {55, 88, 94}
    };

    double quizPercent[STUDENTS];
    double midPercent[STUDENTS];
    double finalPercent[STUDENTS];
    double totalScore[STUDENTS];
    char grade[STUDENTS];

    ChangeQuizScoreToPercentage(marks, quizPercent);
    ChangeMidTermScoreToPercentage(marks, midPercent);
    ChangeFinalScoreToPercentage(marks, finalPercent);

    for (int i = 0; i < STUDENTS; i++) {
        totalScore[i] = quizPercent[i] + midPercent[i] + finalPercent[i];
        grade[i] = Check_Grade(totalScore[i]);
    }

    cout << fixed << setprecision(2);
    cout << left << setw(16) << "Student Name"
         << setw(12) << "Student TP"
         << setw(10) << "Quiz(20)"
         << setw(14) << "Mid term(50)"
         << setw(16) << "Final Exam(30)"
         << setw(12) << "Total(100)"
         << setw(6)  << "Grade" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < STUDENTS; i++) {
        cout << left << setw(16) << names[i]
             << setw(12) << tp[i]
             << setw(10) << quizPercent[i]
             << setw(14) << midPercent[i]
             << setw(16) << finalPercent[i]
             << setw(12) << totalScore[i]
             << setw(6)  << grade[i] << endl;
    }
    cout << endl;

    int highest = 0;
    int lowest = 0;
    for (int i = 1; i < STUDENTS; i++) {
        if (totalScore[i] > totalScore[highest])
            highest = i;
        if (totalScore[i] < totalScore[lowest])
            lowest = i;
    }

    int countAB = 0;
    for (int i = 0; i < STUDENTS; i++) {
        if (grade[i] == 'A' || grade[i] == 'B')
            countAB++;
    }

    cout << "Highest scoring student : " << names[highest]
         << " (" << totalScore[highest] << ")" << endl;
    cout << "Lowest scoring student  : " << names[lowest]
         << " (" << totalScore[lowest] << ")" << endl;
    cout << "Total students with grade A or B : " << countAB << endl;

    return 0;
}

void ChangeQuizScoreToPercentage(int marks[STUDENTS][SUBJECTS], double quizPercent[STUDENTS]) {
    for (int i = 0; i < STUDENTS; i++) {
        quizPercent[i] = marks[i][0] / 100.0 * 20;
    }
}

void ChangeMidTermScoreToPercentage(int marks[STUDENTS][SUBJECTS], double midPercent[STUDENTS]) {
    for (int i = 0; i < STUDENTS; i++) {
        midPercent[i] = marks[i][1] / 100.0 * 50;
    }
}

void ChangeFinalScoreToPercentage(int marks[STUDENTS][SUBJECTS], double finalPercent[STUDENTS]) {
    for (int i = 0; i < STUDENTS; i++) {
        finalPercent[i] = marks[i][2] / 100.0 * 30;
    }
}

char Check_Grade(double total) {
    if (total >= 90)
        return 'A';
    else if (total >= 70)
        return 'B';
    else if (total >= 50)
        return 'C';
    else
        return 'F';
}
