#include<stdio.h>
int print(int [],int,int);
int fill(int n ,int k,int a[],int s)
{
    if(k==n)
    {
        print(a,n,s);
        return;
    }
    for(int i=0;i<2;i++)
    {
        if(isSafe(a,n,k,s))
        {
        a[k]=i;
        fill(n,k+1,a,s);
        }

    }
}
int isSafe(int set[], int n, int sum, int total) {
    if (sum == total)
        return 1;
    if (sum > total || n < 0)
        return 0;
    return 1;
}
int print(int a[],int n,int s)
{
    int ws=0;
    for(int i=0;i<n;i++)
    {
        int ws=0;
        if(a[i]==1)

        {
            ws=ws+a[i];
        }
    }
    if(ws==s)
    {
        printf("found");
    }
    else
    {
        printf("not found");
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
    fill(n,0,a,s);
}
