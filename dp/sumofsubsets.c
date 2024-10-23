#include<stdio.h>

int ss(int ,int,int[]);
int ssm(int ,int ,int [],int [10][10]);
int sst(int ,int ,int [],int [][10]);

int main()
{
	int wt[10],s,n,i,j,a[10][10];
	printf("enter the how many numbers do you want");
	scanf("%d",&n);
	printf("enter the numbers:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&wt[i]);
	}
	printf("enter the sum you required");
	scanf("%d",&s);
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=s;j++)
		{
			a[i][j]=-1;
		}
	}
	int result = ss(n,s,wt); 
	printf("values are %d\n",result);
	
	int result1 = ssm(n,s,wt,a); 
	printf("\n %d times possible to from number with memorization",result1);
	
	int result2 = sst(n,s,wt,a); 
	printf("\n %d times possible to from number with tabulation",result2);
}
int ss(int n,int s,int wt[])
{
	if(s==0 )
	{
		return 1;
	}
	if(n==0 )
	{
		return 0;
	}
	if(wt[n-1]<=s)
	{
		return ss(n-1,s-wt[n-1],wt)+ss(n-1,s,wt);
	}
	else
	{
		return ss(n-1,s,wt);
	}
}

int ssm(int n,int s,int wt[],int a[][10])
{
	if(a[n][s]!=-1)
	{
		return a[n][s];
	}
	if(s==0 )
	{
		return a[n][s] = 1;
	}
	if(n==0 )
	{
		return a[n][s]=0;
	}
	if(wt[n-1]<=s)
	{
		return a[n][s] =ssm(n-1,s-wt[n-1],wt,a)+ssm(n-1,s,wt,a);
	}
	else
	{
		return a[n][s] = ssm(n-1,s,wt,a);
	}
}

int sst(int n,int s,int wt[],int a[][10])
{
	int i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=s;j++)
		{
			if(j==0)
			{
				a[i][j]=1;
				continue;
			}
			if(i==0)
			{
				a[i][j]=0;
				continue;
			}
			if(wt[i-1]<=j)
			{
				a[i][j]=a[i-1][j-wt[i-1]]+a[i-1][j];
			}
			else
			{
				a[i][j] = a[i-1][j];
			}
		}
	}
	return a[n][s];
}
