#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
int Gongyue(int a,int b)
{
	int num=1;
	if (a < b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	while (num)
	{
		num = a % b;
		a = b;
		b = num;
	}
	return a;
}
int Gongbei(int a, int b)
{
	int result;
	result = (a*b) / Gongyue(a, b);
	return result;
}
int main()
{
	int m;
	int i, j, k;
	int max = 0;
	scanf("%d", &m);
	for (i = 1; i <= m-2; i++)
	{
		for (j = i+1; j <= m - 1; j++)
		{
			int result = Gongbei(i, j);
			for (k = i + 2; k <= m; k++)
			{
				int num = Gongbei(k, result);
				if (num>max)
				{
					max = num;
				}
			}
		}
	}
	printf("%d\n", max);
	system("pause");
	return 0;
}