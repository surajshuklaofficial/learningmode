#include <iostream>
#include "../index.h"
using namespace std;

void insertionSort(int arr[], int size)
{
    int index = 0;
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > arr[index])
            index = i;
        else
        {
            int temp = arr[i];
            while (temp < arr[index] && index >= 0)
            {
                arr[index + 1] = arr[index];
                index--;
            }

            arr[index + 1] = temp;
            index = i;
        }
    }
}

int main()
{
    int arr[] = {11, 3, 14, 1, 4, 1, 3, 2, 7, 12};
    insertionSort(arr, 10);
    printArray(arr, 10);
    return 0;
}