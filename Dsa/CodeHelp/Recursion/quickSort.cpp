#include <iostream>
#include <vector>
#include "../index.h"
using namespace std;

int lessThanCount(vector<int> &arr, int start, int end, int key)
{
    int count = 0;
    for (int i = start; i <= end; i++)
    {
        if (arr[i] < key)
            count++;
    }

    return count;
}

void quickSortAlgo(vector<int> &arr, int start, int end)
{
    if (start >= end) return;

    int less = lessThanCount(arr, start, end, arr[start]) + start;

    swap(arr[start], arr[less]);

    int left = start, right = end;
    while (left < less && less < right) {
        if (arr[left] >= arr[less]) {
            if (arr[less] > arr[right]) {
                swap(arr[left], arr[right]);
                left++;
                right--;
            } else {
                right--;
            }
        } else {
            left++;
        }
    }

    quickSortAlgo(arr, start, less - 1);
    quickSortAlgo(arr, less + 1, end);
}

int main()
{
    // int arr[] = {11, 13, 14, 1, 4, 1, 3, 2, 7, 12};
    int arr[] = {2, 9, 9, 8, 9, -6, 3 };
    int size = 7;
    vector<int> arrV;
    for (int i = 0; i < size; i++) {
        arrV.push_back(arr[i]);
    }
    quickSortAlgo(arrV, 0, 6);
    printVec(arrV);
    return 0;
}