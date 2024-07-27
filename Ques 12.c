#include <stdbool.h>
#include <stdio.h>

#define MAX_STATES 3

bool is_valid(char c) {
    return c != 'b'; // Any character except 'b'
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    int state = 0; // Start state
    int i; // Declare the loop variable outside the for loop

    for (i = 0; str[i] != '\0'; i++) {
        if (state == 0) {
            if (str[i] == 'b') {
                state = 1; // Transition to state 1 on 'b'
            } else {
                break; // String can't be accepted if it doesn't start with 'b'
            }
        } else if (state == 1) {
            if (is_valid(str[i])) {
                // Stay in state 1 on any character except 'b'
            } else if (str[i] == 'b') {
                state = 2; // Transition to accepting state on final 'b'
            } else {
                break; // String can't be accepted after a character other than 'b'
            }
        } else if (state == 2) {
            if (str[i] == 'b') {
                // Stay in state 2 on 'b'
            } else {
                state = 1; // Transition back to state 1 on any character except 'b'
            }
        }
    }

    if (state == 2) {
        printf("String is accepted by the DFA.\n");
    } else {
        printf("String is not accepted by the DFA.\n");
    }

    return 0;
}

