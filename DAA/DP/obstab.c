
#include <stdio.h>
#include <limits.h>

int sum(int freq[], int i, int j);
int optimalSearchTree(int keys[], int freq[], int n)
{
	int cost[n][n];

	for (int i = 0; i < n; i++)
		cost[i][i] = freq[i];
	for (int L=1; L<n; L++)
	{
		for (int i=0; i<=n-L; i++)
		{
	
			int j = i+L;
			int s = sum(freq, i, j);
			cost[i][j] = INT_MAX;

			for (int k=i; k<=j; k++)
			{
			int val = ((k > i)? cost[i][k-1]:0) + ((k < j)? cost[k+1][j]:0) + s;
			if (val < cost[i][j])
				cost[i][j] = val;
			}
		}
	}
	return cost[0][n-1];
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
	//int keys[] = {10, 12, 20};
	//int freq[] = {34, 8, 50};
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
	printf("Cost of Optimal BST is %d ", 
				optimalSearchTree(keys, freq, n));
	return 0;
}

