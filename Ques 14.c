#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STATES 3

bool is_valid_char(char c) {
    return c == 'a' || c == 'b';
}

bool simulate_nfa(char *str) {
    int len = strlen(str);
    bool dp[len + 1][MAX_STATES];

    // Initialize the DP table
    memset(dp, false, sizeof(dp));
    dp[0][0] = true; // Start state

    int i, state; // Declare loop variables outside the for loop

    for (i = 0; i < len; i++) {
        char c = str[i];
        if (!is_valid_char(c)) {
            return false; // Invalid character
        }

        for (state = 0; state < MAX_STATES; state++) {
            if (dp[i][state]) {
                switch (state) {
                    case 0:
                        if (c == 'b') {
                            dp[i + 1][1] = true; // Transition to state 1 on 'b'
                        }
                        break;
                    case 1:
                        dp[i + 1][1] = true; // Stay in state 1 on any character
                        if (c == 'a') {
                            dp[i + 1][2] = true; // Transition to state 2 on 'a'
                        }
                        break;
                    case 2:
                        dp[i + 1][2] = true; // Stay in state 2 on any character
                        break;
                }
            }
        }
    }

    return dp[len][2]; // Accept if in state 2 at the end
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    if (simulate_nfa(str)) {
        printf("String is accepted by the NFA.\n");
    } else {
        printf("String is not accepted by the NFA.\n");
    }

    return 0;
}

