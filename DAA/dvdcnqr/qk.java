import java.util.*;
class qk{
    public static void main(String...args)
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("enter n:");
        int n=sc.nextInt();
        System.out.println("enter the elements: ");
        int arr[]=new int[n];
        for(int i=0;i<n;i++)
        {
            arr[i]=sc.nextInt();
        }
        System.out.println("before sorting :");
        for(int i=0;i<n;i++)
        {
            System.out.print(arr[i]+" ");
        }
        qk q=new qk();
        q.quick(arr,0,n-1);
        System.out.println("after sorting :");
        for(int i=0;i<n;i++)
        {
            System.out.print(arr[i]+" ");
        }
     }
     void quick(int a[],int low,int high)
     {
        int i,j,pivot,t;
        if(low<high)
        {
            i=low;
            j=high;
            pivot=low;
        
        while(i<j)
        {
            while(a[i]<=a[pivot])
            i++;
            while(a[j]>a[pivot])
            j--;
            if(i<j)
            {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
        t=a[j];
        a[j]=a[pivot];
        a[pivot]=t;
        quick(a,low,j-1);
        quick(a,j+1,high);
     }
    }
}