/*
This program implementation shows like the user to enter the size of the array and the
array elements. It dynamically allocates memory for the array, finds the minimum and
maximum elements using pointers, and then frees the allocated memory.
*/


#include <stdio.h>
#include <stdlib.h>

void findMinMax(int *arr, int size, int *min, int *max) {
    // Initialize min and max with the first element
    *min = arr[0];
    *max = arr[0];

    // Traverse the array to find min and max
    for (int i = 1; i < size; i++) {
        if (arr[i] < *min) {
            *min = arr[i];  // Update min if current element is smaller
        } else if (arr[i] > *max) {
            *max = arr[i];  // Update max if current element is larger
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
        scanf("%d", &arr[i]);
    }

    int min, max;

    // Find the minimum and maximum elements
    findMinMax(arr, size, &min, &max);

    printf("Minimum element: %d\n", min);
    printf("Maximum element: %d\n", max);

    // Free dynamically allocated memory
    free(arr);

    return 0;
}
