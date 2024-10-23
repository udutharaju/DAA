#include<stdio.h>
int main()
{
    int n,w;
    printf("enter n: ");
    scanf("%d",&n);
    printf("enter bag weight: ");
    scanf(" %d",&w);
    int wt[n],i;
    printf("enter weights:\n");
    for(i=0;i<n;i++)
    {
      scanf("%d",&wt[i]);
    }
    int s=subsum(n,w,wt);
    if(s==1)
    {
        printf("true");
    }
    else{
        printf("false");
    }
    
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
        
        //int a=subsum(n-1,w-wt[n-1],wt);
        //int b=subsum(n-1,w,wt);
        return subsum(n-1,w-wt[n-1],wt)||subsum(n-1,w,wt);
       //return a||b;
        
    }
    else
    {
        return subsum(n-1,w,wt);
    }
}
