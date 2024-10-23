#include<stdio.h>
#include<math.h>
#include<limits.h>

struct point
{
    int x,y;
};
int main ()
{
    struct point p[10];
    int i,n,j,x1,y1;
    double sum,avgdistance, distance;
    printf("enter the no.of villages:");
    scanf("%d",&n);
    for(i =0;i<n;i++)
    {
          printf("enter the %d village boundary: ",i+1);
          scanf("%d%d",&p[i].x,&p[i].y);
    }
    double max = INT_MIN;
    for(i=0;i<n;i++)
    {
        sum = 0;
        for(j=0;j<n;j++)
        {
            distance = sqrt(pow(p[j].x -p[i].x,2) +pow(p[j].y - p[i].y,2));
            sum += distance;
        }
        avgdistance =sum/(n-1);
        if(avgdistance>max)
        {
            max =avgdistance;
            x1=p[i].x;
            y1=p[i].y;
        }
    }
    printf("pharmacy should be located in %d%d and at a distance of %lf",x1,y1,max);
    
}