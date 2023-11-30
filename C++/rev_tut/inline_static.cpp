#include <iostream>
using namespace std;

int add(int a, int b) {
    static int c = 0;
    c++;
    return a + b + c;
}

inline int add_line(int a, int b) {
    return a + b;
}


int main() {
    
    cout << add(4, 5) << endl;
    cout << add(4, 5) << endl;
    cout << add_line(4, 5) << endl; // inline gets copied here during compile time
    return 0;
}