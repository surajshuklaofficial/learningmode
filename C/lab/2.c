#include <stdio.h>

int main() {
   
   printf("Roll Number: 2k22/A15/25; Name: Suraj Shukla\n");

   float principal, rate, time, interest;

   printf("Enter the principal amount: ");
   scanf("%f", &principal);

   printf("Enter the rate of interest: ");
   scanf("%f", &rate);

   printf("Enter the time period (in years): ");
   scanf("%f", &time);

   interest = (principal * rate * time) / 100;

   printf("Simple Interest = %.2f\n", interest);

   return 0;
}
