
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

struct point
{
    int x, y;
};

void quicksort(struct point p[], int low, int high);
double closestpair(struct point p[], int start, int end);
double bruteforce(struct point p[], int start, int end);

void quicksort(struct point p[], int low, int high)
{
    if(low < high)
    {
        int i = low, j = high;
        struct point pivot = p[low], temp;

        while(i < j)
        {
            while(p[i].x <= pivot.x )
            {
                i++;
            }   
            while(p[j].x > pivot.x)
            {
                j--;
            }
            if (i < j)
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }

        temp = p[low];
        p[low] = p[j];
        p[j] = temp;

        quicksort(p, low, j-1);
        quicksort(p, j+1, high);
    }
}

double closestpair(struct point p[], int start, int end)
{
    struct point s[20];
    int k = 0;

    if (end > start + 1)
    {
        int mid = start + (end - start) / 2;
        double ld = closestpair(p, start, mid);
        double rd = closestpair(p, mid + 1, end);

        double d = ld < rd ? ld : rd;

        for(int i = start; i <= end; i++)
        {
            if (abs(p[i].x - p[mid].x) < d)
            {
                s[k++] = p[i];
            }
        }
       
        double sm = bruteforce(s, 0, k - 1);
        return d < sm ? d : sm; 
    }
    else
    {
        return bruteforce(p, start, end); 
    }
}

double bruteforce(struct point p[], int start, int end)
{
    float min = INFINITY;
    
    
    for(int i = start; i<end; i++)
    {
        for (int j = i + 1; j <= end; j++) 
        {
            float d = sqrt(pow(p[i].x - p[j].x, 2) + pow(p[i].y - p[j].y, 2));
            if (d < min)
            {
                min = d;
                
            }
        }
    }
    return min; 
}

int main()
{
    int n;
    printf("Enter the no.of points.");
    scanf("%d",&n);
    struct point p[n];
    printf("Enter %d no of points \n",n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&p[i].x,&p[i].y);
    }
    quicksort(p, 0, n-1);
    
    double d = closestpair(p, 0, n - 1); 

    printf("\n the min value %f",d);
    
    return 0; 
}
