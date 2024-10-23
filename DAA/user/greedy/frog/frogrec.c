#include <stdio.h>
#include <limits.h>

#define MAX 100

// Recursive function to find the minimum cost to reach the last stone
int frogJump(int cost[], int n) {
    if (n == 0) {
        return cost[0];
    }
    if (n == 1) {
        return cost[1];
    }

    // Calculate the minimum cost to reach the n-th stone
    int oneStep = frogJump(cost, n - 1) + cost[n];
    int twoSteps = frogJump(cost, n - 2) + cost[n];
    
    return (oneStep < twoSteps) ? oneStep : twoSteps;
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
    
    printf("The minimum cost to reach the last stone is: %d\n", frogJump(cost, n - 1));
    
    return 0;
}

