#include <stdio.h>

int main() {
    printf("Roll Number: 2k22/A15/25; Name: Suraj Shukla\n");

    int rows, i, j;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    for (i = 1; i <= rows; i++) {
        for (j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}
