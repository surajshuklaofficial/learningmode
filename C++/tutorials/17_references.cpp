#include <iostream>
using namespace std;

int main(){
    string food = "Pizza";
    string &meal = food; // reference to food; it is just an another name given to the food

    cout << food << endl;
    cout << meal << endl;
    cout << &food << " " << &meal << endl; // to get memory address - in hexadecimal

    // pointer - a variable that stores the memory address as its value
    string* ptr = &food; // a pointer variable, with the name ptr, that stores the address of food

    cout << ptr << endl;
    cout << *ptr << endl; // dereference

    // modifying pointers value ; value of original variable will also change
    *ptr = "burger";
    cout << *ptr << endl;
    cout << ptr << endl; // but memory address remains the same
    cout << food <<endl;
}   

/*
references and pointers are one of the things 
that make c++ stand out from other programming 
languages like Python and Java.
*/