#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#pragma warning(disable:4996)
int main()
{
	char a[8001];
	int flag = 0;
	int n, sum = 0;
	scanf("%d", &n);
	getchar();
	gets(a);
	int i, j, k, m;
	j = n - 1;
	for (i = 0; i<j; ++i)
	for (k = j; k >= i; --k)
	{
		if (i == k)
		{
			if (n % 2 == 0)
			{
				printf("Impossible");
				return 0;
			}
			else
			{
				if (flag)
				{
					printf("Impossible");
					return 0;
				}
			}
			sum += n / 2 - i;
			flag = 1;
			break;
		}
		if (a[i] == a[k])
		{
			for (m = k; m<j; ++m)
			{
				a[m] = a[m + 1];
				sum++;
			}
			a[j] = a[i];
			--j;
			break;
		}
	}
	printf("%d", sum);
	system("pause");
	return 0;
}
