
#include <stdio.h>

void printSubset(int n,int subset[]) {
    
        printf("Subset: ");
        for (int i = 0; i < n; i++) {
            if (subset[i] != 0)
                printf("%d ", subset[i]);
        }
        printf("\n");
    
}

void subsetSum(int a[], int n, int sum, int total, int subset[],int i) {
    if (sum == total) {
        printSubset( n,subset);
    } else {
        if (sum > total || i < 0)
            return;
        subset[i] = a[i]; // Include current element
        subsetSum(a, n , sum + a[i], total, subset,i-1);
        subset[i] = 0; // Exclude current element
        subsetSum(a, n , sum, total, subset,i-1);
    }
}

int main()
{
    int n,s;
    printf("enter n:");
    scanf("%d",&n);
    int a[n];
    printf("enter the elements:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter weight:");
    scanf("%d",&s);
    int subset[n+1];
    subsetSum(a, n, 0, s,subset, n-1);
    return 0;
}




