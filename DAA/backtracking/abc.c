#include<stdio.h>
#include<stdbool.h>
#include<string.h>
//char a[]="abc";
void fill(int k,int n,char a[])
{
    
    if(k==n)
    {
    
        printf("%s\n ",a);
        //return;
       
    }
    for(char i='a';i<='c';i++)

        if(issafe(k,i,a))
        {
            a[k]=i;
            fill(k+1,n,a);
        }
 }
int issafe(int k,int i,char a[])
{
    int j;
    for(j=0;j<k;j++)
    {
        if(a[j]==i)
        {
        return 0;
        }
    }
    return 1;
}
int main()
{
    //char a[]="abc";
    char a[100];
    scanf("%s",a);
    int n=strlen(a);
    fill(0,n,a);
    
}

/*time complexity: O(n!)*/
