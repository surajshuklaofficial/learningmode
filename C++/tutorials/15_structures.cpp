#include <iostream>
using namespace std;

int main(){
    struct {             // structure declaration
        int myNum;       // member (int variable)
        string myString; // member (string variable)
    } myStruture1 , myStruture2;        // structure variables - one structure in multiple variables

    myStruture1.myNum = 1;       // assigning values
    myStruture1.myString = "1";  
    cout << myStruture1.myNum << " " << myStruture1.myString << endl; // accessing structure members
}

/*
structures are dynamic datatype.
*/