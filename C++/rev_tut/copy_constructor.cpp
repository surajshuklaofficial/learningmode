#include <iostream>
using namespace std;

class Number {
    int data;
    public:
        Number(){};
        Number(int val) {
            data = val;
        }

        Number(Number &obj) {
            cout << "Copy constructor running !!!" << endl;
            data = obj.data;
        }

        void display(){
            cout << "data: " << data << endl;
        }
};

int main() {
    Number z1(4), z3;
    z1.display();

    Number z2 = z1; // CC invoked
    z2.display();

    z3 = z1; // CC not invoked
    z3.display();

    Number z4(z1); // CC invoked
    z4.display();
    return 0;
}