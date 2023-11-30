#include <stdio.h>
#include <string.h>

int stringLength(char str[]) {
    int length = 0;

    while (str[length] != '\0') {
        length++;
    }

    return length;
}

void printCharacters(char str[]) {
    int i = 0;

    while (str[i] != '\0') {
        printf("%c ", str[i]);
        i++;
    }

    printf("\n");
}

int main() {
    printf("Roll Number: 2k22/A15/25; Name: Suraj Shukla\n");

    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character from the string
    str[strcspn(str, "\n")] = '\0';

    int length = stringLength(str);

    printf("Length of the string: %d\n", length);

    printf("Characters in the string: ");
    printCharacters(str);

    return 0;
}
