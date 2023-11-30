#include <iostream>
using namespace std;

// call by reference using pointers
void swapByPointer( int *x, int *y ) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// call by reference using reference variable
void swapByReferenceVar( int &x, int &y ) {
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 1, b = 4;

    cout << "value of a: " << a << "; value of b: " << b << "; before swap" << endl;

    swapByPointer( &a, &b );
    cout << "value of a: " << a << "; value of b: " << b << "; after swap by pointers" << endl;

    swapByReferenceVar( a, b );
    cout << "value of a: " << a << "; value of b: " << b << "; after swap by reference var" << endl;
    
    return 0;
}