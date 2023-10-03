/*
findUnion and findIntersection, that find and print the union and
intersection of two sorted arrays, respectively. The main function
 prompts the user to input the sizes and elements of the two arrays
 and then calls these functions.
*/

#include <stdio.h>
#include <stdlib.h>

// Function to find the union of two sorted arrays using pointers
int findUnion(int *arr1, int size1, int *arr2, int size2) {
    int i = 0, j = 0;

    // Print elements of both arrays that are not common
    while (i < size1 && j < size2) {
        if (*(arr1 + i) < *(arr2 + j)) {
            printf("%d ", *(arr1 + i));
            i++;
        } else if (*(arr2 + j) < *(arr1 + i)) {
            printf("%d ", *(arr2 + j));
            j++;
        } else {
            // Elements are equal, print one and move both pointers
            printf("%d ", *(arr1 + i));
            i++;
            j++;
        }
    }

    // Print the remaining elements of the larger array
    while (i < size1) {
        printf("%d ", *(arr1 + i));
        i++;
    }

    while (j < size2) {
        printf("%d ", *(arr2 + j));
        j++;
    }

    printf("\n");
}

// Function to find the intersection of two sorted arrays using pointers
void findIntersection(int *arr1, int size1, int *arr2, int size2) {
    int i = 0, j = 0;

    // Print common elements of both arrays
    while (i < size1 && j < size2) {
        if (*(arr1 + i) < *(arr2 + j)) {
            i++;
        } else if (*(arr2 + j) < *(arr1 + i)) {
            j++;
        } else {
            // Elements are equal, print one and move both pointers
            printf("%d ", *(arr1 + i));
            i++;
            j++;
        }
    }

    printf("\n");
}

int main() {
    int size1, size2;

    // Get the size of the first array from the user
    printf("Enter the size of the first array: ");
    scanf("%d", &size1);

    // Dynamically allocate memory for the first array
    int *arr1 = (int *)malloc(size1 * sizeof(int));

    // Get elements of the first array from the user
    printf("Enter the elements of the first array (sorted):\n");
    for (int i = 0; i < size1; i++) {
        scanf("%d", arr1 + i);
    }

    // Get the size of the second array from the user
    printf("Enter the size of the second array: ");
    scanf("%d", &size2);

    // Dynamically allocate memory for the second array
    int *arr2 = (int *)malloc(size2 * sizeof(int));

    // Get elements of the second array from the user
    printf("Enter the elements of the second array (sorted):\n");
    for (int i = 0; i < size2; i++) {
        scanf("%d", arr2 + i);
    }

    // Find and print the union of the two arrays
    printf("Union of the arrays: ");
    findUnion(arr1, size1, arr2, size2);

    // Find and print the intersection of the two arrays
    printf("Intersection of the arrays: ");
    findIntersection(arr1, size1, arr2, size2);

    // Free dynamically allocated memory
    free(arr1);
    free(arr2);

    return 0;
}
