#include <stdio.h>
#include <string.h>

void convertCase(char str[]) {
    int length = strlen(str);

    for (int i = 0; i < length; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            // Convert lowercase to uppercase
            str[i] = str[i] - 32;
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            // Convert uppercase to lowercase
            str[i] = str[i] + 32;
        }
    }
}

int main() {
    printf("Roll Number: 2k22/A15/25; Name: Suraj Shukla\n");

    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Removing the newline character from the string
    str[strcspn(str, "\n")] = '\0';

    convertCase(str);

    printf("Converted string: %s\n", str);

    return 0;
}
