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

// Function to match production S -> 0A1
bool match_S(char str[], int index, int length) {
    if (index >= length) {
        return false; // Reached end of string without matching
    }

    if (is_valid(str, index, '0')) {
        if (index + 2 < length && is_valid(str, index + 2, '1')) {
            return match_A(str, index + 1, length - 2); // Check for 0A1
        } else {
            return false; // Invalid 0 without A1
        }
    } else {
        return match_A(str, index, length); // Check for production A
    }
}

// Function to match production A -> 1A | e (empty string)
bool match_A(char str[], int index, int length) {
    if (index >= length) {
        return true; // Empty string (e) is valid for A
    }

    if (is_valid(str, index, '1')) {
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

