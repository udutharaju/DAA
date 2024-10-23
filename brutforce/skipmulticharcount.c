#include<stdio.h>
#include<string.h>
int main()
{
	char str1[100],str2[100];
	int i,j;
	
	printf("Enter string1:");
	scanf("%s",str1);
	printf("Enter string2:");
	scanf("%s",str2);
	//str1[strcspn(str1,"\n")]='\0';
	//str2[strcspn(str2,"\n")]='\0';
	
	int m=strlen(str1);
	int n=strlen(str2);
	printf("Length of str1 is %d\n",m);
	printf("Length of str2 is %d\n",n);
	
	int f1=0,index=-1,count=0;
	for(i=0;i<=m-n;i++)
	{
		if(str1[i]==str2[0])
		{
			int f=0;
			int current=i;
			for(j=0;j<n;j++,current=current+j+1)
			{	
				
				if(str2[j]!=str1[current])
				{
					f=1;
					break;
				}
				
			}
			if(f==0)
			{	
				f1=1;
				index=i;
				count++;
				printf("Substring is found at index %d\n",index);
			}
		}
	}
	if(f1==0)
	{
		printf("String doesn't match.");
	}
	else
	{
		//printf("String matches\n");
		printf("Count of Substrings:%d\n",count);
	}
	return 0;
}
