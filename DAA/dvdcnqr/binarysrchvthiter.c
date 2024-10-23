#include <stdio.h>

int binarySearch(int array[], int x, int low, int high) {
  // Repeat until the pointers low and high meet each other
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (array[mid] == x)
      return mid;

    if (array[mid] < x)
      low = mid + 1;

    else
      high = mid - 1;
  }

  return -1;
}

int main(void) {
  int n,i;
  //int array[] = {3, 4, 5, 6, 7, 8, 9};
  printf("enter the array");
  scanf("%d",&n);
  int array[n];
  printf("enter the ele:");
  for(i=0;i<n;i++)
  {
  	scanf("%d",&array[i]);	
  }
  //int n = sizeof(array) / sizeof(array[0]);
  int x = 4;
  int result = binarySearch(array, x, 0, n - 1);
  if (result == -1)
    printf("Not found");
  else
    printf("Element is found at index %d", result);
  return 0;
}

