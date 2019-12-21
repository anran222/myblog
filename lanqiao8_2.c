#include<stdio.h>
int main()
{
	int m,n;
	int count=0;
	scanf("%d %d",&m,&n);
	int i;
	int j=0;
	int a[100]={0};
	int b[100]={0};
	for(i=0;i<m;i++)
	{
		scanf("%d",&a[i]);
		b[j]=a[i];
		j++;
	}
	int sum=0;
	for(i=0;i<m;i++)
	{
		sum=a[i];
	if((sum)%n==0)
		{
			count++;
		}
		for(j=i+1;j<m;j++)
		{
			sum+=b[j];
			if((sum)%n==0)
			{
				count++;
			}
		}
	 }
	 printf("%d",count); 
	return 0;
 } 
