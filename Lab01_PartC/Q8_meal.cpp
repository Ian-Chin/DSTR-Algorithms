// Lab 1 - Part C - Question 8
// Total cost of a meal inclusive of 6% GST and tipping

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    const double GST_RATE = 0.06;
    double mealCost, tipPercent;
    double gstAmount, costAfterGst, tipAmount, totalCost;

    cout << "Enter the cost of the meal (before GST and tipping): RM ";
    cin >> mealCost;

    if (cin.fail() || mealCost < 0)
    {
        cout << "Invalid meal cost!" << endl;
        return 1;
    }

    cout << "Enter the tip amount (in percentage): ";
    cin >> tipPercent;

    if (cin.fail() || tipPercent < 0)
    {
        cout << "Invalid tip percentage!" << endl;
        return 1;
    }

    gstAmount    = mealCost * GST_RATE;
    costAfterGst = mealCost + gstAmount;
    tipAmount    = costAfterGst * (tipPercent / 100);
    totalCost    = costAfterGst + tipAmount;

    cout << fixed << setprecision(2);
    cout << endl;
    cout << "The total cost of the meal BEFORE GST and tipping : RM " << mealCost << endl;
    cout << "The total cost of the meal AFTER GST              : RM " << costAfterGst << endl;
    cout << "The total cost of the meal AFTER GST and tipping  : RM " << totalCost << endl;

    return 0;
}
