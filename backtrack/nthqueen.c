#include<stdio.h>

void nqueen(int ,int );
void print(int[],int);
int issafe(int,int);

int a[10];
void main()
{
    int n,k=0;
    scanf("%d",&n);
    nqueen(n,k);
}

void print(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
    printf("\n");
}

void nqueen(int n,int k)
{
    //When we reach last index it will print permutation.
    if(k==n)
    {
        print(a,n);
        return;
    }
    //loop for checking 
    for(int i=0;i<n;i++)
    {
        if(issafe(k,i))
        {
            a[k]=i;
            nqueen(n,k+1);
        }
    }
}

int issafe(int k,int i)
{
    for(int j=0;j<k;j++)
    {
        if(a[j]==i)
        return 0;
        if(abs(k-j)==abs(i-a[j]))
        return 0;
    }
    return 1;
}

