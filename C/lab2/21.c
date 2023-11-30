#include <stdio.h>
#include <string.h>

int main() {
    printf("Roll Number: 2k22/A15/25; Name: Suraj Shukla\n");

    char str1[100];
    char str2[100];
    char result[200];

    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);

    // Removing the newline character from the strings
    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';

    // Copying the characters of the first string to the result string
    int i, j;
    for (i = 0; str1[i] != '\0'; i++) {
        result[i] = str1[i];
    }

    // Concatenating the characters of the second string to the result string
    for (j = 0; str2[j] != '\0'; j++, i++) {
        result[i] = str2[j];
    }
    result[i] = '\0';

    printf("Concatenated string: %s\n", result);

    return 0;
}
