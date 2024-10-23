

#include <stdio.h>
int count = 0;
void sum(int a[], int i, int s, int w, int n) {
    if (w == s) {
        count += 1;
        return;
    }
    if (w> s || i == n) {
        return;
    }
    // Include current number
    sum(a, i + 1, s, w + a[i], n);
    // Exclude current number
    sum(a, i + 1, s, w, n);
}


int main()
{
    int n,s;
    printf("enter n:");
    scanf("%d",&n);
    int a[n];
    printf("enter the elements:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter weight:");
    scanf("%d",&s);
    sum(a, 0, s, 0, n);
    if(count==0)
    printf("not found");
    else
    printf("Number of subsets: %d\n", count);
}

