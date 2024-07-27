#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_STATES 10
#define MAX_SYMBOLS 26 // Assuming symbols are lowercase alphabets

// Structure to represent a transition in the NFA
typedef struct Transition {
    char symbol;
    int to_state;
} Transition;

// Structure to represent a state in the NFA
typedef struct State {
    int id;
    bool is_accepting;
    Transition* transitions; // Array of outgoing transitions
    int num_transitions;     // Number of outgoing transitions
} State;

// Function to create a new state
State* create_state(int id, bool is_accepting) {
    State* state = (State*)malloc(sizeof(State));
    state->id = id;
    state->is_accepting = is_accepting;
    state->transitions = NULL;
    state->num_transitions = 0;
    return state;
}

// Function to add a transition to a state
void add_transition(State* state, char symbol, int to_state) {
    state->transitions = (Transition*)realloc(state->transitions, (state->num_transitions + 1) * sizeof(Transition));
    state->transitions[state->num_transitions].symbol = symbol;
    state->transitions[state->num_transitions].to_state = to_state;
    state->num_transitions++;
}

// Function to mark a state visited in the DFS
void mark_visited(bool* visited, int state_id) {
    visited[state_id] = true;
}

// Function to perform a DFS traversal to find e-closure
void dfs_epsilon_closure(State* nfa[], int num_states, int state_id, bool* visited, int* epsilon_closure) {
    if (visited[state_id]) {
        return;
    }

    mark_visited(visited, state_id);
    epsilon_closure[state_id] = 1;  // Mark the current state as part of the e-closure

    int i; // Declare loop variable outside the for loop
    for (i = 0; i < nfa[state_id]->num_transitions; i++) {
        Transition* transition = &nfa[state_id]->transitions[i];
        if (transition->symbol == '\0') { // e-move transition
            dfs_epsilon_closure(nfa, num_states, transition->to_state, visited, epsilon_closure);
        }
    }
}

// Function to calculate e-closure for a state
int* find_epsilon_closure(State* nfa[], int num_states, int state_id) {
    bool visited[MAX_STATES] = {false};
    int* epsilon_closure = (int*)calloc(num_states, sizeof(int));

    dfs_epsilon_closure(nfa, num_states, state_id, visited, epsilon_closure);

    return epsilon_closure;
}

int main() {
    // Example NFA (modify as needed)
    int num_states = 3;
    State* nfa[MAX_STATES];
    nfa[0] = create_state(0, false);
    nfa[1] = create_state(1, false);
    nfa[2] = create_state(2, true);

    add_transition(nfa[0], 'a', 1);
    add_transition(nfa[0], '\0', 2);
    add_transition(nfa[1], 'b', 2);
    add_transition(nfa[1], '\0', 1);

    // Find e-closure for state 0
    int* closure = find_epsilon_closure(nfa, num_states, 0);

    printf("e-closure of state 0: {");
    int i; // Declare loop variable outside the for loop
    for (i = 0; i < num_states; i++) {
        if (closure[i]) {
            printf("%d ", i);
        }
    }
    printf("}\n");

    // Free allocated memory
    free(closure);
    for (i = 0; i < num_states; i++) {
        free(nfa[i]->transitions);
        free(nfa[i]);
    }

    return 0;
}

