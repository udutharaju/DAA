#include<stdio.h>
#include<math.h>
struct point
    {
        int x,y;
    };
int main()
{
    int i,n,j,a,b,c,k,np,nn,count=0,f=0;
    printf("enter no of points:");
    scanf("%d",&n);
    struct point p[n];
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&p[i].x,&p[i].y);
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
          /** a=p[i].y-p[j].y;
            b=p[j].x-p[i].x;
            c=(p[j].x*p[i].y)-(p[i].x*p[j].y);*/
            a=p[j].y-p[i].y;
            b=p[i].x-p[j].x;
            c=(p[i].x*p[j].y)-(p[j].x*p[i].y);
            np=0,nn=0;
            for(k=0;k<n;k++)
            {
                int val=a*p[k].x+b*p[k].y-c;
                if(val>0)
                np++;
                else if(val<0)
                nn++;
            }
            if(np==0||nn==0)
            {
                count++;f=1;
                printf("convex");
                printf("(%d%d),(%d%d)\n",p[i].x,p[i].y,p[j].x,p[j].y);
                
            }
          /*  else if(np!=0||nn!=0)
            {
                printf("not convex");
                printf("(%d%d),(%d%d)\n",p[i].x,p[i].y,p[j].x,p[j].y);
            }*/
        }
    }
    //printf("convex and no of edges are %d",count);
    if(f==1)
    {
    printf("convex hull\n");
    printf("no of edges : %d",count);
    }
    else{
        printf("not convex");
    }
    
}
