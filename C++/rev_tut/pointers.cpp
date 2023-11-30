#include <iostream>
using namespace std;

int main() {
    
    int a = 56;
    int &b = a; // it will just make one more name for a
    int c = a; // it will other variable with different memory but same data value
    int *p1 = &a;
    int *p2 = &b;
    int *p3 = &c;
    int **p4 = &p1; // pointer to pointer
    cout << p1 << endl << p2 << endl << p3 << endl; 
    cout << a << endl << b << endl << c << endl;
    cout << "deferencing..." << endl << *p1 << endl;
    cout << p4 << " " << *p4 << " " << **p4 << endl;

    return 0;
}