#include <stdio.h>
#include <string.h>

void reverseString(char str[]) {
    int length = strlen(str);
    int start = 0;
    int end = length - 1;

    while (start < end) {
        // Swap characters
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        // Move to the next characters
        start++;
        end--;
    }
}

int main() {
    printf("Roll Number: 2k22/A15/25; Name: Suraj Shukla\n");

    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Removing the newline character from the string
    str[strcspn(str, "\n")] = '\0';

    reverseString(str);

    printf("Reversed string: %s\n", str);

    return 0;
}
