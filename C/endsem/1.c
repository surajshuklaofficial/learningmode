#include <stdio.h>

// Function to concatenate two strings using pointers
void concatenateStrings(char* dest, const char* src) {
    // Move the destination pointer to the end of the string
    while (*dest != '\0') {
        dest++;
    }

    // Copy the source string to the destination
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }

    // Add the null terminator at the end
    *dest = '\0';
}

int main() {
    char str1[100] = "Hello";
    char str2[] = " World";

    concatenateStrings(str1, str2);
    printf("Concatenated string: %s\n", str1);

    return 0;
}
