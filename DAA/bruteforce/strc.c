//2.string matching and its count
#include<stdio.h>
#include<string.h>
int main()
{
    char a[100],b[100];
    printf("enter string:");
    scanf("%s",a);
    printf("enter substring:");
    scanf("%s",b);
    int f=0,f1=0,i,j,c=0;
        for(i=0;i<=(strlen(a)-strlen(b));i++)
        {
            if(b[0]==a[i])
            f=0;
                for(j=0;j<strlen(b);j++)
                {
                    if(b[j]!=a[j+i])
                    {
                    f=1;
                    break;
                    }
                }
            if(f==0)
            {
               c++;
                f1=1;
            }
        }
        if(f1==0)
        {
            printf("not found");
        }
        else
        {
            printf("found %d times",c);
        }}

