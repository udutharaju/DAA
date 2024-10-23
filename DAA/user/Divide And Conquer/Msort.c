#include<stdio.h>

void merge(int a[],int low,int mid,int high)
{
    int i=low,j=mid+1,k=low,b[20];
    while(i<=mid && j<=high)
    {
        if(a[i]<=a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];    
    }
    while(i<=mid)
        b[k++] = a[i++];
    while(j<=high)
        b[k++] = a[j++];
    for(k=0;k<=high;k++)
    {
        a[k] = b[k];
    }        
}

void msort(int a[],int low,int high)
{
    if(low<high)
    {
        int mid = (low+high)/2;
        msort(a,low,mid);
        msort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

void main()
{
    int n;
    printf("Enter array size : ");
    scanf("%d",&n);
    int a[n];
    printf("Enter array elements : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }  
    msort(a,0,n-1);
    printf("Sorted array : \n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}