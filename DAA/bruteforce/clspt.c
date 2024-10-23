#include<stdio.h>
#include<math.h>
struct point
{
    int x;
    int y;
};
void main()
{
    int x1,y1,x2,y2,n,i,j;
    float dst;
    struct point p[10];
    printf("enter rhe no of points");
    scanf("%d",&n);
    printf("enter coordintes for %d points",n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&p[i].x,&p[i].y);
    }
    float min=1000000;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            dst=sqrt(pow(p[i].x-p[j].x,2)+pow(p[i].y-p[j].y,2));
            if(dst<min)
            {
                x1=p[i].x;
                y1=p[i].y;
                x2=p[j].x;
                y2=p[j].y;
                min=dst;
            }
        }
    }
    printf("the closest points are(%d,%d) and (%d,%d) distance %f",x1,y1,x2,y2,min);
}
