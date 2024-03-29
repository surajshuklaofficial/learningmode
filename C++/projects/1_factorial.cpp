// a program print factorial of a given input using both iterative and recursive approach
#include <iostream>
using namespace std;

// iterative approach
long long factorial_via_iteration(int num) {
    long long factorial = 1;
    while (num > 0) { factorial *= num--; }
    return factorial;
}

// recursive approach
long long factorial_via_recursion(int num) {
    if (num > 1) { return num * factorial_via_recursion(--num);}  // decrement operators not working properly(reason not known)
    else { return 1; }
}

int main() {
    int num;
    cout << "Enter number to find factorial: ";
    cin >> num;

    cout << "Factorial of " << num << " is(via iteration): " << factorial_via_iteration(num) << endl;
    cout << "Factorial of " << num << " is(via recursion): " << factorial_via_recursion(num) << endl;
    return 0;
}