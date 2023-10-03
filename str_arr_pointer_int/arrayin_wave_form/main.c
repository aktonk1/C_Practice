#include <stdio.h>
#include <stdlib.h>
qsort(arr, size, sizeof(int), compareIntegers);
// Function to swap two elements in an array
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort the array and convert it into wave form
void sortInWave(int *arr, int size) {
    // Sort the array
    qsort(arr, size, sizeof(int), compareIntegers);

    // Swap adjacent elements to create the wave pattern
    for (int i = 0; i < size - 1; i += 2) {
        swap(arr + i, arr + i + 1);
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

    // Sort the array in wave form
    sortInWave(arr, size);

    // Print the sorted array in wave form
    printf("Array in wave form: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    // Free dynamically allocated memory
    free(arr);

    return 0;
}
