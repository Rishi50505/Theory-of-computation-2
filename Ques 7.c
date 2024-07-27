#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LENGTH 100

bool is_valid(char str[], int index, char target) {
    return str[index] == target;
}

// Function prototypes
bool match_S(char str[], int index, int length);
bool match_A(char str[], int index, int length);

// Function to match production S -> A101A
bool match_S(char str[], int index, int length) {
    if (length < 5) { // String must be at least 5 characters long (A101A)
        return false;
    }

    if (!match_A(str, index, length)) { // Check for A at the beginning
        return false;
    }

    if (!is_valid(str, index + 1, '1')) { // Check for '1'
        return false;
    }

    if (!is_valid(str, index + 2, '0')) { // Check for '0'
        return false;
    }

    if (!is_valid(str, index + 3, '1')) { // Check for '1'
        return false;
    }

    return match_A(str, index + 4, length); // Check for A at the end
}

// Function to match production A -> 0A | 1A | e (empty string)
bool match_A(char str[], int index, int length) {
    if (index >= length) {
        return true; // Empty string (e) is valid for A
    }

    if (is_valid(str, index, '0')) {
        return match_A(str, index + 1, length); // Check for 0A
    } else if (is_valid(str, index, '1')) {
        return match_A(str, index + 1, length); // Check for 1A
    } else {
        return false; // Invalid symbol for A
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

