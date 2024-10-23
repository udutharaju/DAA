#include<stdio.h>
#include<stdbool.h>
bool issubsum(int n,int sum,int wt[]);
int main()
{
    int n,w,sum=0;
    printf("enter n: ");
    scanf("%d",&n);
    int wt[n],i,j;
    
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
       bool k= issubsum(n,sum/2,wt);
       if(k==true)
       {
        printf("true");
       }
       else{
        printf("false");
       }

    }
    
    
    
}

bool issubsum(int n,int w,int wt[])
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
    if(w==0)
    {
        return true;
    }
    if(n==0&&w!=0)
    {
        return false;
    }
    if(wt[n-1]<=w)
    {
        
       return d[n][w]=issubsum(n-1,w,wt)||issubsum(n-1,w-wt[n-1],wt);
        
    }
    else
    {
        return d[n][w]=issubsum(n-1,w,wt);
    }
}


//timecomplexity: O(n*m) where n=size of array and m is half the elements of rray when sum is even
