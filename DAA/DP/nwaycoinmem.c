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
    int coin[n],i,j;
    printf("enter coins:\n");
    for(i=0;i<n;i++)
    {
      scanf("%d",&coin[i]);
    }
    int m=cc(n,w,coin);
    printf("total no of ways::%d",m);
   
}
int cc(int n,int w,int coin[])
{
     int d[n+1][w+1],i,j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=w;j++)
        {
            d[i][j]=-1;
        }
    }
    if(d[n][w]!=-1)
    {
        return d[n][w];
    }
    if(n==0&&w!=0)
    {
        return d[n][w]=0;
    }
    if(w==0)
    {
        return d[n][w]=1;
    }
    if(coin[n-1]<=w)
    {
       return d[n][w]=(cc(n,w-coin[n-1],coin))+cc(n-1,w,coin);
        
    }
    else
    {
        return d[n][w]=cc(n-1,w,coin);
    }

}
