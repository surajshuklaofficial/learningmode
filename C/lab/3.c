#include <stdio.h>

int main() {
   printf("Roll Number: 2k22/A15/25; Name: Suraj Shukla\n");

   int num1, num2, sum, difference, product;
   float quotient;

   printf("Enter the first number: ");
   scanf("%d", &num1);

   printf("Enter the second number: ");
   scanf("%d", &num2);

   sum = num1 + num2;
   difference = num1 - num2;
   product = num1 * num2;
   quotient = (float) num1 / num2;

   printf("Sum: %d\n", sum);
   printf("Difference: %d\n", difference);
   printf("Product: %d\n", product);
   printf("Quotient: %.2f\n", quotient);

   return 0;
}
