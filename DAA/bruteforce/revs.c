#include<stdio.h>
#include<string.h>
int main()
{
    char a[100],b[100];
   printf("enter string:");
   scanf("%s",a);
    printf("enter substring:");
    scanf("%s",b);
    char rev[100];
    int len=strlen(b);
    int t=len-1;
    /*for(int st=0,en=len-1;st<en;st++,en--)
    {rev=b[st];
    b[st]=b[en];
    b[en]=rev;
    }*/
    for(int i=0;i<len;i++)
    {
    rev[i]=b[t];
    t--;
    }
    
   printf("rev %s",rev);
    int f=0,f1=0,i,j;
        for(i=0;i<=(strlen(a)-strlen(rev));i++)
        {if(rev[0]==a[i])
            {f=0;
                for(j=0;j<strlen(rev);j++)
                {
                    if(rev[j]!=a[j+i])
                   {f=1;
                    break;}
                }
            if(f==0)
            {printf("\nmatch found at %d pos ",i);
                f1=1;break;
         }}}
        if(f1==0)
        {
            printf("not found");
        }}

