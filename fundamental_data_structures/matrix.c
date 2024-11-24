#include <stdio.h>

int main() {
    float matrix[3][3];
    float *matrix_pointer;
    int i, j;

    matrix_pointer = &matrix[0][0];

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Enter the value for position [%d][%d]: ", i, j);
            scanf("%f", (matrix_pointer + i * 3 + j));
        }
    }

    printf("\n\nMATRIX RESULT:\n");

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("\nValue at position [%d][%d] = %f", i, j, *(matrix_pointer + i * 3 + j));
            printf("\nAddress of position [%d][%d] = %p\n", i, j, (void *)(matrix_pointer + i * 3 + j));
        }
    }
    return 0;
}
