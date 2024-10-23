#include<stdio.h>
#include<math.h>
int knap(int wt[],int v[],int w,int n);
int main()
{
    int n,w;
    printf("enter n: ");
    scanf("%d",&n);
    printf("enter bag weight: ");
    scanf(" %d",&w);
    int wt[n],v[n],i;
    printf("enter weights:\n");
    for(i=0;i<n;i++)
    {
      scanf("%d",&wt[i]);
    }
    printf("enter values:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&v[i]);
    }
    printf("max valuef sack : %d \n ",knap(wt,v,w,n));

}
int knap(int wt[], int v[], int w, int n) {
    return backtrack(0, 0, 0, wt, v, w, n);
}
int backtrack(int i, int weight, int value, int wt[], int values[], int w, int n) {
    if (i == n) {
        return value;
    }

    if (weight + wt[i] <= w) {
        int a = backtrack(i + 1, weight + wt[i], value + values[i], wt, values, w, n);
        int b = backtrack(i + 1, weight, value, wt, values, w, n);
        return (a > b) ? a : b;
    } else {
        return backtrack(i + 1, weight, value, wt, values,w, n);
    }
}

