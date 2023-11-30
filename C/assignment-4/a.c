#include <stdio.h>

int main() {

   printf("Roll Number: 2k22/A15/25; Name: Suraj Shukla\n");
   float fahrenheit, celsius;

   printf("Enter the temperature in Fahrenheit: ");
   scanf("%f", &fahrenheit);

   celsius = (fahrenheit - 32) * 5 / 9;

   printf("Temperature in Celsius: %.2f\n", celsius);

   return 0;
}
