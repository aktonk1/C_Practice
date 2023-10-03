/*
findOccurrence function uses pointer arithmetic to iterate through the array
and count the occurrences of the target integer. The user is prompted to
enter the size of the array, the array elements, and the target integer.
The program then finds and prints the occurrence of the target integer in the array.*/


#include <stdio.h>

// Function to find the occurrence of an integer in the array using pointer
int findOccurrence(int *arr, int size, int target) {
    int count = 0;

    for (int i = 0; i < size; i++) {
        // Check if the current element is equal to the target
        if (*(arr + i) == target) {
            count++;
        }
    }

    return count;
}

int main() {
    int size, target;

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

    // Get the target integer from the user
    printf("Enter the integer to find occurrences: ");
    scanf("%d", &target);

    // Find and print the occurrence of the target integer
    int occurrence = findOccurrence(arr, size, target);
    printf("The integer %d occurs %d times in the array.\n", target, occurrence);

    // Free dynamically allocated memory
    free(arr);

    return 0;
}
