#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to check if the string belongs to the language defined by A
bool is_valid_A(const char *str, int *index) {
    while (str[*index] == 'a' || str[*index] == 'b') {
        (*index)++;
    }
    return true;
}

// Function to check if the string belongs to the language defined by S
bool is_valid_S(const char *str) {
    int len = strlen(str);
    if (len < 3) {
        return false; // Minimum length for S ? aAb is 3
    }

    int index = 0;
    if (str[index] != 'a') {
        return false; // String must start with 'a'
    }
    index++;

    if (!is_valid_A(str, &index)) {
        return false;
    }

    if (str[index] != 'b') {
        return false; // String must end with 'b'
    }
    index++;

    return index == len; // Ensure the entire string is consumed
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    if (is_valid_S(str)) {
        printf("String belongs to the language defined by the CFG.\n");
    } else {
        printf("String does not belong to the language defined by the CFG.\n");
    }

    return 0;
}

