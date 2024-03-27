#include <iostream>
using namespace std;

void printArray(int arr[], int size) {
    cout << "\nprinting Array:" << endl;

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << endl << "printing done!" << endl;
}

void printArray(char arr[]) {
    cout << "\nprinting Array:" << endl;

    for (int i = 0; arr[i] != '\0'; i++) {
        cout << arr[i] << " ";
    }

    cout << endl << "printing done!" << endl;
}