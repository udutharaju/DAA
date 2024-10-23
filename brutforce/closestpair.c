#include<stdio.h>
#include<math.h>

struct point
{
    int x;
    int y;
};
void main ()
{   
    int i,n,j,x1,x2,y1,y2,distance;
    struct point p [10];
    printf("enter the no.of points u want:");
    scanf("%d",&n);
    
    printf("enter the %d points ",n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&p[i].x,&p[i].y);
    }
    int min = 1000000;
    for(i =0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            distance =sqrt(pow(p[i].x-p[j].x,2)+pow(p[i].y-p[j].y,2));
            if(distance<min)
            {
                min =distance;
                x1 = p[i].x;
                y1 = p[i].y;
                x2 = p[j].x;
                y2 = p[j].y;
            }
        }
    }
    printf("closest pair are %d%d and %d%d distance %d",x1,y1,x2,y2,min);
  
}
