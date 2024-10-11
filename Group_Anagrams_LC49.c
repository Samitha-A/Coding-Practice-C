#include <stdio.h>
#include <string.h>

// Function to check if two strings are anagrams
int isAnagram(char* str1, char* str2) {
    int charCount[256] = {0};  // ASCII character frequency array

    // If lengths differ, they can't be anagrams
    if (strlen(str1) != strlen(str2))
        return 0;

    // Count character frequencies for both strings
    for (int i = 0; i < strlen(str1); i++) {
        charCount[str1[i]]++;  // Increment for str1
        charCount[str2[i]]--;  // Decrement for str2
    }

    // Check if all counts are zero (i.e., all characters match)
    for (int i = 0; i < 256; i++) {
        if (charCount[i] != 0)
            return 0;
    }

    return 1;
}

int main() {
    int n;
    scanf("%d", &n);  // Number of strings
    char str[n][100]; // Array to store strings
    int processed[100] = {0};  // Array to mark processed strings

    // Read strings from input
    for (int i = 0; i < n; i++) {
        scanf("%s", str[i]);
    }

    // Group anagrams
    for (int i = 0; i < n; i++) {
        if (processed[i] == 0) {  // If string not already processed
            printf("%s ", str[i]); // Print the current string
            processed[i] = 1;      // Mark as processed

            // Find and print anagrams of the current string
            for (int j = i + 1; j < n; j++) {
                if (processed[j] == 0 && isAnagram(str[i], str[j])) {
                    printf("%s ", str[j]);  // Print the anagram
                    processed[j] = 1;       // Mark as processed
                }
            }
            printf("\n");  // Move to the next line after printing a group
        }
    }

    return 0;
}
