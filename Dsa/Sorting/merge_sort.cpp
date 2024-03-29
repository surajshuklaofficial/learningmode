#include <iostream>
using namespace std;

// TODO: optimize space complexity
void printArray(int arr[], int size) {
    cout << "\nprinting Array:" << endl;

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << endl << "printing done!" << endl;
}

void mergeArray(int arr[], int s, int e, int p)
{
    int len1 = p - s + 1;
    int len2 = e - p;

    int *arr1 = new int[len1];
    int *arr2 = new int[len2];

    int index = 0;
    int index1 = 0;
    int index2 = 0;
    for (int i = 0; i < len1; i++)
    {
        arr1[i] = arr[index];
        index++;
    }

    for (int i = 0; i < len2; i++)
    {
        arr2[i] = arr[index];
        index++;
    }

    index = 0;
    index1 = 0;
    index2 = 0;
    while (index1 < len1 && index2 < len2)
    {
        if (arr1[index1] < arr2[index2])
        {
            arr[index] = arr1[index1];
            index++;
            index1++;
        }
        else
        {
            arr[index] = arr2[index2];
            index++;
            index2++;
        }
    }

    while (index1 < len1)
    {
        arr[index] = arr1[index1];
        index++;
        index1++;
    }

    while (index1 < len1)
    {
        arr[index] = arr1[index1];
        index++;
        index2++;
    }

    delete[] arr1;
    delete[] arr2;  
}

void mergeSort(int arr[], int s, int e)
{
    if (s >= e)
        return;

    int p = s + (e - s) / 2;
    mergeSort(arr, s, p);
    mergeSort(arr, p + 1, e);

    mergeArray(arr, s, e, p);
}

int main()
{
    int arr[] = {11, 3, 14, 1, 4};
    mergeSort(arr, 0, 4);
    printArray(arr, 5);
    return 0;
}