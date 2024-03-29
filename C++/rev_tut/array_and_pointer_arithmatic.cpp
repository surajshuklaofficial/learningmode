#include <iostream>
using namespace std;

int main() {
    
    int nums[] = {1, 2, 3, 4, 5};

    // pointer arithmatic shown below
    cout << "Address of Element at index 0:" << nums << endl; // gives address of first element
    cout << "Address of Element at index 0:" << *nums << endl; // gives first element i.e., 0
    cout << "Address of Element at index 0:" << *(nums+4) << endl; // gives value stored at index 4 i.e., 5
    cout << "Address of Element at index 0:" << *(nums+5) << endl; // gives garbage value because no value is defined at index 5
    cout << "Element at index 0: " << nums[0] << endl; // gives first element i.e., 0

    nums[0] = 2; // c++ arrays are mutable
    cout << "Element at index 0 after mutation: " << nums[0] << endl; // gives first element i.e., 2

    return 0;
}