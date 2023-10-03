/*
moveNegativesToOneSide function iterates through the array,
and whenever a negative element is encountered, it swaps it with the
element at the negIndex. The negIndex is then incremented to move to
the next position.This process effectively moves all negative elements
to one side while maintaining the order of other elements.
*/

#include <stdio.h>
#include <stdio.h>

// Function to move negative elements to one side of the array
void moveNegativesToOneSide(int arr[], int size) {
    int negIndex = 0;

    // Traverse the array
    for (int i = 0; i < size; i++) {
        // If the current element is negative, swap it with the element at negIndex
        if (arr[i] < 0) {
            // Swap elements
            int temp = arr[i];
            arr[i] = arr[negIndex];
            arr[negIndex] = temp;

            // Move the negative index to the next position
            negIndex++;
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

    // Move negative elements to one side of the array
    moveNegativesToOneSide(arr, size);

    // Print the modified array
    printf("Array after moving negative elements to one side: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    // Free dynamically allocated memory
    free(arr);

    return 0;
}
