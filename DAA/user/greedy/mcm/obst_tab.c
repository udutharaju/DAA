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

int obst(int n, int dp[][MAX], int fre[]) {
    for (int i = 0; i < n; i++) {
        dp[i][i] = fre[i];
    }

    for (int l = 1; l < n; l++) { 
        for (int i = 0; i < n - l; i++) {
            int j = i + l;
            dp[i][j] = INT_MAX;
            int sum_fre = sum(fre, i, j);

            for (int r = i; r <= j; r++) {
                int cost = 0;
                if (r > i) {
                    cost += dp[i][r - 1];
                }
                if (r < j) {
                    cost += dp[r + 1][j];
                }
                cost += sum_fre;

                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
    int n;
    printf("Enter the size: ");
    scanf("%d", &n);
    int fre[n];
    int dp[MAX][MAX];

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &fre[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }

    int res = obst(n, dp, fre);
    printf("Optimal cost: %d\n", res);

    return 0;
}
