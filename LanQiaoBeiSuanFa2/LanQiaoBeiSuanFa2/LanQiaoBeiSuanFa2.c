#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
int main()
{
	long long result;
	long long m;
	printf("请输入一个数:");
	scanf("%I64d", &m);
	if (m <= 2)
	{
		result = m;
	}
	else if (m % 2 != 0)
	{
		result = m*(m - 1)*(m - 2);
	}
	else if (m % 3 != 0)
	{
		result = m*(m - 1)*(m - 3);
	}
	else
	{
		result = (m - 1)*(m - 2)*(m - 3);
	}
	printf("%I64d\n", result);
	system("pause");
	return 0;
}