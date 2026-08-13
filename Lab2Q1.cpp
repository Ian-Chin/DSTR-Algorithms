#include <iostream>
using namespace std;
void Average(); //prototype
// void Average(int, int, int); //prototype(declaration)
int main() {
    Average();
}

//without return, without parameter
void Average() {
    int num1, num2, num3;

    cout << "Enter three integers: ";
    cin >> num1 >> num2 >> num3;
    cout << "Average of " << num1 << ", " << num2 << ", and " << num3 << " is " << (num1 + num2 + num3) / 3 << endl;
}

//------------------------------------------------------------------------------------------------------------------------
// void Average(int num1, int num2, int num3) {

//     cout << "Enter three integers: ";
//     cin >> num1 >> num2 >> num3;
//     cout << "Average of " << num1 << ", " << num2 << ", and " << num3 << " is " << double(num1 + num2 + num3) / 3 << endl;
// }


//-------------------------------------------------------------------------------------------------------------------------
// int main(int num1, int num2, int num3) {
//    cout << "Enter three integers: ";
//    cin >> num1 >> num2 >> num3;
//    Average(int num1, int num2, int num3);
// }


// void Average(int num1, int num2, int num3) {
//     cout << "Average of " << num1 << ", " << num2 << ", and " << num3 << " is " << double(num1 + num2 + num3) / 3 << endl;
// }


//-------------------------------------------------------------------------------------------------------------------------
// void Average(int, int, int); //prototype


// void main() {
//     int num1, int num2, int num3;

//     cout << "Enter three integers: ";
//     cin >> num1 >> num2 >> num3;
//     cout << "Average of " << num1 << ", " << num2 << ", and " << num3 << " is " << Average(num1 + num2 + num3) / 3 << endl;
// }


//-------------------------------------------------------------------------------------------------------------------------
//with return , with parameter
// double Average(int une, int rendu, int moonu) {
//     return double(une +rendu + moonu) / 3;
// }


//-------------------------------------------------------------------------------------------------------------------------
// with return, without parameter
// double Average() {
//     int num1, num2, num3;

//     cout << "Enter three integers: ";
//     cin >> num1 >> num2 >> num3;
//     return double(num1 + num2 + num3) / 3;
// }


//-------------------------------------------------------------------------------------------------------------------------
//int main(){
//    double average = Average();
//    cout << "Average of three integers is " << Average() << endl;
//}

// double Average() {
//     int num1, num2, num3;

//     cout << "Enter three integers: ";
//     cin >> num1 >> num2 >> num3;
//     return double(num1 + num2 + num3) / 3;
// }