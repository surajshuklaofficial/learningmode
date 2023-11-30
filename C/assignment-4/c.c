#include <stdio.h>

int main() {

   printf("Roll Number: 2k22/A15/25; Name: Suraj Shukla\n");

   int charMin, charMax, ucharMax;
   int shortMin, shortMax, ushortMax;
   int intMin, intMax, uintMax;
   long longMin, longMax, ulongMax;

   charMin = 1 << (sizeof(char) * 8 - 1);
   charMax = ~(charMin);
   ucharMax = charMax * 2 + 1;

   shortMin = 1 << (sizeof(short) * 8 - 1);
   shortMax = ~(shortMin);
   ushortMax = shortMax * 2 + 1;

   intMin = 1 << (sizeof(int) * 8 - 1);
   intMax = ~(intMin);
   uintMax = intMax * 2 + 1;

   longMin = 1L << (sizeof(long) * 8 - 1);
   longMax = ~(longMin);
   ulongMax = longMax * 2 + 1;

   printf("Range of char: %d to %d\n", charMin, charMax);
   printf("Range of unsigned char: 0 to %d\n", ucharMax);
   printf("Range of short: %d to %d\n", shortMin, shortMax);
   printf("Range of unsigned short: 0 to %d\n", ushortMax);
   printf("Range of int: %d to %d\n", intMin, intMax);
   printf("Range of unsigned int: 0 to %u\n", uintMax);
   printf("Range of long: %ld to %ld\n", longMin, longMax);
   printf("Range of unsigned long: 0 to %lu\n", ulongMax);

   return 0;
}
