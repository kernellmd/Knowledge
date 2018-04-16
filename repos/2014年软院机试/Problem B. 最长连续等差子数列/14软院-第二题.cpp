#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			int x;
			scanf("%d",&x);
			if(x==1)
			{
				int y;
				scanf("%d",&y);
				printf("%d\n",x);
				continue;
			}
			int a[x],b[x],c[x];
			int k=0;
			for(int j=0;j<x;j++)
			{
				scanf("%d",&a[j]);
				if(j!=0)
				{
				    b[k++]=a[j]-a[j-1];
				}	
			}
			int number=2;
			int r=0;
			for(int j=0;j<k;j++)
			{
				if(b[j]==b[j+1])
				{
					number++;
				}
			   	else
				{
			    	c[r++]=number;
			    	number=2;
				}	
			}
			if(r==0)
			printf("%d\n",number);
			else
			{
			  sort(c,c+r);
			  printf("%d\n",c[r-1]);
			}
		}
	}
	return 0;
}
