/*
compareIntegers function is used as a comparison function for qsort to
sort the array. The findLongestConsecutiveSubsequence function then iterates
through the sorted array to find the longest consecutive subsequence. The main
function prompts the user to input the size and elements of the array and then
calls the findLongestConsecutiveSubsequence function to print the result.
*/

#include <stdio.h>
#include <stdlib.h>

// Function to compare integers for qsort
int compareIntegers(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to find the longest consecutive subsequence in an array using pointers
void findLongestConsecutiveSubsequence(int *arr, int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }

    // Sort the array
    qsort(arr, size, sizeof(int), compareIntegers);

    // Find the longest consecutive subsequence
    int longestLength = 1, currentLength = 1;
    int *startPtr = arr;  // Pointer to the beginning of the current subsequence

    for (int i = 1; i < size; i++) {
        if (*(arr + i) == *(arr + i - 1) + 1) {
            // Increment the length of the current consecutive subsequence
            currentLength++;

            // Update the longest length if needed
            if (currentLength > longestLength) {
                longestLength = currentLength;
            }
        } else if (*(arr + i) != *(arr + i - 1)) {
            // Reset the length and update the start pointer for a new subsequence
            currentLength = 1;
            startPtr = arr + i;
        }
    }

    // Print the longest consecutive subsequence
    printf("Longest consecutive subsequence: ");
    for (int i = 0; i < longestLength; i++) {
        printf("%d ", *(startPtr + i));
    }
    printf("\n");
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

    // Find and print the longest consecutive subsequence
    findLongestConsecutiveSubsequence(arr, size);

    // Free dynamically allocated memory
    free(arr);

    return 0;
}
