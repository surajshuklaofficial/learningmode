#include <stdio.h>

void printHalfPyramid(int rows) {
   for (int i = 1; i <= rows; i++) {
      for (int j = 1; j <= i; j++) {
         printf("* ");
      }
      printf("\n");
   }
}

void printInvertedHalfPyramid(int rows) {
   for (int i = rows; i >= 1; i--) {
      for (int j = 1; j <= i; j++) {
         printf("* ");
      }
      printf("\n");
   }
}

void printFullPyramid(int rows) {
   int spaces = rows - 1;
   for (int i = 1; i <= rows; i++) {
      for (int j = 1; j <= spaces; j++) {
         printf(" ");
      }
      spaces--;
      for (int j = 1; j <= 2 * i - 1; j++) {
         printf("*");
      }
      printf("\n");
   }
}

int main() {

   printf("Roll Number: 2k22/A15/25; Name: Suraj Shukla\n");

   int rows;

   printf("Enter the number of rows: ");
   scanf("%d", &rows);

   printf("Half Pyramid Pattern:\n");
   printHalfPyramid(rows);

   printf("Inverted Half Pyramid Pattern:\n");
   printInvertedHalfPyramid(rows);

   printf("Full Pyramid Pattern:\n");
   printFullPyramid(rows);

   return 0;
}
