import java.util.*;
class obst
{
    int n;
    int keys[];
    int freq[];
    int a[][];
    obst(int n,int keys[],int freq[])
    {
        this.n=n;
        this.keys=keys;
        this.freq=freq;
        a=new int[n+2][n+2];
    }
    int fill(int i,int j)
    {
        for(int l=0;l<j;l++)
        {
            for(int row=i;row<=j-l;row++)
            {
                int col=l+row;
                int min=Integer.MAX_VALUE;
                if(row>col){
                    a[row][col]=0;
                    continue;
                }
                    if(row==col){
                        a[row][col]=freq[row];
                        continue;
                    }
                    for(int k=row;k<=col;k++)
                    {
                        int val=a[row][k-1]+a[k+1][col]+sum(row,col);
                        if(val<min)
                        {
                            min=val;
                        }
                    }
                    a[row][col]=min;

                }
                
            }
            return a[1][n];
        }
    
    int sum(int m,int n)
    {
        int sum=0;
        for(int i=m;i<=n;i++)
        {
            sum+=freq[i];
        }
        return sum;
    }
    public static void main(String...args)
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("enter n:");
        int n=sc.nextInt();
        int keys[]=new int[n];
        System.out.println("enter keys:");
        for(int i=0;i<n;i++)
        {
            keys[i]=sc.nextInt();
        }
        int freq[]=new int[n];
        System.out.println("enter frequencies:");
        for(int i=1;i<=n;i++)
        {
            freq[i]=sc.nextInt();
        }
        obst bt=new obst(n,keys,freq);
       int t= bt.fill(1,n);
       System.out.println(t);
        
   }
}