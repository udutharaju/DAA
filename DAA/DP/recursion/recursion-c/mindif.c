#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int min(int n,int a[],int s1,int sum)
{
    if(n==0)
    {
         return abs((sum-s1)-s1);
    }
    else{
         return fmin(min(n-1,a,s1+a[n-1],sum),min(n-1,a,s1,sum));
    }
    
    

}
int main()
{
    int n,i,j,sum=0;
    printf("enter n:");
    scanf("%d",&n);
    int a[n];
    printf("enter elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        sum=sum+a[i];
    }
    printf("sum :%d",sum);
    printf("minimum set difference is:%d",min(n,a,0,sum));
}