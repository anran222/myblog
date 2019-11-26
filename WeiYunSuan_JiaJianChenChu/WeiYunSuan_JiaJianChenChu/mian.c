#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
int Add(int a, int b)
{
	int sum;
	int num;
	do{
		sum = a^b;
		num = (a&b) << 1;
		a = sum;
		b = num;
	} while (b != 0);
		return a;
}
int Sub(int a, int b)
{
	b = ~b;
	int result;
	result=Add(a, Add(b, 1));
	return result;
}
int Mul(int a, int b)
{
	int res = 0;
	while (b != 0)
	{
		if (b & 1)
		{
			res = Add(res, a);
		}
		a = a << 1;
		b = b >> 1;
	}
	return res;
}
int Div(int a, int b)
{
	int res = 0;
	while (a>=b)
	{
		a = Sub(a, b);
		res = Add(res, 1);
	}
	return res;
}
int main()
{
	int select;
	int m, n;
	int result;
	while (1)
	{
		printf("**********************\n");
		printf("****1.�ӷ�   2.����***\n");
		printf("****3.�˷�   4.����***\n");
		printf("**********************\n");
		printf("��ע�⣬�����г�������ʱ���õ��Ľ��Ϊȡ�������\n");
		printf("��ѡ����Ҫ���еĲ���:");
		scanf("%d", &select);
		printf("������Ҫ���������������:\n");
		scanf("%d %d", &m, &n);
		switch (select)
		{
		case 1:result = Add(m, n); break;
		case 2:result = Sub(m, n); break;
		case 3:result = Mul(m, n); break;
		case 4:result = Div(m, n); break;
		}
		printf("%d\n", result);
	}
	system("pause");
	return 0;
}