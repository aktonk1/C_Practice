/*
printSpiral function takes a matrix and its dimensions and
prints its elements in a spiral order. The main function prompts the
user to input the number of rows, columns, and matrix elements.
It then calls the printSpiral function to print the matrix in a spiral manner.*/

#include <stdio.h>

// Function to print matrix in a spiral manner
void printSpiral(int *matrix, int rows, int cols) {
    int top = 0, bottom = rows - 1, left = 0, right = cols - 1;

    while (top <= bottom && left <= right) {
        // Print top row
        for (int i = left; i <= right; i++) {
            printf("%d ", *((matrix + top * cols) + i));
        }
        top++;

        // Print right column
        for (int i = top; i <= bottom; i++) {
            printf("%d ", *((matrix + i * cols) + right));
        }
        right--;

        // Print bottom row
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                printf("%d ", *((matrix + bottom * cols) + i));
            }
            bottom--;
        }

        // Print left column
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                printf("%d ", *((matrix + i * cols) + left));
            }
            left++;
        }
    }
}

int main() {
    int rows, cols;

    // Get the number of rows and columns from the user
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Dynamically allocate memory for the matrix
    int *matrix = (int *)malloc(rows * cols * sizeof(int));

    // Get matrix elements from the user
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", (matrix + i * cols) + j);
        }
    }

    // Print matrix in a spiral manner
    printf("Matrix in a spiral manner:\n");
    printSpiral(matrix, rows, cols);

    // Free dynamically allocated memory
    free(matrix);

    return 0;
}
