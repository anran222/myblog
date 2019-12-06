#include<stdio.h>
#include<windows.h>
int Fib1(int m)
{
	while (m >= 2)
	{
		return Fib1(m - 1) + Fib1(m - 2);
	}
	return 1;
}
int Fib2(int n)
{
	int num;
	int a = 1;
	int b = 1;
	if (n <= 1)
	{
		return 1;
	}
	else
	{
		for (int i = 2; i <= n; i++)
		{
			num = a + b;
			a = b;
			b = num;
		}
		return num;
	}
}
int main()
{
	int p = 8;
	printf("%d\n", Fib1(p));
	printf("%d\n", Fib2(p));
	system("pause");
	return 0;
}