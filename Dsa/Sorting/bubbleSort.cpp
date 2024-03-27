#include <iostream>
using namespace std;

// iterative approach
void bubbleSort(int arr[], int size) {
    while (size > 0) {
        for (int i = 0; i < size - 1; i++) {
            if (arr[i] > arr[i + 1]) swap(arr[i], arr[i + 1]);
        }
        size--;
    }
}

// recursive approach
void swapper(int arr[], int size) {
    if (size == 1) return;
    if (arr[0] > arr[1]) swap(arr[0], arr[1]);
    swapper(arr + 1, size - 1); 
}

void bubbleSortR(int arr[], int size) {
    if (size == 1) return;
    swapper(arr, size);
    bubbleSortR(arr, size - 1);
}

void print(int arr[], int size) {
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    
    int arr[7] = {3, 4, 2, 5, 1, 9, 4};

    // bubbleSort(arr, 5);
    bubbleSortR(arr, 7);
    print(arr, 7);


    return 0;
}