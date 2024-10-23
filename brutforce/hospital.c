#include<stdio.h>
#include<math.h>
#include<limits.h>

struct point
{
    int x;
    int y;
};
int main ()
{
    int i,j,x1,x2,y2,y1,n;
    double  sum, distance,avgdistance;
    struct point p[10];
    printf("enter the no.of villages nearby:");
    scanf("%d",&n);
    printf("enter the villages borders:");
    for(i=0;i<n;i++)
    {
         scanf("%d%d",&p[i].x,&p[i].y);
    }
    double min = INT_MAX;
    for(i=0;i<n;i++)
    {
            sum=0;
        for(j=0;j<n;j++)
        {
            
                distance = sqrt(pow(p[j].x-p[i].x,2) + pow(p[j].y-p[i].y,2));
                sum += distance;
        }
                avgdistance = sum/(n-1);
                if(avgdistance<min)
                {
                    min=avgdistance;
                    x1 =  p[i].x;
                    y1 = p[i].y; 
                }
        
    }
    printf("equally distanced village for all villages border are %d %d and distance is %lf",x1,y1,min);
}