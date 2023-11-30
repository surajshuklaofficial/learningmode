#include <stdio.h>

int main() {

    printf("Roll Number: 2k22/A15/25; Name: Suraj Shukla\n");

    float principle, time, rate, SI;


    printf("Enter principle value: ");
    scanf("%f", &principle);

    printf("Enter time: ");
    scanf("%f", &time);

    printf("Enter rate: ");
    scanf("%f", &rate);

    SI = (principle * time * rate) / 100;

    printf("The value of Simple Interest is: %f", SI);

}