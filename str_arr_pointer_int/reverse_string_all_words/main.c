/*
reverseString that takes a string as input and reverses it using pointers.
 The main function includes a test case where the input string is "all is well,"
 and the program prints the original and reversed strings.
 */

#include <stdio.h>
#include <string.h>

// Function to reverse a string using pointer
void reverseString(char *str) {
    // Find the length of the string
    int length = strlen(str);

    // Initialize pointers for the beginning and end of the string
    char *start = str;
    char *end = str + length - 1;

    // Swap characters using pointers until they meet in the middle
    while (start < end) {
        // Swap characters
        char temp = *start;
        *start = *end;
        *end = temp;

        // Move pointers towards the center
        start++;
        end--;
    }
}

int main() {
    // Test case
    char input[] = "all is well";

    // Print the original string
    printf("Original string: %s\n", input);

    // Reverse the string using pointer
    reverseString(input);

    // Print the reversed string
    printf("Reversed string: %s\n", input);

    return 0;
}
