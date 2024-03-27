#include <iostream>
using namespace std;

bool isSorted(int arr[], int size)
{
    if (size == 0 || size == 1) // if arr has 0 or 1 element then it is sorted
        return true;

    if (arr[0] > arr[1])
        return false;
    else
        isSorted(arr + 1, size - 1);
}

int calcSum(int arr[], int size)
{
    if (size == 0)
        return 0;

    return arr[0] + calcSum(arr + 1, size - 1);
}

bool binarySearch(int arr[], int left, int right, int key) {
    int mid = left + (right - left) / 2; 

    // element not found
    if (left > right) return false; // base case

    // element found
    if (arr[mid] == key) return true; // base case
    else if (arr[mid] > key) return binarySearch(arr, left, mid - 1, key);
    else return binarySearch(arr, mid + 1, right, key);
}

int main()
{

    int size = 9;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << isSorted(arr, size) << endl;
    cout << calcSum(arr, size) << endl;
    cout << binarySearch(arr, 0, size, 1);


    return 0;
}