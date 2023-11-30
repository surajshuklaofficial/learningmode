#include <stdio.h>

int main() {

   printf("Roll Number: 2k22/A15/25; Name: Suraj Shukla\n");

   int number, sum = 0;

   printf("Enter a five-digit number: ");
   scanf("%d", &number);

   // Extracting and adding individual digits
   sum += number % 10;      // add the last digit
   number /= 10;            // remove the last digit
   sum += number % 10;      // add the next digit
   number /= 10;            // remove the next digit
   sum += number % 10;      // add the next digit
   number /= 10;            // remove the next digit
   sum += number % 10;      // add the next digit
   number /= 10;            // remove the next digit
   sum += number % 10;      // add the first digit

   printf("Sum of digits: %d\n", sum);

   return 0;
}
