/*
partition and quicksort. The partition function takes the last element
 of the array as the pivot, places the pivot element in its correct position,
 and partitions the array into two subarrays. The quicksort function recursively
 sorts the subarrays. The main function prompts the user to input the
 size and elements of the array, then calls the quicksort function and prints the sorted array.

*/

#include <stdio.h>

// Function to partition the array and return the pivot index
int partition(int *arr, int low, int high) {
    int pivot = *(arr + high);
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (*(arr + j) <= pivot) {
            // Swap arr[i+1] and arr[j]
            i++;
            int temp = *(arr + i);
            *(arr + i) = *(arr + j);
            *(arr + j) = temp;
        }
    }

    // Swap arr[i+1] and arr[high] (put the pivot in its correct place)
    int temp = *(arr + i + 1);
    *(arr + i + 1) = *(arr + high);
    *(arr + high) = temp;

    return i + 1;
}

// Function to implement the Quicksort algorithm
void quicksort(int *arr, int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pivotIndex = partition(arr, low, high);

        // Recursively sort the subarrays before and after the pivot
        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
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

    // Sort the array using Quicksort
    quicksort(arr, 0, size - 1);

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }

    // Free dynamically allocated memory
    free(arr);

    return 0;
}
