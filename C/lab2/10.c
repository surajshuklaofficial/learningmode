#include <stdio.h>

void generateFibonacci(int n) {
    int first = 0, second = 1, next;

    printf("Fibonacci Sequence: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", first);

        next = first + second;
        first = second;
        second = next;
    }

    printf("\n");
}

int main() {
    printf("Roll Number: 2k22/A15/25; Name: Suraj Shukla\n");

    int n;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    generateFibonacci(n);

    return 0;
}
