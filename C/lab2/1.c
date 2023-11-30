#include <stdio.h>

int main() {
    printf("Roll Number: 2k22/A15/25; Name: Suraj Shukla\n");

    double num1, num2, sum, average;

    printf("Enter the first number: ");
    scanf("%lf", &num1);

    printf("Enter the second number: ");
    scanf("%lf", &num2);

    sum = num1 + num2;
    average = sum / 2;

    printf("Sum: %lf\n", sum);
    printf("Average: %lf\n", average);

    return 0;
}
