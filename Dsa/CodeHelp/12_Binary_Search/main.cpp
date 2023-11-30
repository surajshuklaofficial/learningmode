#include <iostream>
using namespace std;

template <class T>
int binary_search(T arr[], int size, T key) {
    int start = 0;
    int end = size - 1;

    int mid;
    while ( start <= end ) {
        
        mid = start + (end - start)/2; // (start + end)/2 => can cause overflow error

        if (arr[mid] == key) {
            return mid;

        } else if (arr[mid] > key) {
            end = mid - 1;

        } else if (arr[mid] < key) {
            start = mid + 1;
        }
    }

    return -1;
};

int main() {
    
    int even_arr[10] = { 1, 2, 3, 4, 8, 13, 24, 45, 344, 566 };
    int odd_arr[9] = { -3, 1, 2, 5, 13, 24, 32, 34, 56 };

    cout << binary_search<int>(even_arr, 10, 45) << endl;
    cout << binary_search<int>(odd_arr, 9, -3) << endl;
    return 0;
}