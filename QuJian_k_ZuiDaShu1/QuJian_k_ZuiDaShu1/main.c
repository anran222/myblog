#include<stdio.h>
#include<string.h>
#include<windows.h>
#pragma warning(disable:4996)
int main()
{
	long i, j;
	long m, n;
	int a[1000];
	printf("输入序列长度:");
	scanf("%d", &m);
	printf("请输入序列，每个数用空格隔开:");
	for (i = 0; i < m; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("请输入询问个数:");
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