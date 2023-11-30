#include <stdio.h>

int fibonacci(int n) {
   if (n <= 1) {
      return n;
   } else {
      return fibonacci(n - 1) + fibonacci(n - 2);
   }
}

int main() {

   printf("Roll Number: 2k22/A15/25; Name: Suraj Shukla\n");

   int terms, i;

   printf("Enter the number of terms: ");
   scanf("%d", &terms);

   printf("Fibonacci sequence: ");
   for (i = 0; i < terms; i++) {
      printf("%d ", fibonacci(i));
   }

   return 0;
}
