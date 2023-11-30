#include <stdio.h>

// Function to convert decimal to binary
long decimalToBinary(int decimal) {
    long binary = 0;
    int remainder, place = 1;

    while (decimal > 0) {
        remainder = decimal % 2;
        binary += remainder * place;
        decimal /= 2;
        place *= 10;
    }

    return binary;
}

// Function to convert binary to decimal
int binaryToDecimal(long binary) {
    int decimal = 0;
    int remainder, base = 1;

    while (binary > 0) {
        remainder = binary % 10;
        decimal += remainder * base;
        binary /= 10;
        base *= 2;
    }

    return decimal;
}

int main() {
    printf("Roll Number: 2k22/A15/25; Name: Suraj Shukla\n");

    int choice, decimal;
    long binary;

    printf("1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter a decimal number: ");
            scanf("%d", &decimal);
            printf("Binary: %ld\n", decimalToBinary(decimal));
            break;

        case 2:
            printf("Enter a binary number: ");
            scanf("%ld", &binary);
            printf("Decimal: %d\n", binaryToDecimal(binary));
            break;

        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}
