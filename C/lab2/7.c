#include <stdio.h>

int main() {
    printf("Roll Number: 2k22/A15/25; Name: Suraj Shukla\n");

    int number, reversedNumber = 0;

    printf("Enter a 5-digit number: ");
    scanf("%d", &number);

    while (number > 0) {
        int digit = number % 10;
        reversedNumber = reversedNumber * 10 + digit;
        number /= 10;
    }

    printf("Reversed number: %d\n", reversedNumber);

    return 0;
}
