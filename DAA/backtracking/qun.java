//package backtracking;
import java.util.*;
import java.lang.Math;
class qun
{
    int q[];
    int c=0;
    qun(int n)
    {
        q=new int[n];
    }
    void qn(int n,int k)
    {
        if(k>n)
        {
            for(int i=0;i<n;i++)
            {
                System.out.print(" "+q[i]);
            }
            System.out.println("");
            c++;
            return;
        }
       // for(int i=0;i<n;i++)   1302 2301
       
       for(int i=1;i<=n;i++)    //2413 3142
        {
            if(isattack(k,i))
            {
                q[k-1]=i;
                qn(n,k+1);
            }
        }


    }
    boolean isattack(int k,int i)
    {
        for(int j=1;j<k;j++)
        {
            if(q[j-1]==i)
            return false;
            if(Math.abs(k-j)==Math.abs(i-q[j-1]))
            return false;
        }
        return true;
        
    }
}
class bt
{
    public static void main(String...args)
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("enter the size:");
        int n=sc.nextInt();
        qun t=new qun(n);
        t.qn(n,1);
        System.out.println("no of ways:"+t.c);
    
    }
}


/*time complexity: O(n!)*/

