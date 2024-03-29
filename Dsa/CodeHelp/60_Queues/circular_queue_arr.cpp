#include <iostream>
using namespace std;

template <class T>
class CircularQueue {
    T *arr;
    int front; // here front will point on the first added element
    int rear; // here rear will point on the last added element
    int size;
    public:
        CircularQueue(int n) {
            size = n;
            arr = new T[size];
            front = -1;
            rear = -1;
        } 

        void enqueue(T data) {
            if (isFull()) {
                cout << "Queue OverFlow!" << endl;
            } else {
                rear = (rear + 1) % size;
                arr[rear] = data;
                if (front  == -1) front = 0;
            }
        }

        T dequeue() {
            if (isEmpty()) {
                cout << "Queue OverFlow!" << endl;
            } else {
                T item = arr[front];
                if (front == rear) {
                    front = rear = -1;
                } else {
                    front = (front + 1) % size;
                }
                return item;
            }
        }

        bool isEmpty() {
            return (front == -1 );
        }

        bool isFull() {
            return ((front == 0 && rear = size - 1) || front == rear + 1);
        }
}

int main() {
    
    return 0;
}


/*
	Time complexity: O(1) for all operations.
	Space Complexity: O(N)
	
	Where 'N' is the size of the queue. 
*/

// class CircularQueue{
//     // Initialise front and rear of the queue.
//     int rear, front;

//     // Size of the queue.
//     int d;

//     // Array To be used for the implementation.
//     vector<int> arr;

// public:
//     // Initialize the circular queue.
//     CircularQueue(int n){
//         d = n;

//         // For a circular queue the front and rear both start as empty.
//         front = rear = -1;

//         // Create the arrays.
//         arr = vector<int>(d);
//     }

//     // Enqueues 'X' into the Queue. Returns true if it gets enqueued into the queue, and false otherwise..
//     bool enqueue(int value){
//         if ((front == 0 && rear == d - 1) || (rear == (front - 1) % (d - 1))) {
//             /* 
//                If the queue is full, no more elements can be added so return false.
//                Queue will be full if front is at 1st element and rear is at last element.
//                OR if rear is equal to front - 1.
//             */
//             return false; 
//         } 
//         else if (front == -1) { 
//             // Queue is empty, hence insert the first element.
//             front = rear = 0; 
//             arr[rear] = value; 
//         } 
//         else if (rear == d - 1 && front != 0) { 
//             // If rear reaches end of queue but the first element is empty.
//             rear = 0; 
//             arr[rear] = value; 
//         } 
//         else{ 
//             // Otherwise simply enqueue the element.
//             rear ++; 
//             arr[rear] = value; 
//         } 
//         return true;
//     }

//     // Dequeues top element from the Queue. Returns -1 if the queue is empty, otherwise returns the dequeued element.
//     int dequeue(){
//         if (front == -1) {
//             // If queue is empty.
//             return -1; 
//         } 
  
//         // Initialise element to store dequeud element.
//         int data = arr[front]; 
//         arr[front] = -1; 
        
//         if (front == rear) {
//             // If the queue has only one element.
//             front = -1; 
//             rear = -1; 
//         } 
//         else if (front == d - 1){
//             // If front is the last element of the queue.
//             front = 0; 
//         }
//         else{
//             // In all other cases simply dequeue.
//             front++; 
//         }
//         // Return the dequeued element.
//         return data; 
//     }
// };