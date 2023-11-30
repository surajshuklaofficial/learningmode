#include <stdio.h>

int main() {

   printf("Roll Number: 2k22/A15/25; Name: Suraj Shukla\n");

   int num;

   printf("Enter a number: ");
   scanf("%d", &num);

   if (num > 0) {
      printf("The number is positive.\n");
   } else if (num < 0) {
      printf("The number is negative.\n");
   } else {
      printf("The number is zero.\n");
   }

   return 0;
}
