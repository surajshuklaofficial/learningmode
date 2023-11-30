#include <stdio.h>
#include <ctype.h>

int main() {
    printf("Roll Number: 2k22/A15/25; Name: Suraj Shukla\n");

    FILE *sourceFile, *targetFile;
    char character;

    sourceFile = fopen("source.txt", "r");
    targetFile = fopen("target.txt", "w");

    if (sourceFile == NULL || targetFile == NULL) {
        printf("Failed to open files.\n");
        return 1;
    }

    while ((character = fgetc(sourceFile)) != EOF) {
        if (islower(character)) {
            character = toupper(character);
        }
        fputc(character, targetFile);
    }

    fclose(sourceFile);
    fclose(targetFile);

    printf("File contents modified and written to target file successfully.\n");

    return 0;
}
