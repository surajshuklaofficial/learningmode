#include <iostream>
using namespace std;

int printFibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    
    return printFibonacci(n - 1) + printFibonacci(n - 2);
}

void sayNum(int n) {
    if (n == 0) return;

    cout << n%10 << " ";
    sayNum(n/10);
}

int main() {

    // cout << printFibonacci(6);
    sayNum(534);
    return 0;
}