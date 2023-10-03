/*Find a peak element which is not smaller than its neighbors
analysis:

*/

#include <stdio.h>
#include <stdlib.h>


int findPeakElement(int arr[], int size) {
    for (int i = 1; i < size - 1; i++) {
        if (arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1]) {
            return i; // i is a peak element
        }
    }
    return -1; // No peak element found
}

int main() {
    int arr[] = {1, 3, 20, 48, 1, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    int peakIndex = findPeakElement(arr, size);

    if (peakIndex != -1) {
        printf("Peak element without pointer: %d\n", arr[peakIndex]);
    } else {
        printf("No peak element found\n");
    }

    return 0;
}
