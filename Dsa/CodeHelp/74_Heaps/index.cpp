#include <iostream>
using namespace std;

class Heaps {
    int arr[100];
    int pointer;

    void swipper(int index = 1) {
        while (index < pointer) {
            int leftChild = 2 * index;
            int rightChild = leftChild + 1;

            if (leftChild < pointer && arr[index] < arr[leftChild]) {
                swap(arr[index], arr[leftChild]);
                swipper(leftChild);
            }
            if (rightChild < pointer && arr[index] < arr[rightChild]) {
                swap(arr[index], arr[rightChild]);
                swipper(rightChild);
            }
            return;
        }
    }
    public: 
        Heaps() : pointer(0) {};

        void insert(int data) {
            pointer++;

            arr[pointer] = data;

            int index = pointer;
            while ( index > 1) {
                int parent = index / 2;

                if (arr[index] > arr[parent]) {
                    swap(arr[index], arr[parent]);
                    index = parent;    
                } else break;
            }
        }

        void display() {
            for (int i = 1; i <= pointer; i++) cout << arr[i] << " ";
            cout << endl;
        }

        void del() {
            if (pointer == 0) cout << "Nothing to delete!" << endl;

            // step 1: put last element into first index
            arr[1] = arr[pointer];

            // step 2: remove last element
            pointer--;

            // step 3: take root node to it's correct position
            swipper();
        }
};

// it's complexity is O(log n); 
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[largest] < arr[left]) {
        largest = left;
    }

    if (right <= n && arr[largest] < arr[right]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

// heap sort - it's complexity is O(n log n)
void heapSort(int arr[], int size) {
    while (size > 0) {
        heapify(arr, size, 1);
        cout << arr[1] << endl;
        swap(arr[size], arr[1]);
        size--;
    }  
}

int main() {
    Heaps H;

    H.insert(375);
    H.insert(65);
    H.insert(75);
    H.insert(60);
    H.insert(55);
    H.insert(70);

    H.display();
    H.del();
    H.display();

    int arr[] = {-1, 55, 57, 56, 54, 52};
    int n = 5;

    // here it becomes O(n) - bulding a heap
    for (int i = n/2; i > 0; i--) {
        heapify(arr, n, i);
    }

    // heapSort(arr, n);

    cout << "printing after heapify: " << endl;
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    } cout << endl;

    
    return 0;
}