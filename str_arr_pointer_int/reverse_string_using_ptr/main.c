/*reverseStringWithoutReversingWords reverses the entire string
 first and then reverses each word individually to maintain the original order of words.*/

#include <stdio.h>
#include <string.h>

// Function to reverse a string without reversing words using pointer
void reverseStringWithoutReversingWords(char *str) {
    // Find the length of the string
    int length = strlen(str);

    // Initialize pointers for the beginning and end of the string
    char *start = str;
    char *end = str + length - 1;

    // Reverse the entire string
    while (start < end) {
        // Swap characters
        char temp = *start;
        *start = *end;
        *end = temp;

        // Move pointers towards the center
        start++;
        end--;
    }

    // Reverse each word individually to maintain word order
    start = str;
    while (*start != '\0') {
        // Find the end of the current word
        char *wordEnd = start;
        while (*wordEnd != ' ' && *wordEnd != '\0') {
            wordEnd++;
        }
        // Move end pointer back by one to point to the last character of the word
        wordEnd--;

        // Reverse the characters of the current word
        while (start < wordEnd) {
            char temp = *start;
            *start = *wordEnd;
            *wordEnd = temp;

            // Move pointers within the word towards the center
            start++;
            wordEnd--;
        }

        // Move start pointer to the next word (or the null terminator if at the end)
        start = wordEnd + 2;
    }
}

int main() {
    // Test case
    char input[] = "all is well";

    // Print the original string
    printf("Original string: %s\n", input);

    // Reverse the string without reversing words using pointer
    reverseStringWithoutReversingWords(input);

    // Print the modified string
    printf("Modified string: %s\n", input);

    return 0;
}
