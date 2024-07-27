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

// Function to check if the string belongs to the language defined by A
bool is_valid_string(const char *str) {
    int index = 0;
    return is_valid_A(str, &index) && str[index] == '\0';
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    if (is_valid_string(str)) {
        printf("String belongs to the language defined by the CFG.\n");
    } else {
        printf("String does not belong to the language defined by the CFG.\n");
    }

    return 0;
}

