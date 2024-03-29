#include <iostream>
#include "../index.h"
#include <climits>
using namespace std;

void selection_sort(int arr[], int size) {
    
    int total_passes = size - 1; 
    int smallest_instance = INT_MAX, smallest_instance_index = 0;

    for (int i = 0; i < total_passes; i++) {
        for (int j = i; j < size; j++) {
            if (arr[j] <= smallest_instance) {
                smallest_instance_index = j;
                smallest_instance = arr[j];
            }
        }

        swap(arr[i], arr[smallest_instance_index]);
        smallest_instance = INT_MAX;
    }
};

int main() {
    
    int arr[] = { 23, 34, 34, 45, 26, 67, 3, 5, 7};

    printArray(arr, 9);

    selection_sort(arr, 9);


    printArray(arr, 9);

    return 0;
}