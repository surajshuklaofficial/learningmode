#include <iostream>
using namespace std;

// declaring a structure named "car" - to use it as a datatype
struct car{
    int yearOfLaunch;
    string brand;
    string model;
};

int main(){
    car myCar1;
    myCar1.brand = "BMW", myCar1.model = "X5", myCar1.yearOfLaunch = 1999;
    return 0;
}