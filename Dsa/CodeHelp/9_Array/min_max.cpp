#include <iostream>
#include <climits>
using namespace std;

void printArray(int arr[], int size) {
    cout << "\nprinting Array:" << endl;

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << endl << "printing done!" << endl;
}

int getMax(int num[], int size) {

    int max = INT_MIN;

    for (int i = 0; i < size; i++) {
        if (num[i] > max) {
            max = num[i];
        }
    }

    return max;
}

int getMin(int num[], int size) {

    int min = INT_MAX;

    for (int i = 0; i < size; i++) {
        if (num[i] < min) {
            min = num[i];
        }
    }

    return min;
}

int main() {
    
    int size;
    cout << "Enter size of Array: ";
    cin >> size;

    // int num[size]; // bad pratice
    int num[1000];

    int num1[] = {4, 2, 3, 1, 5};

    // for (int i = 0; i < size; i++){
    //     cout << "Enter Element-" << i << ": ";
    //     cin >> num1[i];
    // }   
    // cout << endl;

    printArray(num1, size);
    cout << "Maximum value of array is " << getMax(num1, size) << endl;
    cout << "Minimum value of array is " << getMin(num1, size) << endl;
    return 0;
}