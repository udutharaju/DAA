#include<stdio.h>
#include<limits.h>
int cc(int n,int w,int coin[]);
int main()
{
     int n,w;
    printf("enter n: ");
    scanf("%d",&n);
    printf("enter w: ");
    scanf(" %d",&w);
    int coin[n],i;
    printf("enter coins:\n");
    for(i=0;i<n;i++)
    {
      scanf("%d",&coin[i]);
    }
    int m=cc(n,w,coin);
    printf("total no of ways::%d",m);
   
}
int cc(int n,int w,int coin[n])
{
   
int i,j;
    int d[n+1][w+1];
    for(i=0;i<=n;i++)
    {
        d[i][0]=1;
    }
         for(i=1;i<=w;i++)
         {
            d[0][i]=0;
         }
         for(i=1;i<=n;i++)
         {
           for(j=1;j<=w;j++)
         {
    

    if(coin[i-1]<=j)
    { 
        d[i][j]=d[i][j-coin[i-1]]+d[i-1][j];
      }
    else
    {
        d[i][j]= d[i-1][j];
    }
    }
    }
    return d[n][w];
}