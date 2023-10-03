/*
findDuplicates function uses nested loops to compare each element
 with every other element in the array. If a duplicate is found,
 it prints the duplicate element. The main function prompts the user
 to input the size and elements of the array and then calls the findDuplicates function.
 */

#include <stdio.h>
#include <stdlib.h>

// Function to find duplicates in an array using pointers
void findDuplicates(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (*(arr + i) == *(arr + j)) {
                // Duplicate found
                printf("Duplicate: %d\n", *(arr + i));
            }
        }
    }
}

int main() {
    int size;

    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Dynamically allocate memory for the array
    int *arr = (int *)malloc(size * sizeof(int));

    // Get array elements from the user
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", arr + i);
    }

    // Find and print duplicates in the array
    findDuplicates(arr, size);

    // Free dynamically allocated memory
    free(arr);

    return 0;
}
