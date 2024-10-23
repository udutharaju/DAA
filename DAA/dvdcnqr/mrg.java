import java.util.*;
class mrg
{
    public static void main(String...args)
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("enter n:");
        int n=sc.nextInt();
        int arr[]=new int[n];
        for(int i=0;i<n;i++)
        {
            arr[i]=sc.nextInt();
        }
        System.out.println("before sorting:");
        for(int i=0;i<n;i++)
        {
            System.out.print(arr[i]+" ");
        }
        mrg m=new mrg();
        m.mergesort(arr,0,n-1);
        System.out.println("after sorting:");
        for(int i=0;i<n;i++)
        {
            System.out.print(arr[i]+" ");
        }

    }
    void mergesort(int arr[],int low,int high)
    {
        int mid;
        if(low<high)
        {
         mid=(low+high)/2;
         mergesort(arr,low,mid);
         mergesort(arr,mid+1,high);
         merge(arr,low,mid,high);
        }
    }
    void merge(int a[],int low,int mid,int high)
   {
      int i,j,k;
      int b[]=new int[50];
      i=low;
      j=mid+1;
      k=low;
    while(i<=mid&&j<=high)
    {
      if(a[i]<=a[j])
      {
        b[k++]=a[i++];
      }
      else
      {
        b[k++]=a[j++];
      }
    }

    
    while(i<=mid)
    {
      b[k++]=a[i++];
    }
    while(j<=high)
    {
      b[k++]=a[j++];
    }
    

    for(k=low;k<=high;k++)
    {
       a[k]=b[k];
    }
  }

}