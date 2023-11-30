#include <stdio.h>
#include <math.h>

int main() {
    printf("Roll Number: 2k22/A15/25; Name: Suraj Shukla\n");

    double base, exponent, result;

    printf("Enter the base: ");
    scanf("%lf", &base);

    printf("Enter the exponent: ");
    scanf("%lf", &exponent);

    result = pow(base, exponent);

    printf("Result: %lf\n", result);

    return 0;
}
