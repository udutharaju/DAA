#include<stdio.h>
#include<string.h>
int main()
{
    int m,n,i,j;
     char a[50];
    char b[20];

    int index;
   
    printf("enter the first string:");
    scanf("%s",a);
    printf("enter the second string:");
    scanf("%s",b);
    m =strlen(a);
    n = strlen(b);
    
   
    int f1=0,count=0;
    for(i=0;i<=m-n;i++)
    {
        if(a[i]==b[0])
        {
            int f=0;
            for(j=0;j<n;j++)
            {
                if(b[j]!=a[i+j])
                {
                    f=1;
                    break;
                }
               
            } count++;
            if(f == 0)
            {
                f1=1;
               index = i;
            }
        }   
    }
    printf("count of sub string:%d\n",count);
     if(f1==0)
     {
        printf("string not found at any position");
     }
     else
     {
        printf("string found at %d position",index);
     
     }
   

}

