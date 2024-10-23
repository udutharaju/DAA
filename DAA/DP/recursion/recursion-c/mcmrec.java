import java.util.*;
import java.io.*;
class matrixchainmultiplication{
     int val;
 int mcm(int a[],int i,int j)
    {
        
        if(i==j)
        {
            return 0;
        }
        int min=Integer.MAX_VALUE;
        for(int k=i;k<j;k++)
        {
             val=mcm(a,i,k)+mcm(a,k+1,j)+a[i-1]*a[k]*a[j];
        
        if(val<min)
        {
            min=val;
        }
        }
    
        return min;
    }
}
class m{
    public static void main(String...args){
        Scanner sc=new Scanner(System.in);
        System.out.println("enter n:");
        int n=sc.nextInt();
        int a[]=new int[n];
        for(int i=0;i<n;i++)
        {
            a[i]=sc.nextInt();
        }
        matrixchainmultiplication m1=new matrixchainmultiplication();
        System.out.println("minimum no of multiplications: "+m1.mcm(a,1,n-1));
    }
}