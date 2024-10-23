#include<stdio.h>
#include<string.h>
int main()
{
    int m,n,i,j,k,f=0,c=0,f1=0;
    char a[100],b[100];
    printf("enter a string");
    scanf("%s",a);
    printf("enter b string:");
    scanf("%s",b);
     m=strlen(a);
     n=strlen(b);
     for(i=0;i<=(m-n);i++)
     {
        if(b[0]==a[i])
        {
        f=0;
            for(j=0,k=0;j<n,k<m;k++,j++)
            {
                if(b[j]!=a[(k+=k)+j])
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
     if(f1==1)
     {
        printf("match found %d times",c);

     }
     else
     {
        printf("not found");
     }

}
