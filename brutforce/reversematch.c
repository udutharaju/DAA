#include<stdio.h>
#include<string.h>

int main()
{
    int i,j,f,f1,index,m,n;
    char a[50],b[50],c[50];
    printf("enter the string 1:");
    scanf("%s",a);
    printf("enter the string 1:");
    scanf("%s",b);
    for(i=strlen(b)-1,j=0;i>0,j<strlen(b) ;i--,j++)
    {
        c[j]=b[i];
    }
    printf("reversed string :%s\n",c);
    m =strlen(a);
    n = strlen(b);
   
     f1=0;
    for(i=0;i<=m-n;i++)
    {
        if(a[i]==c[0])
        {
            f=0;
            for(j=0;j<n;j++)
            {
                if(c[j]!=a[i+j])
                {
                      f=1;
                      break;     
                }
            }
            if(f==0)
            {
                f1=1;
                index=i;
            }
            if(f1==0)
            {
                 printf("string not found at any position");
            }
            else
            {
                printf("string found at %d position",index);
            }
        }
    }
}