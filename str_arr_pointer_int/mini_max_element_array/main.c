/* In this problem we implementation as the findMinMax function takes an array, its size,
and two pointers to integers (min and max).It traverses the array to find the minimum and
maximum elements,updating the values through the pointers. The main function initializes an array,
calls findMinMax, and then prints the minimum and maximum elements
*/

#include <stdio.h>

void findMinMax(int arr[], int size, int *min, int *max) {
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
    int arr[] = {-1,3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    int min, max;

    // Find the minimum and maximum elements
    findMinMax(arr, size, &min, &max);

    printf("Minimum element: %d\n", min);
    printf("Maximum element: %d\n", max);

    return 0;
}
