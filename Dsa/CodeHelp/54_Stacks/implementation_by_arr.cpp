#include <iostream>
using namespace std;

template <class T>
class Stack {
    T *arr; 
    int size;
    int top = -1;

    public:
        Stack(int size); // no need for <T> for the constructor
        void push(T data);
        T pop();
        bool isEmpty();
        bool isFull();
        T peek();
        void display();
};

template <class T>
Stack<T> :: Stack(int size) {
    this->size = size;
    arr = new T[size];
}

template <class T>
void Stack<T> :: push(T data) {
    if (isFull()) { // checking Stack overflow
        cout << "Stack is Full!" << endl;
    } else {
        top++;
        arr[top] = data;
    }
}

template <class T>
T Stack<T> :: pop() {
    if (isEmpty()) { // checking Stack underflow
        cout << "Stack is Empty!" << endl;
        return T(); // if you not wrote this then while cout garbage value will be returned; even though if i not return anything the function will not cause any error

    } else {
        top--;
        return arr[top + 1];
    }
}

template <class T>
bool Stack<T> :: isEmpty() {
    return (top == -1);
}

template <class T>
bool Stack<T> :: isFull() {
    return (top == size - 1);
}

template <class T>
T Stack<T> :: peek() {
    if (isEmpty()) {
        cout << "Stack is Empty!" << endl;
        return T(); // if you not wrote this then while cout garbage value will be returned
    } else {
        return arr[top];
    }
}

template <class T>
void Stack<T> :: display() {
    if (isEmpty()) {
        cout << "Stack is Empty!" << endl;
    } else {
        for (int i = top; i > -1; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    
    Stack<int> S1(5);

    // S1.push(3);
    // S1.push(8);
    // S1.push(7);
    // S1.push(6);
    // S1.push(5);

    S1.display();

    S1.pop();

    S1.display();

    cout << S1.peek() << endl << S1.isEmpty() << endl << S1.isFull() << endl;
    return 0;
}