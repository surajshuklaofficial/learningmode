#include <stdio.h>

int main() {
    printf("Roll Number: 2k22/A15/25; Name: Suraj Shukla\n");

    int numbers[] = {10, 20, 30, 40, 50};
    int *ptrArray[5];

    for (int i = 0; i < 5; i++) {
        ptrArray[i] = &numbers[i];
        printf("Element %d: %d\n", i, *ptrArray[i]);
    }

    return 0;
}
