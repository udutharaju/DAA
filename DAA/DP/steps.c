#include<stdio.h>
int steps(int a[],int n);
int main()
{
    int n,i;
    printf("enter no of steps:");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<=n;i++)
    {
    a[i]=-1;
    a[i]=steps(a,i);
    }
    printf(" total no of possiblities: %d",a[n]);

}
    int steps(int a[],int n)
    {
      if(a[n]!=-1)
      {
        return a[n];
      } 
      else if(n==0)
      {
        return a[n]=0;
      }
      else if(n==1)
      {
        return a[n]=1;
      }
      else if(n==2)
      {
      return a[n]=2;
      }
      else
      {
        return a[n]=steps(a,n-1)+steps(a,n-2);
      }
    }
