#include <stdio.h>

int binaryToDecimal(int binary) {
   int decimal = 0, base = 1;

   while (binary > 0) {
      int lastDigit = binary % 10;
      decimal += lastDigit * base;
      binary /= 10;
      base *= 2;
   }

   return decimal;
}

int decimalToBinary(int decimal) {
   int binary = 0, base = 1;

   while (decimal > 0) {
      int lastDigit = decimal % 2;
      binary += lastDigit * base;
      decimal /= 2;
      base *= 10;
   }

   return binary;
}

int main() {

   printf("Roll Number: 2k22/A15/25; Name: Suraj Shukla\n");

   int choice, number;

   printf("Enter 1 to convert binary to decimal\n");
   printf("Enter 2 to convert decimal to binary\n");
   printf("Enter your choice: ");
   scanf("%d", &choice);

   if (choice == 1) {
      printf("Enter a binary number: ");
      scanf("%d", &number);
      printf("Decimal equivalent: %d\n", binaryToDecimal(number));
   } else if (choice == 2) {
      printf("Enter a decimal number: ");
      scanf("%d", &number);
      printf("Binary equivalent: %d\n", decimalToBinary(number));
   } else {
      printf("Invalid choice!\n");
   }

   return 0;
}
