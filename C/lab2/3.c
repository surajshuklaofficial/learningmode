#include <stdio.h>

int main() {
    printf("Roll Number: 2k22/A15/25; Name: Suraj Shukla\n");

    double principal, rate, time, interest;

    printf("Enter the principal amount: ");
    scanf("%lf", &principal);

    printf("Enter the interest rate (in percentage): ");
    scanf("%lf", &rate);

    printf("Enter the time period (in years): ");
    scanf("%lf", &time);

    interest = (principal * rate * time) / 100;

    printf("Simple Interest: %lf\n", interest);

    return 0;
}
