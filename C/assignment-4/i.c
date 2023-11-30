#include <stdio.h>

int isPalindrome(int number) {
   int originalNumber = number;
   int reverse = 0;

   while (number > 0) {
      int lastDigit = number % 10;
      reverse = reverse * 10 + lastDigit;
      number /= 10;
   }

   if (originalNumber == reverse) {
      return 1;  // Palindrome number
   } else {
      return 0;  // Not a palindrome number
   }
}

int main() {

   printf("Roll Number: 2k22/A15/25; Name: Suraj Shukla\n");

   int number;

   printf("Enter a number: ");
   scanf("%d", &number);

   if (isPalindrome(number)) {
      printf("%d is a palindrome number.\n", number);
   } else {
      printf("%d is not a palindrome number.\n", number);
   }

   return 0;
}
