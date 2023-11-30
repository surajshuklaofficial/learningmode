#include <stdio.h>

int main() {
   printf("Roll Number: 2k22/A15/25; Name: Suraj Shukla\n");
   int num1, num2, num3, largest;

   printf("Enter the first number: ");
   scanf("%d", &num1);

   printf("Enter the second number: ");
   scanf("%d", &num2);

   printf("Enter the third number: ");
   scanf("%d", &num3);

   largest = num1;

   if (num2 > largest) {
      largest = num2;
   }

   if (num3 > largest) {
      largest = num3;
   }
   printf("The largest number is %d.\n", largest);
}
