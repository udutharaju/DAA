#include <stdio.h>
#include <limits.h>

#define MAX 100

int memo[MAX];  // Array to store results of subproblems

// Initialize memoization array
void initializeMemo(int n) {
    for (int i = 0; i <= n; i++) {
        memo[i] = -1;  // -1 indicates that the value has not been computed yet
    }
}

// Recursive function with memoization
int frogJump(int cost[], int n) {
    if (n == 0) {
        return cost[0];
    }
    if (n == 1) {
        return cost[1];
    }
    if (memo[n] != -1) {
        return memo[n];
    }

    // Calculate the minimum cost to reach the n-th stone
    int oneStep = frogJump(cost, n - 1) + cost[n];
    int twoSteps = frogJump(cost, n - 2) + cost[n];
    
    // Store and return the result
    memo[n] = (oneStep < twoSteps) ? oneStep : twoSteps;
    return memo[n];
}

int main() {
    int n;
    int cost[MAX];
    
    printf("Enter the number of stones: ");
    scanf("%d", &n);
    
    printf("Enter the cost for each stone: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &cost[i]);
    }
    
    // Initialize memoization array for the number of stones
    initializeMemo(n - 1);
    
    printf("The minimum cost to reach the last stone is: %d\n", frogJump(cost, n - 1));
    
    return 0;
}

