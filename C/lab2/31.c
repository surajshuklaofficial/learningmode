#include <stdio.h>

int calculateSum(int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    printf("Roll Number: 2k22/A15/25; Name: Suraj Shukla\n");

    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);

    int sum = calculateSum(arr, size);

    printf("Sum: %d\n", sum);

    return 0;
}
