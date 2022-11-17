#include <iostream>
using namespace std;

int main(){
    string cars[5] = { "farrari", "lamborghini", "bugati", "volvo", "scorpio"};
    int marks[5] = { 34,56,67,65,67};

    cout << cars[1] << " " << marks[0]<<endl;

    // to get size of array - sizeof() function
    cout << sizeof(marks) << endl; // sizeof() function gives size in terms of bytes
    cout << sizeof(marks)/sizeof(int) << endl; // to get number of elements

    return 0;
}

/*
c++ arrays are mutable, non-dyanamic datatype.
multi-dimensional arrays skipped.
*/