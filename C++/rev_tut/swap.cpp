#include <iostream>
using namespace std;

void swapBypointers(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp; 
}

void swapByreferenceVar(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}
int main() {
    
    int a = 4, b = 2;

    swapBypointers(&a, &b);
    cout << "after swapping by pointer a & b: " << a << " " << b << endl;

    swapByreferenceVar(a, b);
    cout << "after swapping by referenceVar a & b: " << a << " " << b << endl;
    return 0;
}