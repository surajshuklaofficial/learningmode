#include <stdio.h>

int main() {
    printf("Roll Number: 2k22/A15/25; Name: Suraj Shukla\n");

    int number, sum = 0;

    printf("Enter a 5-digit number: ");
    scanf("%d", &number);

    while (number > 0) {
        int digit = number % 10;
        sum += digit;
        number /= 10;
    }

    printf("Sum of the digits: %d\n", sum);

    return 0;

}