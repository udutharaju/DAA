import java.util.*;
import java.lang.Math;
class bt
{
 int dp[][];
 int a[];
 bt(int n)
 {
  a=new int[n];
  dp=new int[n][n];
  
  }
 int mcm(int n)
 {
 for(int l=0;l<n;l++)
  {
   for(int i=1;i<n-l;i++)
   {
    int j=i+l;
    
    if(i==j)
   {
    dp[i][j]=0;
    continue;
    }
   dp[i][j]=Integer.MAX_VALUE;
  int value;
  for(int k=i;k<j;k++)
  {
   value=dp[i][k]+dp[k+1][j]+a[i-1]*a[k]*a[j];
   if(value<dp[i][j])
    
  dp[i][j]=value;
  }
  }
 }
  return dp[1][n-1];
 }
}

class test
{
 public static void main(String...args)
 {
  Scanner sc=new Scanner(System.in);
  System.out.println("enter the array size");
  int n=sc.nextInt();
  bt b=new bt(n);
  System.out.println("enter the array elements");
  for(int i=0;i<n;i++)
  {
   b.a[i]=sc.nextInt();
   }
 int min=b.mcm(n);
  System.out.println("min value;"+ min);
  }
 }
   
