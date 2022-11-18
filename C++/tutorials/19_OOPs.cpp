/* 
DRY : Don't Repeat Yourself
attributes == variables
methods == functions
*/

/*
The constructor has the same name as the class,
it is always public, and it does not have any 
return value.
*/

#include <iostream>
#include <string>
using namespace std;
class MyClass {
    public :        // access specifier
        int myNum;  // attribute
        string mystring; // attribute
        void mymethod();
};

void MyClass::mymethod()  {
    cout << "Hello world!";
}

class newClass: public MyClass {
    public:
    int myNum = 34;
};
int main(){
    MyClass obj1;
    obj1.mymethod();
    return 0;
}



