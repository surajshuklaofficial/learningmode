#include <iostream>
using namespace std;

int main() {
    
    enum Meal{breakfast, lunch, dinner };
    cout << breakfast << endl << lunch << endl << dinner << endl;

    Meal m1 = lunch;
    cout << m1 << endl;
    
    return 0;
}