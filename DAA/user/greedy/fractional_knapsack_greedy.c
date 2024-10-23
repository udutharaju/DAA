#include<stdio.h>
int frational(int wt[],int val[],double fr[],int W,int n )
{
  	double result=0;
	for(int i=0;i<n;i++)
	{
		if(wt[i]<=W)
		{
			result += val[i];
			W = W-wt[i];
		}
		else
		{
			result +=(double) W/wt[i]*val[i];
			break;
		} 
	}
	return result;
}
int main ()
{
	int W=0,n=0;
	printf("enter the number of items");
	scanf("%d",&n);
	double fr[n];
	int wt[n];
	int val[n];
	printf("enter the values \n");
	for(int i=0;i<n;i++)
	{
		printf("enter the wt of %d item :\n",i+1);
		scanf("%d",&wt[i]);
		printf("enter the value of %d item :\n",i+1);
 	 	scanf("%d",&val[i]);
	}	
	printf("enter the wight of the bag ::  ");
	scanf("%d",&W);
	for(int i=0;i<n;i++)
	{
		fr[i]=(double)val[i]/wt[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(fr[i]>fr[j])
			{
				int temp=fr[i];
				fr[i]=fr[j];
				fr[j]=temp;

				temp=val[i];
				val[i]=val[j];
				val[j]=temp;

				temp=wt[i];
				wt[i]=wt[j];	
				wt[j]=temp;
      		}
  		}
	}
printf("result :: %d ",frational(wt,val,fr,W,n));
}


