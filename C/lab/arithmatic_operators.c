#include <stdio.h>

int main() {
    
    printf("Roll Number: 2k22/A15/25; Name: Suraj Shukla\n");

    int num1;
    int num2;

    printf("Enter number 1: ");
    scanf("%d", &num1);

    printf("Enter number 2: ");
    scanf("%d", &num2);

    int sum   = num1  +  num2;
    int sub   = num1  -  num2;
    int multi = num1  *  num2;
    int div   = num1  /  num2;


    printf("The value of sum  is: %d \n", sum);   
    printf("The value of sub is: %d \n", sub);   
    printf("The value of multi is: %d\n",  multi);
    printf("The value of div is: %d\n",  div);

}