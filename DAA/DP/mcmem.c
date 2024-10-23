#include<stdio.h>
#include<limits.h>
 int val;
     int mcm(int n,int a[n],int i,int j)
    {
    int d[n+1][n+1];
     for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                d[i][j]=-1;
            }
        }
        if(d[i][j]!=-1)
        {
            return d[i][j];
        }
        if(i==j)
        {
            return d[i][j]=0;
        }
        int min=INT_MAX;
        for(int k=i;k<j;k++)
        {
             val=mcm(n,a,i,k)+mcm(n,a,k+1,j)+a[i-1]*a[k]*a[j];
        
        if(val<min)
        {
            min=val;
        }
    }
    
        return d[i][j]=min;
    }
    int main()
    {
       printf("enter n:");
        int n;
        scanf("%d",&n);
        int a[n];
    
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
       
       printf("minimum no of multiplications:%d ",mcm(n,a,1,n-1));
    }

