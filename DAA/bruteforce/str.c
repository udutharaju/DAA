#include<stdio.h>
#include<string.h>
int main()
{
    char a[100],b[100];
    printf("enter string:");
    scanf("%s",a);
    printf("enter substring:");
    scanf("%s",b);
    int f=0,f1=0,i,j;
        for(i=0;i<strlen(a);i++)
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
                printf("match found");
                f1=1;
                break;
            }
            
            
        }
        if(f1==0)
        {
            printf("not found");
        }


}

