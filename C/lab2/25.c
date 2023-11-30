#include <stdio.h>

void addMatrices(int mat1[][3], int mat2[][3], int result[][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void displayMatrix(int matrix[][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Roll Number: 2k22/A15/25; Name: Suraj Shukla\n");

    int mat1[3][3];
    int mat2[3][3];
    int result[3][3];

    printf("Enter the elements of the first matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("Enter the elements of the second matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    addMatrices(mat1, mat2, result);

    printf("Resultant matrix after addition:\n");
    displayMatrix(result);

    return 0;
}
