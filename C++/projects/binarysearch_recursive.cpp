#include <iostream>
using namespace std;


// methods of passing arrays as an argument
/* 
int recursive_binary_search(int * arr) {
    cout << arr[4] << endl;
}
*/

/* 
int recursive_binary_search(int arr[]) {
    cout << arr[4] << endl;
} 
*/

int recursive_binary_search(int * arr, int a, int b, int num) {

    int mid = a + ( b - a) / 2;

    if ( num == arr[mid]) {
        return mid;
    }

    // else if ( b < a ) {
    //     return "Not Found"
    // }

    else { 
        if ( num > arr[mid] ) {
            a = mid;
        } else {
            b = mid;
        }
        recursive_binary_search(arr, a, b, num);
    }
}

int main() {
    int nums[] = {3, 4, 5, 6, 42}, size, num = 4;

    cout << recursive_binary_search(nums, 0, 5, num) << endl;
    return 0;
}