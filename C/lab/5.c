#include <stdio.h>

int main() {

   printf("Roll Number: 2k22/A15/25; Name: Suraj Shukla\n");

   int num;

   printf("Enter a number: ");
   scanf("%d", &num);

   (num % 2 == 0) ? printf("The number is even.\n") : printf("The number is odd.\n");

   return 0;
}
