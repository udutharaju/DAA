import java.util.*;
import java.io.*;
class matrixchainmultiplication{
    static int val;
     static int mcm(int a[],int d[][],int i,int j)
    {
        if(d[i][j]!=-1)
        {
            return d[i][j];
        }
        if(i==j)
        {
            return d[i][j]=0;
        }
        int min=Integer.MAX_VALUE;
        for(int k=i;k<j;k++)
        {
             val=mcm(a,d,i,k)+mcm(a,d,k+1,j)+a[i-1]*a[k]*a[j];
        
        if(val<min)
        {
            min=val;
        }
    }
    
        return d[i][j]=min;
    }
    public static void main(String...args){
        Scanner sc=new Scanner(System.in);
        System.out.println("enter n:");
        int n=sc.nextInt();
        int a[]=new int[n];
        int d[][]=new int[n+1][n+1];
        for(int i=0;i<n;i++)
        {
            a[i]=sc.nextInt();
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                d[i][j]=-1;
            }
        }
        System.out.println("minimum no of multiplications: "+mcm(a,d,1,n-1));
    }
}