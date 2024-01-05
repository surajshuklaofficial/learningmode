#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 1) return 1;

    return n * factorial(n - 1);
}

// // tail recursion
// int printCount(int n) {
//     if (n == 1) return 1; // base case

//     cout << n << " "; // processing

//     return printCount(n - 1); // recursive condition
// }

// head recursion
void printCount(int n) {
    if (n == 0) return ; // base case
    cout << n << " "; // processing
    printCount(n - 1); // recursive condition
}

int main() {
    
    cout << factorial(6) << endl;
    printCount(6);
    return 0;
}