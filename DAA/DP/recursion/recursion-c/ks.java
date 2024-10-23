import java.util.*;
class knapsack{
    int []wt;
    int []val;
    int n,w,i;
    public knapsack(int n,int w)
    {
        this.n=n;
        this.w=w;

    }
    void read()
    {
        Scanner sc=new Scanner(System.in);
        wt=new int[n];
        val=new int[n];
        System.out.println("enter weights:");
        for(i=0;i<n;i++)
        {
            wt[i]=sc.nextInt();
            
        }
        System.out.println("enter values:");
        for(i=0;i<n;i++)
        {
          
            val[i]=sc.nextInt();
        }
    }
    int ks(int n,int w)
    {
        if(n==0||w==0)
        {
            return 0;
        }
        if(wt[n-1]<=w)
        {
            int a=val[n-1]+ks(n-1,w-wt[n-1]);
        int b=ks(n-1,w);
        int max;
        if(a>b)
        {
            max=a;
        }
        else if(a<b)
        {
            max=b;
        }
        else
        {
            max=a;
        }

        return max;
            
        }
        else
        {
            return ks(n-1,w);
        }
    }
    public static void main(String...args)
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("enter n:");
        int n=sc.nextInt();
        System.out.println("enter w:");
        int w=sc.nextInt();
        knapsack k=new knapsack(n,w);
        
        k.read();
        System.out.println(k.ks(n,w));
    }
}