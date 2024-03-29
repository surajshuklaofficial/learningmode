#include <iostream>
#include "../index.h"
using namespace std;

int findMin(int arr[], int size)
{
    int mini = arr[0];
    for (int i = 1; i < size; i++)
    {
        mini = min(mini, arr[i]);
    }

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == mini)
            return i;
    }
}

void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int minIndex = findMin(arr + i, size - i);
        swap(arr[i], arr[minIndex + i]);
    }
}

void selectionSortR(int arr[], int size)
{
    if (size == 1)
        return;

    int minIndex = findMin(arr, size);
    swap(arr[0], arr[minIndex]);
    selectionSortR(arr + 1, size - 1);
}

int main()
{
    int arr[] = {11, 3, 14, 1, 4, 1, 3, 2, 7, 12};
    selectionSortR(arr, 10);
    printArray(arr, 10);
    return 0;
}