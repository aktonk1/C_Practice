/*
sort012 that sorts an array of 0s, 1s, and 2s in-place using
three pointers (low, mid, and high).The main function prompts
the user to input the size of the array and the elements,
 then it calls the sort012 function and prints the sorted array.
*/

#include <stdio.h>
#include <stdlib.h>


// Function to sort an array of 0s, 1s, and 2s using pointers
void sort012(int *arr, int size) {
    int low = 0, mid = 0, high = size - 1;

    while (mid <= high) {
        switch (arr[mid]) {
            case 0:
                // Swap arr[low] and arr[mid], move both pointers to the right
                {
                    int temp = arr[low];
                    arr[low] = arr[mid];
                    arr[mid] = temp;
                    low++;
                    mid++;
                }
                break;

            case 1:
                // No swap needed, move mid pointer to the right
                mid++;
                break;

            case 2:
                // Swap arr[mid] and arr[high], move high pointer to the left
                {
                    int temp = arr[mid];
                    arr[mid] = arr[high];
                    arr[high] = temp;
                    high--;
                }
                break;
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
    printf("Enter the elements of the array (0s, 1s, and 2s):\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", arr + i);
    }

    // Sort the array of 0s, 1s, and 2s using pointers
    sort012(arr, size);

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    // Free dynamically allocated memory
    free(arr);

    return 0;
}
