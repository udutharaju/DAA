#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<stdbool.h>
int nqueen(int n,int k);
bool isattack(int k,int i);
int q[10];
int nqueen(int n,int k)
{
    int i;
    if(k==n)
    {
        //return q;
        for(i=0;i<n;i++)
        {
           printf("%d",q[i]); 
        }
        printf("\n");
        return;
    }
    for(i=0;i<n;i++)
    {
        if(isattack(k,i))
        {
            q[k]=i;
            nqueen(n,k+1);
        }
    }
}
bool isattack(int k,int i)
{
   int j;
   for(j=0;j<k;j++)
   {
    if(q[j]==i)
    {
    return false;
    }
    if(abs(k-j)==abs(i-q[j]))
    {
    return false;
    }
   } 
   return true;
}
int main()
{
    int n;
    printf("enter n:");
    scanf("%d",&n);
     nqueen(n,0);
}




