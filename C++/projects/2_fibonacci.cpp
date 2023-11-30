// a program to print first N numbers of fibonacci series

#include <iostream>
using namespace std;

// iterative approach
void fibonacci_generator_via_iteration(int num) {
    int current_num, prev_num = 1, prev_prev_num = 1;
    for (int i = 0; i < num; i++) {
        current_num = prev_num + prev_prev_num;
        prev_prev_num = prev_num;
        prev_num = current_num;

        cout << current_num << " ";
    }
    cout << endl;
}

// recursive approach
void fibonacci_generator_via_recursion(int num, int prev_current_num, int prev_num) {
    cout << prev_current_num  + prev_num << " ";
    if (num > 1) { fibonacci_generator_via_recursion( num - 1, prev_current_num + prev_num, prev_current_num); } 
}

int main() {
    
    int num;
    cout << "Enter a number: " ;
    cin >> num;

    cout << "recursion will start from 2 :-" << endl;
    fibonacci_generator_via_iteration(num);
    fibonacci_generator_via_recursion(num, 1, 1);
    return 0;
}