#include <iostream>
#include "../index.h"
using namespace std;

void insertionSort(int arr[], int size)
{
    int index = 0;
    for (int i = 1; i < size; i++)
    {
        while (arr[index + 1] < arr[index] && index >= 0) // by reversing the condition sorting can be change from asc to desc => arr[index] < arr[index + 1]
        {
            swap(arr[index], arr[index + 1]);
            index--;
        }
        index = i;
    }
}

void insertionSortR(int arr[], int size, int index)
{
    // base case
    if (index == size - 1)
        return;

    int temp = index;
    while (index >= 0 && arr[index] > arr[index + 1]) // by reversing the condition sorting can be change from asc to desc => arr[index] < arr[index + 1]
    {
        swap(arr[index], arr[index + 1]);
        index--;
    }

    insertionSortR(arr, size, temp + 1);
}

int main()
{
    int arr[] = {11, 3, 14, 1, 4, 1, 3, 2, 7, 12};
    // insertionSortR(arr, 10, 0);
    insertionSort(arr, 10);
    printArray(arr, 10);
    return 0;
}