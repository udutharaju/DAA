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
    if(n==0&&w!=0)
    {
        return 0;
    }
    if(w==0)
    {
        return 1;
    }
    if(coin[n-1]<=w)
    {
       return (cc(n,w-coin[n-1],coin))+cc(n-1,w,coin);
        
    }
    else
    {
        return cc(n-1,w,coin);
    }

}