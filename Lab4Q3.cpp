// Lab 4 - Part A, Exercise 3 : population class (birth rate and death rate)
#include <iostream>
#include <iomanip>
using namespace std;

class population {
private:
    int totalPopulation, numberOfBirths, numberOfDeaths;

public:
    population();
    bool setPopulation(int p);   // rejects figures less than 1
    bool setBirths(int b);       // rejects numbers less than 0
    bool setDeaths(int d);       // rejects numbers less than 0
    int getPopulation();
    int getBirths();
    int getDeaths();
    double getBirthRate();
    double getDeathRate();
};

population::population() {
    totalPopulation = 1;
    numberOfBirths = 0;
    numberOfDeaths = 0;
}

bool population::setPopulation(int p) {
    if (p < 1)
        return false;
    totalPopulation = p;
    return true;
}

bool population::setBirths(int b) {
    if (b < 0)
        return false;
    numberOfBirths = b;
    return true;
}

bool population::setDeaths(int d) {
    if (d < 0)
        return false;
    numberOfDeaths = d;
    return true;
}

int population::getPopulation() {
    return totalPopulation;
}

int population::getBirths() {
    return numberOfBirths;
}

int population::getDeaths() {
    return numberOfDeaths;
}

double population::getBirthRate() {
    return (double)numberOfBirths / totalPopulation;
}

double population::getDeathRate() {
    return (double)numberOfDeaths / totalPopulation;
}

int main() {
    population town;
    int value;
    do {
        cout << "Enter the population : ";
        cin >> value;
        if (!town.setPopulation(value))
            cout << "Population cannot be less than 1. Try again." << endl;
    } while (value < 1);

    // input validation : births cannot be negative
    do {
        cout << "Enter the number of births : ";
        cin >> value;
        if (!town.setBirths(value))
            cout << "Number of births cannot be less than 0. Try again." << endl;
    } while (value < 0);

    // input validation : deaths cannot be negative
    do {
        cout << "Enter the number of deaths : ";
        cin >> value;
        if (!town.setDeaths(value))
            cout << "Number of deaths cannot be less than 0. Try again." << endl;
    } while (value < 0);

    cout << fixed << setprecision(4);
    cout << "\nPopulation : " << town.getPopulation() << endl;
    cout << "Births     : " << town.getBirths() << endl;
    cout << "Deaths     : " << town.getDeaths() << endl;
    cout << "Birth rate : " << town.getBirthRate() << endl;
    cout << "Death rate : " << town.getDeathRate() << endl;

    return 0;
}
