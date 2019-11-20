#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
int main()
{
	int i;
	int j = 0;
	int k = 0;
	int a[100];
	int b[100];
	int c[100];
	int m;
	printf("请输入数组个数:\n");
	scanf("%d", &m);
	printf("请输入一串数字，用空格隔开:\n");
	for (i = 0; i < m; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = 0; i < m; i++)
	{
		if (a[i] % 2 != 0)
		{
			b[j] = a[i];
			j++;
		}
		else
		{
			c[k] = a[i];
			k++;
		}
	}
	for (i = 0; i < j; i++)
	{
		printf("%d ", b[i]);
	}
	for (i = 0; i < k; i++)
	{
		printf("%d ", c[i]);
	}
	system("pause");
	return 0;
}