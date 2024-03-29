#include <iostream>
#include "index.h"
using namespace std;

// reversing the elements of original array
void reverse_array_by_for(int arr[], int size) {

    int temp_value;

    for (int i = 0; i < size/2; i++) {
        temp_value = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp_value;
    }
}

// reversing the alternate elements of array
void reverse_alternate_elements_by_for(int arr[], int size) {

    int temp_value;

    for (int i = 0; i < size/2; i++) {
        temp_value = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp_value;
    }
}


// reversing the elements of original array
void reverse_array_by_while(int arr[], int size) {

    int start = 0;
    int end = size - 1;

    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

// reversing the alternate elements of array
void reverse_alternate_elements_by_while(int arr[], int size) {

    int start = 0;
    int end = size - 1;

    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        start++;
        end--;
        end--;
    }
}

int main() {
    
    int arr[] = { 23, 34, 34, 45, 26, 67, 3, 5, 7, 10};

    printArray(arr, 10);

    reverse_array_by_for(arr, 10);
    printArray(arr, 10);

    reverse_array_by_while(arr, 10);
    printArray(arr, 10);

    return 0;
}