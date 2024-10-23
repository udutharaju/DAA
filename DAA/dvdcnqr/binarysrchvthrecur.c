#include <stdio.h>

int binarySearch(int array[], int x, int low, int high) {
  if (high >= low) {
    int mid = (low + high)/ 2;

    // If found at mid, then return it
    if (array[mid] == x)
      return mid;

    // Search the left half
    if (array[mid] > x)
      return binarySearch(array, x, low, mid - 1);

    // Search the right half
    else
    return binarySearch(array, x, mid + 1, high);
  }

  return -1;
 /* if(low==high)
  {
    if(array[low]==x)
    return low;
    else
    return 0;
  }
  else{
    int mid=(low+high)/2;
    if(x==array[mid])
    return mid;
    if(x<array[mid])
    return  binarySearch(array, x, low, mid - 1);
    else
   return binarySearch(array, x, mid + 1, high);

    
  }*/
}

int main() {
    int n,x;
    printf("enter n:");
    scanf("%d",&n);
  int array[n];
  printf("enter elements:");
  for(int i=0;i<n;i++)
  {
    scanf("%d",&array[i]);

  }
  printf("enter search element:");
  scanf("%d",&x);

  for(int i=0;i<n;i++)
  {
    for(int j=i+1;j<n;j++)
    {
        if(array[i]>array[j])
        {
        int t=array[i];
        array[i]=array[j];
        array[j]=t;
        }
    }
  }
  printf("sorted array:");
  for(int i=0;i<n;i++)
  {
    printf("%d  ",array[i]);
  }
  int result = binarySearch(array, x, 0, n - 1);
  if (result == -1)
    printf("Not found");
  else
    printf("Element is found at index %d", result);
}

