#include <stdio.h>

int isPrime(int number) {
    if (number <= 1) {
        return 0;
    }

    for (int i = 2; i <= number / 2; i++) {
        if (number % i == 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    printf("Roll Number: 2k22/A15/25; Name: Suraj Shukla\n");

    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    if (isPrime(number)) {
        printf("%d is prime.\n", number);
    } else {
        printf("%d is not prime.\n", number);
    }

    return 0;
}
