#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STATES 5

bool is_valid_char(char c) {
    return c == '0' || c == '1';
}

bool simulate_nfa(const char *str) {
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
                        if (c == '0') {
                            dp[i + 1][1] = true; // Transition to state 1 on '0'
                        }
                        break;
                    case 1:
                        if (c == '0') {
                            dp[i + 1][2] = true; // Transition to state 2 on '0'
                        }
                        break;
                    case 2:
                        dp[i + 1][2] = true; // Stay in state 2 on any character except '1'
                        if (c == '1') {
                            dp[i + 1][3] = true; // Transition to state 3 on '1'
                        }
                        break;
                    case 3:
                        if (c == '1') {
                            dp[i + 1][3] = true; // Stay in state 3 on '1'
                        } else {
                            dp[i + 1][4] = true; // Transition to reject state on any character except '1'
                        }
                        break;
                    case 4:
                        dp[i + 1][4] = true; // Stay in reject state
                        break;
                }
            }
        }
    }

    return dp[len][3]; // Accept if in state 3 at the end
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

