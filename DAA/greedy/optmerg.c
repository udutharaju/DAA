#include <stdio.h>
#include <stdlib.h>
int optimalMerge(int files[], int n)
{
  
    swap(files,n);
    int cost = 0;
    while (n > 1) {
        int mergedFileSize = files[0] + files[1];
        cost += mergedFileSize;
        files[0] = mergedFileSize;
        // Shift the remaining files to the left
        for (int i = 1; i < n - 1; i++) {
            files[i] = files[i + 1];
        }
        n--; // Reduce the number of files
        // Sort the files again
        swap(files,n);
        
    }
    return cost;
}
int swap(int files[],int n)
    {
    for(int i=0;i<n;i++)
    {
    for(int j=i+1;j<n;j++)
    {
    if(files[i]>files[j])
    {
    int t=files[i];
    files[i]=files[j];
    files[j]=t;
    }
    }
    }
    }
int main()
{
   
    int n;
    printf("enter n:");
    scanf("%d",&n);
    int files[n];
    printf("enter files:");
    for(int i=0;i<n;i++)
    {
    scanf("%d",&files[i]);
    }
    int minCost = optimalMerge(files, n);
    printf("Minimum cost of merging is: %d Comparisons\n", minCost);
    return 0;
}
