// a program to check whether a input number is prime or not
#include <iostream>
#include <cmath>
using namespace std;

// Concept: If a number is not prime, it must have a divisor smaller or equal to its square root.
int check_prime_number(int num) {
    int sqrt_num = sqrt(num);
    for ( int i = 2; i <= sqrt_num; i++) {
        if ( num % i == 0) {
            return 0;
        } else {}
    }

    return 1;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (check_prime_number(num) == 1) { cout << "It is a prime number.";}
    else if (check_prime_number(num) == 0) { cout << "It is not a prime number.";};
    return 0;
}