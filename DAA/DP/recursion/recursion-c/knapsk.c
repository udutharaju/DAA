#include<stdio.h>
#include<math.h>
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
    printf("max valuef sack : %d \n ",knap(n,w,wt,v));

}
int knap(int n,int w,int wt[n],int v[n])
{
    
    if(n==0||w==0)
    {
        return 0;
    }
    if(wt[n-1]<=w)
    {
       // int a=v[n-1]+knap(n-1,w-wt[n-1],wt,v);
        //int b=knap(n-1,w,wt,v);
        /*int max;
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
        }*/

        return fmax(v[n-1]+knap(n-1,w-wt[n-1],wt,v),knap(n-1,w,wt,v));
    }
    else
    {
        return knap(n-1,w,wt,v);
    }
}
