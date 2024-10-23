#include<stdio.h>
void mergesort(int a[],int ,int);
void merge(int a[],int,int,int);
int main()
{
	int n,i;
	printf("enter the size :");
	scanf("%d",&n);
	int a[n];
	printf("enter the elements :");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	mergesort(a,0,n-1);
	printf(" sorted array:");
	for(i=0;i<n;i++)
	{
	printf("%d  ",a[i]);
	}
}
void mergesort(int a[],int low ,int high)
{
int mid;
if(low<high)
{
mid=(low+high)/2;
mergesort(a,low,mid);
mergesort(a,mid+1,high);
merge(a,low,mid,high);
}
}
void merge(int a[],int low,int mid,int high)
{
int i,j,k,b[50];
i=low;
j=mid+1;
k=low;
while(i<=mid&&j<=high)
{
if(a[i]<=a[j])
{
b[k++]=a[i++];
}
else
{
b[k++]=a[j++];
}

}
while(i<=mid)
{
b[k++]=a[i++];
}
while(j<=high)
{
b[k++]=a[j++];
}


for(k=low;k<=high;k++)
{
a[k]=b[k];
}
}

