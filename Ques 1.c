#include <stdio.h>

#define MAX_STATE 2

int main() {
    int current_state = 0;  // Initial state

    char input_string[100];
    printf("Enter a string: ");
    scanf("%s", input_string);

    int i;
    for (i = 0; input_string[i] != '\0'; i++) {
        char symbol = input_string[i];

        if (current_state == 0) {
            if (symbol == 'a') {
                current_state = 1;  // Transition to accepting state
            } else {
                printf("String rejected: Not starting with 'a'\n");
                return 1;
            }
        } else if (current_state == 1) {
            if (symbol != 'a') {
                break;  // Any symbol other than 'a' breaks the condition
            }
        } else {
            printf("String rejected: Unexpected state\n");
            return 1;
        }
    }

    // Check if the string ends with 'a' and is in the accepting state
    if (current_state == 1 && input_string[i - 1] == 'a') {
        printf("String accepted!\n");
    } else {
        printf("String rejected: Not ending with 'a' or invalid transition\n");
    }

    return 0;
}
