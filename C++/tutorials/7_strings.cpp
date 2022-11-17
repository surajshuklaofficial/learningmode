#include <iostream>
#include <string>

using namespace std;

int main(){
    string firstName = "Suraj";
    string lastName = "Shukla";
    string fullName = firstName.append(lastName);
    cout<<fullName<<endl;
    cout<<"The length of the txt string is:"<<fullName.length()<<endl; // size() is an alias of lenght()
    fullName[0] = 'J'; // c++ strings are mutable
    cout<<fullName<<endl;
    string newName;
    cout<<"Enter your name:";
    // cin>>newName;
    getline(cin,newName); // to read a line of text
    cout<<newName;
    return 0;
}

/*
Escape character:
1. \' = single quote
2. \" = double quote
3. \\ = backslash
4. \n = new line
5. \t = tab
*/