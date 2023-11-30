#include <stdio.h>
#include <string.h>

int isPalindrome(char str[]) {
    int length = strlen(str);
    int i = 0;
    int j = length - 1;

    while (i < j) {
        if (str[i] != str[j]) {
            return 0;  // Not a palindrome
        }
        i++;
        j--;
    }

    return 1;  // Palindrome
}

int main() {
    printf("Roll Number: 2k22/A15/25; Name: Suraj Shukla\n");

    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character from the string
    str[strcspn(str, "\n")] = '\0';

    if (isPalindrome(str)) {
        printf("Palindrome\n");
    } else {
        printf("Not a Palindrome\n");
    }

    return 0;
}
