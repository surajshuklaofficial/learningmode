#include <stdio.h>

int countVowels(char str[]) {
    int count = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
            str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
            count++;
        }
        i++;
    }

    return count;
}

int main() {
    printf("Roll Number: 2k22/A15/25; Name: Suraj Shukla\n");

    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    int vowelCount = countVowels(str);

    printf("Number of vowels: %d\n", vowelCount);

    return 0;
}
