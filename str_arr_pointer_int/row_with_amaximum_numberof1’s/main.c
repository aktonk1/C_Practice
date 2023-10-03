/*
findRowWithMaxOnes function takes a binary matrix and its dimensions,
iterates through each row, and counts the number of 1's in each row. It
keeps track of the row with the maximum number of 1's. The main function
prompts the user to input the number of rows, columns, and matrix elements
and then calls the findRowWithMaxOnes function to print the result.
*/

#include <stdio.h>
#include <stdlib.h>

// Function to find the row with the maximum number of 1's in a binary matrix
int findRowWithMaxOnes(int *matrix, int rows, int cols) {
    int maxOnesRow = -1;  // Initialize to an invalid value
    int maxOnesCount = 0;

    for (int i = 0; i < rows; i++) {
        int onesCount = 0;

        // Count the number of 1's in the current row
        for (int j = 0; j < cols; j++) {
            onesCount += *((matrix + i * cols) + j);
        }

        // Update the row with maximum 1's count
        if (onesCount > maxOnesCount) {
            maxOnesCount = onesCount;
            maxOnesRow = i;
        }
    }

    return maxOnesRow;
}

int main() {
    int rows, cols;

    // Get the number of rows and columns from the user
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Dynamically allocate memory for the binary matrix
    int *matrix = (int *)malloc(rows * cols * sizeof(int));

    // Get matrix elements from the user
    printf("Enter the elements of the binary matrix (0 or 1):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", (matrix + i * cols) + j);
        }
    }

    // Find and print the row with the maximum number of 1's
    int maxOnesRow = findRowWithMaxOnes(matrix, rows, cols);
    printf("Row with maximum number of 1's: %d\n", maxOnesRow);

    // Free dynamically allocated memory
    free(matrix);

    return 0;
}
