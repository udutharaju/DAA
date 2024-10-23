#include <stdio.h>
#include <limits.h> 
#define MAX 100

int mcm(int i, int j, int a[], int dp[][MAX]) {
    if (i == j) {
        return dp[i][j] = 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    int min = INT_MAX; 
    for (int k = i; k < j; k++) {
        int val = mcm(i, k, a, dp) + mcm(k + 1, j, a, dp) + a[i - 1] * a[k] * a[j];
        if (val < min) {
            min = val;
        }
    }
    return dp[i][j] = min;
}

int main() {
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    int a[n+1]; 
    printf("Enter the dimensions of matrices: ");
    for (int i = 0; i <= n; i++) {
        scanf("%d", &a[i]);
    }
         
    int dp[MAX][MAX];
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            dp[i][j] = -1; 
        }
    }

    int res = mcm(1, n, a, dp);
    printf("Minimum number of multiplications needed: %d\n", res);

    return 0;
}
