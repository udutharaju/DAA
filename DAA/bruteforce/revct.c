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
   /* for(int strt=0,end=len-1;strt<end;strt++,end--)
    {
    char t=b[strt];
    b[strt]=b[end];
    b[end]=t;
    }*/
     for(int i=0;i<len;i++)
    {
    rev[i]=b[t];
    t--;
    }
  
    printf("rev %s",rev);
    int f=0,f1=0,i,j,c=0;
        for(i=0;i<(strlen(a)-strlen(b));i++)
        {
            if(rev[0]==a[i])
            {
             f=0;
                for(j=0;j<strlen(rev);j++)
                {
                    if(rev[j]!=a[j+i])
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
        
        
        }
        if(f1==0)
        {
            printf("not found");
        }
        else
        {
        printf("match found %d times ",c);
        }


}

