#include<stdio.h>
#include <limits.h>

int mcm(int ,int);
int mcmm(int ,int );
int mcmt(int ,int );
int a[10],n,val,b[100][100];
int main ()
{
	int i,j;
	printf("enter the array size:");
	scanf("%d",&n);
	printf("enter the matrix sizes");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			b[i][j]=-1;
		}
	}
	
	int result = mcm(1,n-1);
	printf("result %d",result);
	int result1 = mcmm(1,n-1);
	printf("result %d",result1);
	int result3 = mcmt(1,n-1);
	printf("result %d",result3);
}
int mcm(int i,int j)
{
	if(i==j)
	{
		return 0;
	}
	else
	{
		int min =INT_MAX;
		for(int k=i;k<j;k++)
		{
			val= mcm(i,k)+mcm(k+1,j)+(a[i-1]*a[j]*a[k]);
		
			if(val<min)
			{
				min =val;
			}
		}
		return min;
	}	
}
int mcmm(int i,int j)
{
	if(b[i][j]!=-1)
	{
		return b[i][j];
	}
	if(i==j)
	{
		return b[i][j]=0;
	}
	int min = INT_MAX;
	for(int k=i;k<j;k++)
	{
		val = mcmm(i,k)+mcmm(k+1,j)+(a[i-1]*a[j]*a[k]);
		if(val<min)
		{
			min =val;
		}
	}
	return b[i][j] =min;
}
int mcmt(int i,int j)
{
	int dp[10][10];
	for(int k=0;k<n;k++)
	{
		for(i=1;i<=n-k-1;i++)
		{
			j=i+k;
			if(i==j)
			{
				dp[i][j]=0;
				continue;	
			}
			int min =INT_MAX;
			for(int l =i;l<j;l++)
			{
				val=dp[i][l]+dp[l+1][j]+(a[i-1]*a[j]*a[l]);
				if(val<min)
				{
					min =val;
				}
			} dp[i][j]=min;	
		}
	}return dp[i][j];	
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
