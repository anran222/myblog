#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
int main()
{
	int sn = 0;//用来计算所有数的和
	int a = 0;
	int i,j;
	printf("请输入一个数\n");
		scanf("%d", &a);
		j = a;//给定第一个数的值
		sn = j;
	for (i = 0; i < 4; i++)//用循环来控制每一个数的位数
	{
		a = a * 10+j;
		sn+=a;
	}
	printf("%d\n", sn);//输出最后的结果
	system("pause");
		return 0;
}