/*
 we implemented simple sorting logic (bubble sort) directly in the
 functions to find the Kth smallest and Kth largest numbers without
 using function pointers. The rest of the program structure remains similar to the previous one.*/

#include <stdio.h>
#include <stdlib.h>

// Function to find Kth smallest number using pointer
int findKthSmallest(int *arr, int size, int k) {
    // Sort the array in ascending order
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (*(arr + j) > *(arr + j + 1)) {
                // Swap elements if they are in the wrong order
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }

    // Return the Kth smallest number
    return *(arr + k - 1);
}

// Function to find Kth largest number using pointer
int findKthLargest(int *arr, int size, int k) {
    // Sort the array in descending order
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (*(arr + j) < *(arr + j + 1)) {
                // Swap elements if they are in the wrong order
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }

    // Return the Kth largest number
    return *(arr + k - 1);
}

int main() {
    int size, k;

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

    // Get the value of K from the user
    printf("Enter the value of K: ");
    scanf("%d", &k);

    // Find and print the Kth smallest and Kth largest numbers
    printf("Kth smallest number: %d\n", findKthSmallest(arr, size, k));
    printf("Kth largest number: %d\n", findKthLargest(arr, size, k));

    // Free dynamically allocated memory
    free(arr);

    return 0;
}
