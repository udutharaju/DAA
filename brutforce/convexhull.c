#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
struct point{
	int x,y;
};

int main(){
	struct point p[10];
	int n,i,j,k;
	printf("Enter no.of points");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter points value:");
		scanf("%d%d",&p[i].x,&p[i].y);
	}
	for(i=0;i<n;i++)
	{
		printf("%d%d\n",p[i].x,p[i].y);
	}
	int a=0,b=0,c=0,value=0;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			a=p[j].y-p[i].y;
			b=p[i].x-p[j].x;
			c=(p[i].x*p[j].y)-(p[i].y-p[j].x);
			int np=0,nn=0;
			for(k=0;k<n;k++)
			{
				value=(a*p[k].x)+(b*p[k].y)-c;
				if(value>0)
					np++;
				else if(value<0)
					nn++;
			}
			if(np==0 || nn==0)
			{
				printf("%d %d are convex hull.",p[i].x,p[i].y);
			}printf("\n");
		}
	}
}
