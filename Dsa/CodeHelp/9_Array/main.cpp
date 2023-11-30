#include <iostream>
using namespace std;

void printArray(int arr[], int size) {
    cout << "\nprinting Array:" << endl;

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << endl << "printing done!" << endl;
}

int main() {
    
    int arr0[100];
    int arr1[100] = { 0 };
    int arr2[100] = { 1 };

    printArray(arr0, 10);
    printArray(arr1, 10);
    printArray(arr2, 10 );
    fill_n(arr2, 100, 1);
    printArray(arr2, 10 );
    cout << arr0[101] << endl;
    return 0;;
}