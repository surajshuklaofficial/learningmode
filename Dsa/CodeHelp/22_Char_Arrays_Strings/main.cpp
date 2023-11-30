#include <iostream>
#include <string>
using namespace std;

int getLength(char* arr) {
    
    int length = 0;
    for (int i = 0; arr[i] != '\0'; i++) {
        length++;
    }
    return length;
}

int getLength(string arr) {
    
    int length = 0;
    for (int i = 0; arr[i] != '\0'; i++) {
        length++;
    }
    return length;
}

// A --> 65; a --> 97; 0 --> 48
void tolowercase(char* arr) {
    for (int i = 0; arr[i] != '\0'; i++) {
        if (arr[i] < 'a') {
            arr[i] += 32; // or arr[i] = arr[i] - 'A' + 'a';
        }
    }
}

void tolowercase(string arr) {
    for (int i = 0; arr[i] != '\0'; i++) {
        if (arr[i] < 'a') {
            arr[i] += 32; // or arr[i] = arr[i] - 'A' + 'a';
        }
    }
}

int main() {
    
    string name;
    // char name[20];
    cout << "Enter your name: ";
    getline(cin, name); 
    
    cout << "Length of entered name is " << getLength(name) << endl;
    tolowercase(name);
    cout << name << endl;

    // string s;
    // cout << "Enter your name: ";
    // cin >> s;
    // cout << s;



    return 0;
}