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
       return fmin(1+cc(n,w-coin[n-1],coin),cc(n-1,w,coin));
        
        
    }
    else
    {
        return cc(n-1,w,coin);
    }

}
