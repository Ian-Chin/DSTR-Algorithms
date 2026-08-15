#include <iostream>
using namespace std;
 
bool elligible(bool earth, int score, bool goodlooking);//prototype
int main() {
	bool earth, goodlooking;
	int score;
	cout << "Are you from any earth countries?  " << endl;
	cout << "1. Yes" << endl;
	cout << "2. No" << endl;
	cin >> earth;
	cout << "Quiz score: ";
	cin >> score;
	cout << "Do you consider yourself goodlooking?  " << endl;
	cout << "1. Yes" << endl;
	cout << "2. No" << endl;
	cin >> goodlooking;
	if (elligible(earth, score, goodlooking)) {
		cout << "You are eligible!" << endl;
	}
	else {
		cout << "You are not eligible." << endl;
	}
}
bool elligible(bool earth, int score, bool goodlooking) {
	if (earth && score >= 50 || goodlooking && score >= 25)
		return true;
	else
		return false;
}