#include <iostream>
#include "../index.h"
using namespace std;

void insertion_sort(int* arr, int size) {

    int sorted_array_pointer = 0;
    int instance = 0;

    for (int i = 0; i < size; i++) {
        instance = arr[i];
        sorted_array_pointer = i - 1;
        while ((instance < arr[sorted_array_pointer]) && sorted_array_pointer >= 0) {
            arr[sorted_array_pointer + 1] = arr[sorted_array_pointer];
            sorted_array_pointer--;
        }
        arr[sorted_array_pointer + 1] = instance;
    }
}

int main() {
    int arr[] = { 23, 34, 34, 45, 26, 67, 3, 5, 7};

    printArray(arr, 9);

    insertion_sort(arr, 9);


    printArray(arr, 9);

    return 0;
}