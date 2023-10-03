/*
The swap function is used to swap two elements,
and the sortArray function sorts the array using pointers.
The user is prompted to enter the size of the array and the array elements,
and the sorted array is then printed.
The dynamically allocated memory is freed at the end of the program.
*/

#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortArray(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (*(arr + j) > *(arr + j + 1)) {
                // Swap elements if they are in the wrong order
                swap(arr + j, arr + j + 1);
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

    // Sort the array
    sortArray(arr, size);

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }

    // Free dynamically allocated memory
    free(arr);

    return 0;
}
