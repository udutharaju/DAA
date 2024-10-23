//package backtracking;

import java.util.*;
class hamiltonian
{
    int a[];
    int adj[][];
    int c=0;
    int f=0;
    hamiltonian(int n)
    {
        a=new int[n];
        adj=new int[n][n];
    }
    void fill(int n,int k)
    {
        if(k==n)
        {
          if(adj[a[n-1]][a[0]]!=0)
          {
            for(int i=0;i<n;i++)
            {
                System.out.print(" "+a[i]);
            }
            System.out.print(" "+a[0]);
            System.out.println();
            c++;
            f=1;
            }
            return;
            
            }
        
        for(int i=0;i<n;i++)
        {
            if(issafe(k,i,n))
            {
                a[k]=i;
                fill(n,k+1);
            }
        }
    }
    boolean issafe(int k,int i,int n)
    {
        for(int j=0;j<k;j++)
        {
            if(a[j]==i)
            return false;
            if(adj[a[k-1]][i]==0)
            return false;
            if(k==n-1&&adj[i][a[0]]==0)
            return false;
        }
        return true;
    }
    public static void main(String...args)
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("enter the size:");
        int n=sc.nextInt();
        hamiltonian h=new hamiltonian(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
               h.adj[i][j]=sc.nextInt();
            }
        }
        h.fill(n,0);
        if(h.c==0)
        {
        System.out.println("cycle does not exist:"+h.c);
        }
        else{
            System.out.println("cycle exist:"+h.c);
        }
    }
}



/*time complexity: O(n!)*/

