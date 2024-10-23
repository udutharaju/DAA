#include <stdio.h>
#include <limits.h>
#define MAX 100

int mcm(int i, int j, int a[]){
    if (i == j) {
        return 0;
    }
    int min = INT_MAX;
    for (int k = i; k < j; k++) {
        int val = mcm(i, k, a) + mcm(k + 1, j, a) + a[i - 1] * a[k] * a[j];
        if (val < min) {
            min = val;
        }
    }
    return min;
}

int main() {
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX - 1) { 
        printf("Invalid input for number of matrices.\n");
        return 1;
    }

    int a[n + 1];
    printf("Enter the dimensions of matrices: ");
    for (int i = 0; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    int res = mcm(1, n, a); 
    printf("Minimum cost of multiplication is: %d\n", res);
    return 0;
}
