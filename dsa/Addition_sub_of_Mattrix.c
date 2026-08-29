#include <stdio.h>

int main() {
    int A[2][2], B[2][2], add[2][2], sub[2][2], mul[2][2];
    int i, j, k;

    // Input Matrix A
    printf("Enter elements of Matrix A:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Input Matrix B
    printf("Enter elements of Matrix B:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Addition and Subtraction
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            add[i][j] = A[i][j] + B[i][j];
            sub[i][j] = A[i][j] - B[i][j];
        }
    }

    // Multiplication
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            mul[i][j] = 0;

            for (k = 0; k < 2; k++) {
                mul[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Display Addition
    printf("\nAddition:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d ", add[i][j]);
        }
        printf("\n");
    }

    // Display Subtraction
    printf("\nSubtraction:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d ", sub[i][j]);
        }
        printf("\n");
    }

    // Display Multiplication
    printf("\nMultiplication:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d ", mul[i][j]);
        }
        printf("\n");
    }

    return 0;
}