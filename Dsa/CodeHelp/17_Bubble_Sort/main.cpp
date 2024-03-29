#include <iostream>
#include "../index.h"
using namespace std;

void bubble_sort(int* arr, int size) {

    int isSwapped = false;
    for (int i = 1; i < size; i++) {         // total_passes = size - 1
        for (int j = 0; j < size - i; j++) {
            if (arr[j + 1] < arr[j]) {
                swap(arr[j], arr[j + 1]);
                isSwapped = true;
            }
        }

        if (!isSwapped) break; // if there is no swapping; it's mean array is already sorted
    }
}

int main() {
    int arr[] = { 23, 34, 34, 45, 26, 67, 3, 5, 7};

    printArray(arr, 9);

    bubble_sort(arr, 9);


    printArray(arr, 9);
    return 0;
}