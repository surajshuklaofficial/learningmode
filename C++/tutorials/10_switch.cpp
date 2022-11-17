#include <iostream>
using namespace std;

int main() {
    int a = 0,b=4;
    switch (a+b) {
        case 2 :
        cout << "no";
        break;
        
        case 5:
        cout << "yes";
        break;

        case 6:
        cout << "no";
        break;

        default:
        cout << "if no case matched";
    }
}