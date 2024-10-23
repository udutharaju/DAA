#include<stdio.h>
int main()
{
    int n;
    printf("enter n value:");
    scanf("%d",&n);
    printf("fibonacci series:");
    for(int i=0;i<=n;i++)
    {
        printf("%d  ",fib(i));
    }

}
int fib(int n)
{
   
if(n==0)
{
    return 0;
}
else if(n==1)
{
    return 1;
}
else
{
    return fib(n-1)+fib(n-2);
}
    }



