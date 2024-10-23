#include<stdio.h>
int knap(int n,int w,int wt[],int v[],int d[n][w]);
int main()
{
    int n,w;
    printf("enter n: ");
    scanf("%d",&n);
    printf("enter bag weight: ");
    scanf(" %d",&w);
    int wt[n],v[n],i,j,d[n+1][w+1];
    printf("enter weights:\n");
    for(i=0;i<n;i++)
    {
      scanf("%d",&wt[i]);
    }
    printf("enter values:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&v[i]);
    }
    
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=w;j++)
        {
           d[i][j]=-1;
          
    }
    }
   
    printf("max valuef sack : %d \n ",knap(n,w,wt,v,d));

}
int knap(int n,int w,int wt[n],int v[n],int d[n][w])
{

    if(d[n][w]!=-1)
    {
        return d[n][w];
    }
    if(n==0||w==0)
    {
        return d[n][w]=0;
    }
    if(wt[n-1]<=w)
    {
        int a=v[n-1]+knap(n-1,w-wt[n-1],wt,v,d);
        int b=knap(n-1,w,wt,v,d);
        int max;
        if(a>b)
        {
            max=a;
        }
        else if(a<b)
        {
            max=b;
        }
        else
        {
            max=a;
        }

        return d[n][w]=max;
    }
    else
    {
        return d[n][w]=knap(n-1,w,wt,v,d);
    }
}
