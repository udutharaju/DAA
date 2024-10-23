#include<stdio.h>
int knap(int n,int w,int wt[],int v[]);
int main()
{
    int n,w;
    printf("enter n: ");
    scanf("%d",&n);
    printf("enter bag weight: ");
    scanf(" %d",&w);
    int wt[n],v[n],i;
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
   // knap(n,w,wt,v);
     printf("max valuef sack : %d \n ",knap(n,w,wt,v));

}
int knap(int n,int w,int wt[],int v[])
{
int i,j;
int d[n+1][w+1];
for(i=0;i<=n;i++)
    {
        for(j=0;j<=w;j++)
        {

   
    if(i==0||j==0)
    {
         d[i][j]=0;
    }
    else if(wt[i-1]<=j)
    {
        int a=v[i-1]+d[i-1][j-wt[i-1]];
        int b=d[i-1][j];
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

         d[i][j]=max;
    }
    else
    {
         d[i][j]=d[i-1][j];
    }
    }
    }
    return d[n][w];
  // printf("max: %d",d[n][w]);
}
