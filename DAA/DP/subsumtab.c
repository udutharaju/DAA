#include<stdio.h>
#include<stdbool.h>
bool subsum(int n,int w,int wt[]);
int main()
{
    int n,w;
    printf("enter n: ");
    scanf("%d",&n);
    printf("enter bag weight: ");
    scanf(" %d",&w);
    int wt[n],i,j;
    printf("enter weights:\n");
    for(i=0;i<n;i++)
    {
      scanf("%d",&wt[i]);
    }
    
    if(subsum(n,w,wt)==true)
    printf("true");
    else
    printf("false");
   // printf("%c",subsum(n,w,wt));
    
    
    
}
bool subsum(int n,int w,int wt[])
{
    int i,j;
    int d[n+1][w+1];
    for(i=0;i<=n;i++)
    {
        d[i][0]=true;
    }
    for(i=1;i<=w;i++)
    {
         d[0][i]=false;
    }
         for(i=1;i<=n;i++)
         {
           for(j=1;j<=w;j++)
          {
              if(wt[i-1]<=j)
              { 
                 d[i][j]=d[i-1][j-wt[i-1]]||d[i-1][j];
              }
              else
              {
                 d[i][j]= d[i-1][j];
              }
         }
       }
    return d[n][w];
    
}
