
#include <stdio.h>
#include <limits.h>
int sum(int freq[], int i, int j);
int optCost(int freq[], int i, int j)
{
int d[i+1][j+1];
for(int k=0;k<=i;k++)
{
for(int l=0;l<=j;l++)
{
d[k][l]=-1;
}
}
if(d[i][j]!=-1)
return d[i][j]=0;
if (i > j)	
	return d[i][j]=0;
if (i == j)	 
	return d[i][j]=freq[i];

int fsum = sum(freq, i, j);
int min = INT_MAX;
for (int k = i; k <= j; k++)
{
	int val = optCost(freq, i, k-1) + optCost(freq, k+1, j)+fsum;
	if (val < min)
		min = val;
}


return d[i][j]=min;;
}

int sum(int freq[], int i, int j)
{
	int s = 0;
	for (int k = i; k <=j; k++)
	s += freq[k];
	return s;
}

int main()
{
        int n;
        printf("enter n:");
        scanf("%d",&n);
        int keys[n],freq[n];
	printf("enter keys:");
	for(int i=0;i<n;i++)
	{
	scanf("%d",&keys[i]);
	}
	printf("enter freq:");
	for(int i=0;i<n;i++)
	{
	scanf("%d",&freq[i]);
	}
	printf("Cost of Optimal BST is %d ", optCost(freq, 0, n-1));
	return 0;
}

