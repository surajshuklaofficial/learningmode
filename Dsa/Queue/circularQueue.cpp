#include <iostream>
#include "../index.h"
using namespace std;

class Queue {
    int *arr;
    int frontPointer;
    int rearPointer;
    int size;
public:
    Queue() {
        size = 5;
        arr = new int[size];
        frontPointer = -1;
        rearPointer = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if (frontPointer == -1) return true;
        else return false;
    }

    void enqueue(int data) {
        if (rearPointer == frontPointer) { // queue is full
            cout << "Queue is FULL!" << endl;
        } else {
            arr[rearPointer] = data;
            rearPointer = (rearPointer + 1) % size;
        }

        if (frontPointer == -1) frontPointer = 0; // when queue was empty
    }

    int dequeue() {
        if (isEmpty()) return -1;
        else {
            int temp = arr[frontPointer];
            frontPointer = (frontPointer + 1) % size;

            // queue become empty
            if (frontPointer == rearPointer) {
                frontPointer = -1;
                rearPointer = 0;
            }

            return temp;
        }
    }

    int front() {
        if (isEmpty()) return -1;
        else return arr[frontPointer];
    }
};

int main() {
    
    Queue Q;

    cout << Q.isEmpty() << endl;
    Q.enqueue(4);
    Q.enqueue(5);
    Q.enqueue(2);
    Q.enqueue(3);
    Q.enqueue(5);
    Q.enqueue(3);

    Q.dequeue();

    Q.enqueue(6);

    Q.dequeue();

    Q.enqueue(7);

    Q.dequeue();

    Q.enqueue(8);

    Q.dequeue();

    Q.enqueue(9);

    cout << Q.isEmpty() << endl;
    return 0;
}