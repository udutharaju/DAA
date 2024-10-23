
#include <stdio.h>

void sortItems(int n, int wt[], int val[]) {
    int i, j;
    double r1, r2;
    int tempWt, tempVal;
    
    for (i = 0; i < n; i++) {
        for (j = i+1; j < n ; j++) {
            r1 = (double)val[i] / wt[i];
            r2 = (double)val[j ] / wt[j ];
            
            if (r1 < r2) {
                // Swap weights
                tempWt = wt[j];
                wt[j] = wt[i];
                wt[i] = tempWt;
                
                // Swap values
                tempVal = val[j];
                val[j] = val[i];
                val[i] = tempVal;
            }
        }
    }
}

int fks(int n, int W, int wt[], int val[]) {
    sortItems(n, wt, val); // Sort items by value-to-weight ratio
    int res = 0;
    int i;

    for (i = 0; i < n; i++) {
        if (wt[i] > W) {
            res += (W * val[i]) / wt[i];
            break;
        } else {
            res += val[i];
            W -= wt[i];
        }
    }

    return res;
}

int main() {
    int i, n, W;
    printf("Enter the size: ");
    scanf("%d", &n);
    printf("Enter the total weight of bag: ");
    scanf("%d", &W);

    int wt[n], val[n];
    printf("Enter the weights: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &wt[i]);
    }

    printf("Enter the values: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &val[i]);
    }

    printf("The appropriate method gives a maximum value of: %d\n", fks(n, W, wt, val));
    return 0;
}

