#include<stdio.h>
#include<string.h>
#include<windows.h>
#pragma warning(disable:4996)
int main()
{
	long i, j;
	long m, n;
	int a[1000];
	printf("�������г���:");
	scanf("%d", &m);
	printf("���������У�ÿ�����ÿո����:");
	for (i = 0; i < m; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("������ѯ�ʸ���:");
	scanf("%d", &n);
	int l, r, k;
		scanf("%d %d %d", &l, &r, &k);
		for (i = l - 1; i < r; i++)
		{
			for (j = l - 1; j < r - 1 - i; j++)
			{
				if (a[j] < a[j + 1])
				{
					long temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
				}
			}
		}
		printf("%d\n", a[k - 1]);
	system("pause");
	return 0;
}