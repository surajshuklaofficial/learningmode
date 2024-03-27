#include <iostream>
#include "../index.h"
using namespace std;

int lessThanCount(int arr[], int size, int key)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < key)
            count++;
    }

    return count;
}

void quickSort(int arr[], int size)
{
    if (size == 1 || size == 0) return;

    int less = lessThanCount(arr, size, arr[0]);

    swap(arr[0], arr[less]);

    int left = 0, right = size - 1;
    while (left < less && less < right) {
        if (arr[left] > arr[less]) {
            if (arr[less] > arr[right]) {
                swap(arr[left], arr[right]);
            } else {
                right--;
            }
        } else {
            left++;
        }
    }

    quickSort(arr, less);
    quickSort(arr + less + 1, size - less - 1);
    printArray(arr, size);
}

int main()
{
    int arr[] = {11, 3, 14, 1, 4, 1, 3, 2, 7, 12};
    quickSort(arr, 10);
    printArray(arr, 10);
    return 0;
}