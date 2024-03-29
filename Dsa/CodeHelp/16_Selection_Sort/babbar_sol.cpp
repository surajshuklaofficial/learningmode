#include <iostream>
#include "../index.h"
using namespace std;

// TC: O(n^2)
// SC: O(1)
// total passses: n(n - 1)/2
void selection_sort(int arr[], int size) {
    
    int total_passes = size - 1; 

    for (int i = 0; i < total_passes; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);
    }
};

int main() {
    
        int arr[] = { 23, 34, 34, 45, 26, 67, 3, 5, 7};

    printArray(arr, 9);

    selection_sort(arr, 9);


    printArray(arr, 9);

    return 0;
}