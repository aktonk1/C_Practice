/*A sub_array with a given sum using the sliding window technique
findSubarrayWithSum function uses the sliding window technique to
find a subarray with the given sum. The user is prompted to enter
the size of the array, the array elements, and the target sum.
The program then finds and prints the subarray with the given
sum using the sliding window approach.
*/


#include <stdio.h>

// Function to find subarray with given sum using sliding window
void findSubarrayWithSum(int arr[], int size, int targetSum) {
    int start = 0;
    int end = 0;
    int currentSum = arr[0];

    while (end < size) {
        if (currentSum == targetSum) {
            // Subarray found, print indices
            printf("Subarray with sum %d found from index %d to %d\n", targetSum, start, end);
            return;
        } else if (currentSum < targetSum) {
            // Expand the window by moving end to the right
            end++;
            currentSum += arr[end];
        } else {
            // Shrink the window by moving start to the right
            currentSum -= arr[start];
            start++;
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

    // Find and print the subarray with the given sum
    findSubarrayWithSum(arr, size, targetSum);

    // Free dynamically allocated memory
    free(arr);

    return 0;
}
