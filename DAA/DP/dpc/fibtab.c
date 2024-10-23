#include<stdio.h>
int main()
{
    int n;
    printf("enter n value:");
    scanf("%d",&n);
    
  
     printf("fibonacci nth value %d \n",fib(n));
    
    

}
int fib(int n)
{
    int a[n];
    //tabulation
   for(int i=0;i<=n;i++)
   {
     if(i==0)
     {
      a[i]=0;
      printf("%d ",a[i]);
   
    }
      else if(i==1)
     {
    a[i]=1;
    printf("%d ",a[i]);
   
    }
     else
      {
      a[i]=a[i-1]+a[i-2];
      printf("%d ",a[i]);
     
     }  
   
     }
      return a[n];
}
     