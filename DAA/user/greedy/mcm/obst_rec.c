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

int obst(int fre[], int i, int j) {
    if (i > j) {
        return 0;
    }
    if (i == j) {
        return fre[i];
    }

    int min = INT_MAX;

    
    for (int k = i; k <= j; k++) {
        int val = obst(fre, i, k - 1) + obst(fre, k + 1, j) + sum(fre, i, j);
        if (val < min) {
            min = val;
        }
    }

    return min;
}

int main() {
    int n;
    printf("Enter the size: ");
    scanf("%d", &n);

    int fre[n];
    printf("Enter the frequencies: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &fre[i]);
    }

    int result = obst(fre, 0, n - 1);
    printf("The cost of the optimal binary search tree is: %d\n", result);

    return 0;
}
