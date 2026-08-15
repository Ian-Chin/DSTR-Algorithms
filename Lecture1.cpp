#include <iostream>
using namespace std;
 
double inches(int feet, int inch);
int main() {
	int feet, inch;
	cout << "Enter feet and inch: ";
	cin >> feet >> inch;
	cout << "Total inches is : " << inches(feet, inch) << endl;
}
double inches(int feet, int inch) {
	return (feet * 12 + inch) * 2.54;
}