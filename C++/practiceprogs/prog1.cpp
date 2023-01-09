// program to read a text file line by line and display each word separated by #

#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream myfile("prog1.txt");
    string mytext;
    while (getline(myfile,mytext)){
        cout<<mytext;
    }
    myfile.close(); 
}

