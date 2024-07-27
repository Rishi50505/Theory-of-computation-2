#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

bool is_valid(char c) {
    return c == 'b' || c == 'a' || (c >= 'c' && c <= 'z'); // Accept any character except 'a' at the beginning
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
                if (str[i] == 'b') {
                    state = 1; // Transition to state 1 on 'b'
                } else {
                    state = 0; // Stay in state 0 on any other character
                }
                break;
            case 1:
                if (str[i] == 'a') {
                    state = 2; // Transition to state 2 on 'a'
                } else {
                    state = 1; // Stay in state 1 on any character except 'a'
                }
                break;
            case 2:
                accepted = true; // Accept on 'a'
                state = 2; // Stay in state 2
                break;
            default:
                break;
        }
    }

    if (accepted && state == 2) { // Must end in state 2 after 'a'
        printf("String is accepted by the NFA.\n");
    } else {
        printf("String is not accepted by the NFA.\n");
    }

    return 0;
}

