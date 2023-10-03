#include <stdio.h>

// Function to find the missing integer in an array
int findMissingInteger(int *arr, int size, int n) {
    // Calculate the sum of integers from 1 to N
    int sumOfN = n * (n + 1) / 2;

    // Calculate the sum of elements in the array
    int sumOfElements = 0;
    for (int i = 0; i < size; i++) {
        sumOfElements += *(arr + i);
    }

    // The difference is the missing integer
    return sumOfN - sumOfElements;
}

int main() {
    int size, n;

    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Dynamically allocate memory for the array
    int *arr = (int *)malloc(size * sizeof(int));

    // Get array elements from the user
    printf("Enter the elements of the array (from 1 to N-1):\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", arr + i);
    }

    // Get the value of N from the user
    printf("Enter the value of N: ");
    scanf("%d", &n);

    // Find and print the missing integer
    int missingInteger = findMissingInteger(arr, size, n);
    printf("Missing Integer: %d\n", missingInteger);

    // Free dynamically allocated memory
    free(arr);

    return 0;
}
