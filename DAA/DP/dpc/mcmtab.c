#include<stdio.h>
#include<limits.h>
int mcm(int n,int a[]);
int main()
{
 
 printf("enter the array size");
  int n;
  scanf("%d",&n);
 int a[n];
 printf("enter the array elements");
  for(int i=0;i<n;i++)
  {
   scanf("%d",&a[i]);
   }
 int min=mcm(n,a);
 printf("min value: %d",min);
 }

 int  mcm(int n,int a[])
 {
 int dp[n+1][n+1];
 for(int l=0;l<n;l++)
  {
   for(int i=1;i<n-l;i++)
   {
    int j=i+l;
    
    if(i==j)
   {
    dp[i][j]=0;
    continue;
    }
   dp[i][j]=INT_MAX;
  int value;
  for(int k=i;k<j;k++)
  {
   value=dp[i][k]+dp[k+1][j]+a[i-1]*a[k]*a[j];
   if(value<dp[i][j])
    
  dp[i][j]=value;
  }
  }
 }
  return dp[1][n-1];
 }

  
   
