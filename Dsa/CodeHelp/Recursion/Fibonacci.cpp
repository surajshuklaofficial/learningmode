#include <iostream>
using namespace std;

int fibonacciNumber(int num) {
    //base case
    if (num == 1 || num == 2) {
        return 1;
    }

    // recursive call
    return fibonacci(num - 1) + fibonacci(num - 2);
}

int main() {
    
    cout << fibonacciNumber(6) << endl;
    return 0;
}