#include <iostream>
using namespace std;

int main(){
    for (int i = 0; i<5; i++){    // for (statement 1; statement 2; statement 3)
        cout << i << "\n";
    }

    // for-each loop
    int myNumbers[5] = {10,20,30,40,50};
    for (int i : myNumbers){             // for (type variableName : arrayName)
        cout << i << endl;
    }

    string cars[5] = { "farrari", "lamborghini", "bugati", "volvo", "scorpio"};
    for (string i : cars){             // for (type variableName : arrayName)
        cout << i << endl;
    }

    return 0;
}

/* 
statement 1: executed one time before the execution of code block
statement 2: condition
statement 3: executed every time
*/