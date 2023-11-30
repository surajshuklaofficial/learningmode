#include <stdio.h>

int reverseNumber(int number) {
   int reversedNumber = 0;

   while (number != 0) {
      reversedNumber = reversedNumber * 10 + number % 10;
      number /= 10;
   }

   return reversedNumber;
}

int main() {

   printf("Roll Number: 2k22/A15/25; Name: Suraj Shukla\n");

   int number;

   printf("Enter a five-digit number: ");
   scanf("%d", &number);

   if (number >= 10000 && number <= 99999) {
      int reversedNumber = reverseNumber(number);
      printf("Reversed number: %d\n", reversedNumber);
   } else {
      printf("Invalid input! Please enter a five-digit number.\n");
   }

   return 0;
}
