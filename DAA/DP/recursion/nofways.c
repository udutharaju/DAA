#include<stdio.h>
int subsum(int n,int w,int wt[]);
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
    
    
    int s=subsum(n,w,wt);
   printf("no of ways:%d",s);
    
}
int subsum(int n,int w,int wt[])
{
    if(n==0&&w!=0)
    {
         return 0;
    }
    if(w==0)
    {
        return 1;
    }
    if(wt[n-1]<=w)
    {
        return subsum(n-1,w-wt[n-1],wt)+subsum(n-1,w,wt);
       
    }
    else
    {
        return subsum(n-1,w,wt);
    }
}
