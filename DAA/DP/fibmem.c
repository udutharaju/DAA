#include<stdio.h>
int main()
{
    int n;
    printf("enter n value:");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<=n;i++)
    {
         a[i]=-1;
        printf("%d \n",fib(a,i));
    }

}
int fib(int a[],int n)
{
   
   if(a[n]!=-1)
   {
    return a[n];
   }
    else if(n==0)
    {
    return a[n]=0;
    }
    else if(n==1)
    {
    return a[n]=1;
     }
    else
    {
    return a[n]=fib(a,n-1)+fib(a,n-2);
    }
}