#include <stdio.h>
#include <limits.h>

#define MAX 1000 

int sum(int fre[], int i, int j) {
    int sum1 = 0;
    for (int k = i; k <= j; k++) {
        sum1 += fre[k];
    }
    return sum1;
}

int obst(int fre[], int i, int j,int dp[][MAX]) {
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    if (i > j) {
        return 0;
    }
    if (i == j) {
        return fre[i];
    }

    int min = INT_MAX;
    for (int k = i; k <= j; k++) {
        int cost = obst(fre, i, k - 1,dp) + obst(fre, k + 1, j,dp) + sum(fre, i, j);
        if (cost < min) {
            min = cost;
        }
    }

    return dp[i][j] = min;
}

int main() {
    int n;
    printf("Enter the size: ");
    scanf("%d", &n);
    int dp[MAX][MAX];
    int fre[n+1];
    printf("Enter the frequencies: ");
    for (int i = 1; i <=n; i++) {
        scanf("%d", &fre[i]);
    }

    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <=n; j++) {
            dp[i][j] = -1;
        }
    }

    int result = obst(fre, 1, n,dp);
    printf("The cost of the optimal binary search tree is: %d\n", result);

    return 0;
}
