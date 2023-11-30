#include <stdio.h>

int main() {

   printf("Roll Number: 2k22/A15/25; Name: Suraj Shukla\n");

   int bool1, bool2;
   int result_and, result_or, result_not;

   printf("Enter the first boolean value (0 or 1): ");
   scanf("%d", &bool1);

   printf("Enter the second boolean value (0 or 1): ");
   scanf("%d", &bool2);

   result_and = bool1 && bool2;
   result_or = bool1 || bool2;
   result_not = !bool1;

   printf("Result of AND operation: %d\n", result_and);
   printf("Result of OR operation: %d\n", result_or);
   printf("Result of NOT operation on first boolean: %d\n", result_not);

   return 0;
}
