#include<stdio.h>
#include<limits.h>
#include<math.h>
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
    printf("minimum no of coins:%d",m);
   
}
int cc(int n,int w,int coin[n])
{
   
int i,j;
    int d[n+1][w+1];
    for(i=0;i<=n;i++)
    {
        d[i][0]=0;
    }
         for(j=1;j<=w;j++)
         {
            d[0][j]=INT_MAX-1000;
         }
         for(i=1;i<=n;i++)
         {
           for(j=1;j<=w;j++)
         {
    

    if(coin[i-1]<=j)
    { 
        d[i][j]=fmin(1+d[i][j-coin[i-1]],d[i-1][j]);
      }
    else
    {
        d[i][j]= d[i-1][j];
    }
    }
    }
    return d[n][w];
}
