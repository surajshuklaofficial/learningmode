// a program to find GCD of two numbers using euclidean algorithm
#include <iostream>
using namespace std;

// euclidean algorithm: GCD of 2 numbers is equal to GCD of smaller number and remainder of larger number it is divided by smaller number.
int GCD(int num1, int num2) {
    if ( num1 % num2 == 0) {
        return num2;
    } else {
        GCD ( num2, num1 % num2);
    }
}

int main() {
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    cout << "GCD of given number is " << GCD(num1, num2) << endl;
    return 0;
}