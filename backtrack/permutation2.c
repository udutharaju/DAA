#include<stdio.h>

void permute(int ,int );
void print(int[],int);


int a[10];
void main()
{
    int n,k=0;
    scanf("%d",&n);
    permute(n,k);
}

void print(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
    printf("\n");
}
void permute(int n,int k)
{
    //When we reach last index it will print permutation.
    if(k==n)
    {
        print(a,n);
        return;
    }
    //loop for checking 
    for(int i=0;i<2;i++)
    {
        a[k]=i;
        permute(n,k+1);
    }
}


