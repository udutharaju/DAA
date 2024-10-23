#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int count=0;
void fill(int n,char*str,int k)
{
    if(k==n)
    {
        printf("%s\n",str);
        count++;
        return;
    }
    str[k]='0';
    fill(n,str,k+1);
    str[k]='1';
    fill(n,str,k+1);
}
int main()
{
    int k=0,n;
    printf("enter the number of bits:");
    scanf("%d",&n);
    char str[n+1];
    str[n]='\0';
    printf("binary numbers of length %d are:\n",n);
    fill(n,str,k);
    printf("total no of binary numbers are: %d",count);
}