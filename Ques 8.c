#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LENGTH 100

bool is_valid(char str[], int index, char target) {
    return str[index] == target;
}

// Function to match production S -> aS | e (empty string)
bool match_S(char str[], int index, int length) {
    if (index >= length) {
        return true; // Empty string (e) is valid
    }

    if (is_valid(str, index, 'a')) {
        return match_S(str, index + 1, length); // Check for aS
    } else {
        return false; // Invalid character for S
    }
}

int main() {
    char str[MAX_LENGTH];
    printf("Enter a string: ");
    scanf("%s", str);

    int length = strlen(str);

    if (match_S(str, 0, length)) {
        printf("String belongs to the language defined by the CFG.\n");
    } else {
        printf("String does not belong to the language defined by the CFG.\n");
    }

    return 0;
}

