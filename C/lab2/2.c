#include <stdio.h>

int main() {
    printf("Roll Number: 2k22/A15/25; Name: Suraj Shukla\n");

    int numbers[10];
    int i, greatest;

    printf("Enter 10 numbers:\n");

    for (i = 0; i < 10; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    greatest = numbers[0];

    for (i = 1; i < 10; i++) {
        if (numbers[i] > greatest) {
            greatest = numbers[i];
        }
    }

    printf("The greatest number is: %d\n", greatest);

    return 0;
}
