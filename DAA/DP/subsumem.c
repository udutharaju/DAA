#include<stdio.h>
int subsum(int n,int w,int wt[],int d[n][w]);
int main()
{
    int n,w;
    printf("enter n: ");
    scanf("%d",&n);
    printf("enter bag weight: ");
    scanf(" %d",&w);
    int wt[n],i,j,d[n+1][w+1];
    printf("enter weights:\n");
    for(i=0;i<n;i++)
    {
      scanf("%d",&wt[i]);
    }
    for(i=0;i<=n;i++)
    {
         for(j=0;j<=w;j++)
         {
        d[i][j]=-1;
    }
    }
    int s=subsum(n,w,wt,d);
    if(s==1)
    {
        printf("True");
    }
    else{
        printf("False");
    }
    
}
int subsum(int n,int w,int wt[],int d[n][w])
{
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
    if(wt[n-1]<=w)
    {
       return d[n][w]=subsum(n-1,w-wt[n-1],wt,d)||subsum(n-1,w,wt,d);
    
    }
    else
    {
        return d[n][w]=subsum(n-1,w,wt,d);
    }
}


//timecomplexity: O(2^n)
