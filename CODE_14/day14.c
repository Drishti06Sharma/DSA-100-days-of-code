/*Problem: Write a program to check whether a given square matrix is an Identity Matrix. An identity matrix is a square matrix in which all diagonal elements are 1 and all non-diagonal elements are 0.

Input:
- First line: integer n representing number of rows and columns
- Next n lines: n integers each representing the matrix elements

Output:
- Print "Identity Matrix" if the matrix satisfies the condition
- Otherwise, print "Not an Identity Matrix"

Example:
Input:
3
1 0 0
0 1 0
0 0 1

Output:
Identity Matrix*/
#include <stdio.h>
#include <stdlib.h>

/* Function to return spiral order */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {

    int rows = matrixSize;
    int cols = matrixColSize[0];

    *returnSize = rows * cols;

    int* result = (int*)malloc((*returnSize) * sizeof(int));

    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;
    int index = 0;

    while (top <= bottom && left <= right) {

        // Top row
        for (int i = left; i <= right; i++)
            result[index++] = matrix[top][i];
        top++;

        // Right column
        for (int i = top; i <= bottom; i++)
            result[index++] = matrix[i][right];
        right--;

        // Bottom row
        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                result[index++] = matrix[bottom][i];
            bottom--;
        }

        // Left column
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                result[index++] = matrix[i][left];
            left++;
        }
    }

    return result;
}


/* Main function (required for GCC) */
int main() {

    int r, c;
    scanf("%d %d", &r, &c);

    // Allocate matrix dynamically
    int** matrix = (int**)malloc(r * sizeof(int*));
    for (int i = 0; i < r; i++) {
        matrix[i] = (int*)malloc(c * sizeof(int));
    }

    // Input matrix
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &matrix[i][j]);

    int returnSize;
    int colSize = c;

    int* result = spiralOrder(matrix, r, &colSize, &returnSize);

    // Print spiral order
    for (int i = 0; i < returnSize; i++)
        printf("%d ", result[i]);

    printf("\n");

    // Free memory
    free(result);
    for (int i = 0; i < r; i++)
        free(matrix[i]);
    free(matrix);

    return 0;
}
