#include <iostream>
#include <vector>
#include "../index.h"
using namespace std;

// TODO: optimize space complexity

void mergeArray(int arr[], int s, int e, int p)
{
    int len1 = p - s + 1;
    int len2 = e - p;

    int *arr1 = new int[len1];
    int *arr2 = new int[len2];

    int index = s; // remember
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

    index = s;
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

void mergeTwoSortedArray(vector<int> &arr, int s, int p, int e)
{   
    int len1 = p - s + 1;
    int len2 = e - p;

    vector<int> arr1;
    vector<int> arr2;

    int index = s;
    for (int i = 0; i < len1; i++)
    {
        arr1.push_back(arr[index]);
        index++;
    }

    for (int i = 0; i < len2; i++)
    {
        arr2.push_back(arr[index]);
        index++;
    }

    index = s;
    int index1 = 0;
    int index2 = 0;
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

    while (index2 < len2)
    {
        arr[index] = arr2[index2];
        index++;
        index2++;
    }

}

void mergeSort(vector<int> &arr, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    mergeTwoSortedArray(arr, left, mid, right);
    printVec(arr);
}

int main()
{
    // int arr[] = {11, 3, 14, 1, 4};
    int arr[] = {5, 1, 5, 9, 1};
    vector<int> arrV;

    for (int i = 0; i < 5; i++) arrV.push_back(arr[i]);

    // printVec(arrV);
    // mergeSort(arrV, 0, 4);
    mergeSort(arr, 0, 4);


    printArray(arr, 5);
    return 0;
}