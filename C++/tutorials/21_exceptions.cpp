#include <iostream>
using namespace std;

int main(){
    try {
        cout << 5 + "5";
        throw ;
    }

    catch (...){
        cout<<"error";
    }
}