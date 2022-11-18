#include <iostream>
using namespace std;

void myfunc(string fname , string country = "India"){ // function declaration; this func will not return any value-void; country-optional parameter / default parameter, India-default value 
    cout << "learning functions in c++" << fname << country;  // function definition
}

int main(){
    myfunc("suraj shukla");
}


/*
When a parameter is passed to the function, 
it is called an argument. So, from the example above: 
fname is a parameter, while suraj shukla is argument.
*/
