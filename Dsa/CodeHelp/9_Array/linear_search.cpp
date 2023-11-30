#include <iostream>
using namespace std;

int linear_search(int arr[], int size, int num) {
    for (int i = 0; i < size; i++) {
        if ( num == arr[i]) {
            return i;
        }
    }

    return -1;
}

int main() {
    
    int arr[] = { 23, 34, 34, 45, 26, 67, 3, 5, 7};

    int num;
    cout << "Enter num to search: ";
    cin >> num;

    cout << linear_search(arr, 9, num) << endl;
    return 0;
}