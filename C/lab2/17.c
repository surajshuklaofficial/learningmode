#include <stdio.h>

int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    printf("Roll Number: 2k22/A15/25; Name: Suraj Shukla\n");

    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    printf("Factorial of %d is %d\n", number, factorial(number));

    return 0;
}
