#include<stdio.h>
#include<limits.h>
#include<math.h>
int cc(int n,int w,int coin[],int d[n][w]);
int main()
{
     int n,w;
    printf("enter n: ");
    scanf("%d",&n);
    printf("enter w: ");
    scanf(" %d",&w);
    int coin[n],i,j,d[n+1][w+1];
    printf("enter coins:\n");
    for(i=0;i<n;i++)
    {
      scanf("%d",&coin[i]);
    }
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=w;j++)
        {
            d[i][j]=-1;
        }
    }
    int m=cc(n,w,coin,d);
    printf("minimum no of coins:%d",m);
   
}
int cc(int n,int w,int coin[n],int d[n][w])
{
    if(d[n][w]!=-1)
    {
        return d[n][w];
    }
    if(n==0)
    {
        return INT_MAX-1000;
    }
    if(w==0)
    {
        return 0;
    }
    if(coin[n-1]<=w)
    {
       return d[n][w]=fmin(1+cc(n,w-coin[n-1],coin,d),cc(n-1,w,coin,d));
        
        
    }
    else
    {
        return d[n][w]=cc(n-1,w,coin,d);
    }

}

//time complexity: O(n^w)
