#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)
int main()
{
	int flag = 0;
	int flag1 = 0;
	int flag2 = 0;
	int i,j;
	int m;
	int number;
	int juzhen[10][10] = { 0 };
	printf("请输入矩阵大小:");
	scanf("%d", &m);
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d",&juzhen[i][j]);
		}
	}
	printf("\n");
	for (i = 0; i < m; i++)
	{
		j = 0;
		while (j < m-1)
		{
			if (juzhen[i][j] < juzhen[i][j + 1])
			{
				j++;
			}
			else
			{
				flag1 = 1;
				break;
			}
		}
	}
	for (j = 0; j< m; j++)
	{
		i = 0;
		while (i < m-1)
		{
			if (juzhen[i][j] < juzhen[i+1][j])
			{
				i++;
			}
			else
			{
				flag2 = 1;
				break;
			}
		}
	}
	if ((flag1 == 0)&&(flag2==0))
	{
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < m; j++)
			{
				printf("%d ",juzhen[i][j]);
			}
			printf("\n");
		}
	}
	else
	{
		printf("矩阵不是杨氏矩阵!\n");
	}
	printf("\n");
	printf("请输入你想查询的数:\n");
	scanf("%d", &number);
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (juzhen[i][j] == number)
			{
				flag = 1;
				break;
			}
		}
	}
	if (flag)
	{
		printf("存在!\n");
	}
	else
	{
		printf("不存在!\n");
	}
		system("pause");
	return 0;

}