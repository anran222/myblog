#include<stdio.h>
#include<windows.h>
int main()//打印9*9乘法口诀表
{
	int i, j,num;
	for (i = 1; i <= 9; i++)//循环9次---控制行数
	{
		for (j = 1; j <= i; j++)
		{
			num = i*j;
			printf("%3d*%d=%d",j,i, num);//打印每行的表达式
		}
		printf("\n");
	}
	system("pause");
	return 0;
}