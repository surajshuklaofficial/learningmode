#include <iostream>
using namespace std;

template <class T>
class Matrix {
    public : 
        T data[3][3];
        
        Matrix(T* arr);
        friend Matrix<T> mul(Matrix, Matrix); 
};

template <class T>
Matrix<T> :: Matrix(T* arr) {
    cout << arr;
}

template <class T>
Matrix<T> mul(Matrix A, Matrix B) {

}

int main() {
    
    int arr = {{1,2, 3}, {4, 5, 6}, {7, 8, 9}};
    Matrix<int> M1(arr);
    // M1.display();

    return 0;
}