/*
findSubarrayWithSum function uses nested loops to iterate through
all possible subarrays. The outer loop selects the starting index of the subarray, and the
inner loop iterates from that index to find the sum of subarrays.
If the sum matches the target sum, it prints the indices of the subarray.

*/

#include <stdio.h>
#include <stdlib.h>


// Function to find subarray with given sum using nested loops
void findSubarrayWithSum(int arr[], int size, int targetSum) {
    for (int start = 0; start < size; start++) {
        int currentSum = 0;

        for (int end = start; end < size; end++) {
            currentSum += arr[end];

            if (currentSum == targetSum) {
                // Subarray found, print indices
                printf("Subarray with sum %d found from index %d to %d\n", targetSum, start, end);
                return;
            }
        }
    }

    // If no subarray is found
    printf("No subarray with sum %d found\n", targetSum);
}

int main() {
    int size, targetSum;

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

    // Get the target sum from the user
    printf("Enter the target sum: ");
    scanf("%d", &targetSum);

    // Find and print the subarray with the given sum using nested loops
    findSubarrayWithSum(arr, size, targetSum);

    // Free dynamically allocated memory
    free(arr);

    return 0;
}
