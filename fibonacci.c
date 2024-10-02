#include<stdio.h>

int fib(int);
int fibm(int);
int fibt(int);
int main ()
{
	int n,i;
	printf("enter the n value :");
	scanf("%d",&n);
	int result = fib(n);
	printf(" fib value is %d ",result);
	int result2= fibm(n);
	printf(" fibm value is %d ",result2);
	int result3= fibt(n);
	printf(" fibm value is %d ",result3);
}
int fib (int n)
{
	if(n==0 || n==1)
	{
		return 1;
	}
	else
	{
		return fib(n-1)+fib(n-2);
	}
}
int fibm(int n)
{
	int a[n],i;
	for(i=0;i<n;i++)
	{
		a[n]=-1;
	}
	if(a[n]!=-1)
	{
		return a[n];
	}
	if(n==0 || n==1)
	{
		return a[n]=1;
	}
	else
	{
		return  a[n]=fib(n-1)+fib(n-2);
	}
}
int fibt(int n)
{
	int i,a[n];
	for(i=0;i<n;i++)
	{
		if(i==0 || n==0)
		{
			a[i] = 1;
		}
		else
		{
			a[i] = fib(n-1)+fib(n-2);
		}	
	}
	return a[n];
}
