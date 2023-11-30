#include <stdio.h>

int main() {
    printf("Roll Number: 2k22/A15/25; Name: Suraj Shukla\n");

    char operator;
    double num1, num2;

    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &operator);

    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);

    switch (operator) {
        case '+':
            printf("Sum: %lf\n", num1 + num2);
            break;

        case '-':
            printf("Difference: %lf\n", num1 - num2);
            break;

        case '*':
            printf("Product: %lf\n", num1 * num2);
            break;

        case '/':
            if (num2 != 0) {
                printf("Quotient: %lf\n", num1 / num2);
            } else {
                printf("Cannot divide by zero!\n");
            }
            break;

        default:
            printf("Invalid operator!\n");
            break;
    }

    return 0;
}