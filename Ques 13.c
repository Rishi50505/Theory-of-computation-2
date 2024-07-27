#include <stdio.h>
#include <stdbool.h>

bool is_valid_char(char c) {
    return c == 'a' || c == 'b';
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    int state = 0; // Start state
    int i; // Declare the loop variable outside the for loop

    for (i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        if (!is_valid_char(c)) {
            state = 3; // Move to reject state if invalid character
            break;
        }

        switch (state) {
            case 0:
                if (c == 'a') {
                    state = 1; // Transition to state 1 on 'a'
                } else {
                    state = 3; // Reject if it doesn't start with 'a'
                }
                break;
            case 1:
                if (c == 'a') {
                    state = 1; // Stay in state 1 on 'a'
                } else if (c == 'b') {
                    state = 2; // Transition to state 2 on 'b'
                } else {
                    state = 3; // Reject on any other character
                }
                break;
            case 2:
                if (c == 'b') {
                    state = 2; // Stay in state 2 on 'b'
                } else {
                    state = 3; // Reject on any other character
                }
                break;
            case 3:
                // Stay in reject state
                break;
        }
    }

    if (state == 2) {
        printf("String is accepted by the DFA.\n");
    } else {
        printf("String is not accepted by the DFA.\n");
    }

    return 0;
}

