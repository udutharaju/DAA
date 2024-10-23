
#include <stdio.h>
#include <limits.h>
int sum(int freq[], int i, int j);
int optCost(int freq[], int i, int j)
{
if (i > j)	
	return 0;
if (i == j)	 
	return freq[i];

int fsum = sum(freq, i, j);
int min = INT_MAX;
for (int k = i; k <= j; k++)
{
	int val = optCost(freq, i, k-1) + optCost(freq, k+1, j)+fsum;
	if (val < min)
		min = val;
}


return min;
}
/*int optimalSearchTree(int keys[], int freq[], int n)
{
	return optCost(freq, 0, n-1);
}*/

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
	//int n = sizeof(keys)/sizeof(keys[0]);
	printf("Cost of Optimal BST is %d ", optCost(freq, 0, n-1));
	return 0;
}

