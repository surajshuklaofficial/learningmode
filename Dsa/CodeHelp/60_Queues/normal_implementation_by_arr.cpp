#include <iostream>
using namespace std;

template <class T>
class Queue {
    T *arr;
    int front;
    int rear;
    int size;

    public:
        Queue(int n);
        void enqueue(int data);
        T dequeue();
        T getFront();
        T getRear();
        bool isEmpty();
        void display();
        ~Queue() {
            delete[] arr;
        }
};

template <class T>
Queue<T> :: Queue(int n) {
    size = n;
    arr = new T[size];
    front = -1;
    rear = 0;
}

template <class T>
void Queue<T> :: enqueue(int data) {
    if (rear == size - 1) {
        cout << "Queue Overflow!" << endl;
    } else {
        arr[rear] = data;
        rear++;
    }
    if (front == -1) front++;
}

template <class T>
T Queue<T> :: dequeue() {

    front++;
    if (isEmpty()) {
        return -1;
    } else {
        return arr[front - 1];
    }
}

template <class T>
T Queue<T> :: getFront() {
    if (isEmpty()) {
        return T();
    } else {
        return arr[front];
    }
}

template <class T>
T Queue<T> :: getRear() {
    if (isEmpty()) {
        return T();
    } else {
        return arr[rear - 1];
    }
}

template <class T>
bool Queue<T> :: isEmpty() {
    return (front == rear || front == -1);
}
template <class T>
void Queue<T> :: display() {
    for (int i = front; i < rear; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    Queue<int> intQueue(5); // Creating an integer queue with a capacity of 5

    intQueue.enqueue(10);
    intQueue.enqueue(20);
    intQueue.enqueue(30);
    intQueue.enqueue(60);
    intQueue.enqueue(50);

    cout << "Front of the queue: " << intQueue.getFront() << endl; // Should print 10
    cout << "Rear of the queue: " << intQueue.getRear() << endl;   // Should print 30

    intQueue.dequeue(); // Dequeue an element

    cout << "Front of the queue after dequeue: " << intQueue.getFront() << endl; // Should print 20

    return 0;
}