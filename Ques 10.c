#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

bool is_valid(char c) {
    return c == '0' || c == '1'; // Only accept 0 or 1
}

int main() {
    char str[MAX_LENGTH];
    printf("Enter a string: ");
    scanf("%s", str);

    int state = 0; // Start state
    bool accepted = false;
    int i; // Declare loop variable outside the for loop

    for (i = 0; str[i] != '\0'; i++) {
        switch (state) {
            case 0:
                if (str[i] == '0') {
                    state = 1; // Transition to state 1 on '0'
                } else if (str[i] == '1') {
                    state = 2; // Transition to state 2 on '1'
                }
                break;
            case 1:
                if (str[i] == '1') {
                    state = 2; // Transition to state 2 on '1'
                } else if (str[i] == '0') {
                    state = 1; // Stay in state 1 on '0'
                }
                break;
            case 2:
                accepted = true; // Accept on '1'
                state = 2; // Stay in state 2
                break;
            default:
                break;
        }
    }

    if (accepted && state == 2) { // Must end in state 2 after '1'
        printf("String is accepted by the NFA.\n");
    } else {
        printf("String is not accepted by the NFA.\n");
    }

    return 0;
}

