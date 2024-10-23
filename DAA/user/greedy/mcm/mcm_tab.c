#include<stdio.h>
#include<limits.h>

#define MAX 100

int mcm(int n, int a[], int dp[][MAX]) {
  
    
    
    for (int l = 0; l < n; l++) { 
        for (int i = 1; i <=n - l; i++) {
            int j = i + l;
            if(i==j){
                dp[i][j]=0;
                continue;
            }
            dp[i][j] = INT_MAX; 
            
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + a[i - 1] * a[k] * a[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }
    
    return dp[1][n];
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
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dp[i][j]=0;
        }
    }
    int res = mcm(n, a, dp);
    printf("Minimum cost of multiplication is: %d\n", res);
    
    return 0;
}