#include <iostream>
#include <string>
using namespace std;

int main(){
    int x = 6,y=6;
    if (x<y) {
        cout<<"if executed";
    }

    else if (x>y) {
        cout<<"else if executed";
    }

    else {
        cout<<"else executed";
    }

    // short hand if-else(ternary operator)
    int time = 5;
    string result = (time>8)?"Good morning":"Good afternoon"; // variable = (condition) ? expressTrue : expressFalse;
    cout<<result;
}