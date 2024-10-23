#include <stdio.h>
#include <limits.h>

#define MAX 100

int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to find the minimum cost to reach the last stone
int frogJump(int cost[], int n) {
    int dp[MAX];
    
    // Base cases
    dp[0] = cost[0];
    if (n > 1) {
        dp[1] = min(cost[0] + cost[1], cost[1]);
    }

    // Fill the dp table
    for (int i = 2; i < n; i++) {
        dp[i] = min(dp[i - 1] + cost[i], dp[i - 2] + cost[i]);
    }

    return dp[n - 1];
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
    
    printf("The minimum cost to reach the last stone is: %d\n", frogJump(cost, n));
    
    return 0;
}

