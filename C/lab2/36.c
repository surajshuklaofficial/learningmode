#include <stdio.h>

int main() {
    printf("Roll Number: 2k22/A15/25; Name: Suraj Shukla\n");

    FILE *file;
    long size;

    file = fopen("source.txt", "rb");

    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    size = ftell(file);

    fclose(file);

    printf("Size of the file: %ld bytes\n", size);

    return 0;
}
