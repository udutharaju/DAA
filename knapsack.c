#include<stdio.h>
int ks(int ,int  );
int ksm(int,int);
int kst(int  ,int );
int w[10],val[10];
int a[10][10];
int max(int a,int b)
{
	return a>b?a:b;
}
int main ()
{
	int tw,n,i,j;
	printf("enter the n value:");
	scanf("%d",&n);
	printf("enter the bag weight:");
	scanf("%d",&tw);
	
	printf("enter the %d weights:",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&w[i]);
	}
	printf("enter the %d values:",n);
	for(j=0;j<n;j++)
	{
		scanf("%d",&val[j]);
	}
	int result = ks(n,tw);
	printf("result %d:",result);
	
	int result2 = ksm(n,tw);
	printf("result %d:",result2);
	int result3 = kst(n,tw);
	printf("result %d:",result3);
}
int ks(int n,int tw)
{
	if(n==0 || tw==0)
	{
		return 0;
	}
	if(w[n-1]<=tw)
	{
		return max(val[n-1]+ks(n-1,tw-w[n-1]),ks(n-1,tw));
	}
	else
	{
		return ks(n-1,tw);
	}
}
int ksm(int n,int tw)
{
	int i,j;
	for(i=0;i<=n;i++){
		for(j=0;j<=tw;j++){
			a[i][j]=-1;
		}
	}
	if(a[n][tw]!=-1)
	{
		return a[n][tw];
	}
	if(n==0 || tw ==0 )
	{
		return a[n][tw] =0 ;
	}
	if(w[n-1]<=tw)
	{
		return a[n][tw] = max(val[n-1]+ksm(n-1,tw-w[n-1]),ksm(n-1,tw));
	}
	else
	{
		return a[n][tw]=ks(n-1,tw);
	}
}
int kst(int n ,int tw)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<=tw;j++)
		{
			if(i==0 || j==0)
			{
				a[i][j]=0;
			}
			if(w[n-1]<tw)
			{
				a[i][j]=max(val[i-1]+kst(i-1,j-w[i-1]),kst(i-1,j));
			}
			else
			{
				a[i][j]=kst(i-1,j);
			}
		}
	}
	return a[n][tw];
}
