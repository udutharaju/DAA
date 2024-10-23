#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>
int mf(int a[],int n)
{
    int sum=0,i,j;
    for(i=0;i<n;i++)
    {
          sum+=a[i];
    }
    int w=sum/2;
    int d[n+1][w+1];
    for(i=0;i<=n;i++)
    {
      d[i][0]=1; 
    }
    for(j=1;j<=w;j++)
    {
        d[0][j]=0;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=w;j++)
        {
            if(a[i-1]<=j)
            {
                d[i][j]=d[i-1][j]||d[i-1][j-a[i-1]];
            }
            else
            {
                d[i][j]=d[i-1][j];
            }
        }
    }
    int mmf=INT_MAX;
    for(j=w;j>=0;j--)
    {
        if(d[n][j])
        {
          mmf=sum-2*j;
          break;
        }
    }
    return mmf;
}
int main()
{
    int n,i;
    printf("enter the n value:");
    scanf("%d",&n);
    int a[n];
    printf("enter elements:");
    for(i=0;i<n;i++)
    {
         scanf("%d",&a[i]);

    }
    int mmf=mf(a,n);
    printf("minimum difference is : %d ",mmf);
}

//TIME COMPLEXITY: O(2^n*n)
