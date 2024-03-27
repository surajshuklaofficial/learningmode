#include <iostream>
using namespace std;

int power(int base, int exponent) {
    // base case
    if (exponent == 0) return 1;

    // processing
    int result = power(base, exponent / 2);

    // recursive call
    if (exponent % 2 == 0) return result * result;
    else return result * result * base;
}

int main() {
    
    cout << power(2, 9) << endl;
    return 0;
}