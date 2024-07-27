#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LENGTH 100

bool is_valid(char str[], int index, char target) {
    return str[index] == target;
}

// Function prototypes
bool match_S(char str[], int index, int length);

// Function to match production S -> 0S1
bool match_S(char str[], int index, int length) {
    if (index >= length) {
        return true; // Empty string (e) is valid
    }

    // Check for S -> 0S1 production
    if (is_valid(str, index, '0')) {
        if (index + 2 < length && is_valid(str, index + 2, '1')) {
            return match_S(str, index + 1, length - 2); // Check for 0S1
        } else {
            return false; // Invalid 0 without S1
        }
    }

    // No need to check for other characters here, as
    // the CFG only allows '0' or the empty string for S.

    return true; // Single character (empty string) is also valid
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

