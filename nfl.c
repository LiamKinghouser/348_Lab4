#include <stdio.h>

// Scorign plays and corresponding names
int plays[] = {8, 7, 6, 3, 2};
char *playNames[] = {"TD + 2pt", "TD + FG", "TD", "3pt FG", "Safety"};

// Recursive function to find all combinations of scoring plays for a target score
void findCombinations(int score, int index, int combination[]) {
    // Base case: score is 0
    if (score == 0) {
        // Print the current combination
        for (int i = 0; i < 5; i++) {
            if (i > 0) {
                printf(", ");
            }
            printf("%d %s", combination[i], playNames[i]);
        }
        printf("\n");
        return;
    }

    // If score goes below zero or we used all play types, return
    if (score < 0 || index >= 5) {
        return;
    }

    // Try including the current play and call recursively
    combination[index]++;  // Add one instance of the current play
    findCombinations(score - plays[index], index, combination);  // Recurse with score reduced
    combination[index]--;  // Backtrack

    // Exclude current play and try next play
    findCombinations(score, index + 1, combination);  // Recurse to the next play
}

int main() {
    int score;

    while (1) {
        printf("Enter the NFL score (Enter 0 or 1 to STOP): ");
        scanf("%d", &score);

        if (score < 2) {
            break;
        }

        int combination[5] = {0};  // Array to store the count of each play
        printf("Combinations to achieve %d points:\n", score);
        findCombinations(score, 0, combination);  // Start recursive search for combinations
    }

    return 0;
}