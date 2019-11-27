#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
int main()
{
	int m;
	int i;
	int b[100];
	int num=0;
	printf("请输入要输入的个数:");
	scanf("%d", &m);
	for (i = 0; i < m; i++)
	{
		scanf("%d", &b[i]);
	}
	for (i = 0; i < m; i++)
	{
		num = num^b[i];
	}
	printf("%d", num);
	system("pause");
	return 0;
}