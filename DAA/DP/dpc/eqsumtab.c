#include<stdio.h>
#include<stdbool.h>
int issubsum(int n,int sum,int wt[]);
int main()
{
    int n,w,sum=0;
    printf("enter n: ");
    scanf("%d",&n);
    int wt[n],i,j;
    int d[n+1][w+1];
    printf("enter weights:\n");
    for(i=0;i<n;i++)
    {
      scanf("%d",&wt[i]);
    }
    for(i=0;i<n;i++)
    {
        sum=sum+wt[i];
    }
   printf("sum=%d\n",sum);
  
    if(sum%2!=0)
    {
        printf("false");
    }
    else 
    {
       int k= issubsum(n,sum/2,wt);
       if(k==1)
       {
        printf("true");
       }
       else{
        printf("false");
       }

    }
    
    
    
}

int issubsum(int n,int w,int wt[])
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


    if(wt[i-1]<=j)
    {
        
        d[i][j]=d[i-1][j]||d[i-1][j-wt[i-1]];
        
    }
    else
    {
         d[i][j]=d[i-1][j];
    }
    }
    }
    return d[n][w];
}