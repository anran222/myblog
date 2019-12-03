#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
int main()
{
	int num;
	int n;
	int jw = 0;
	int i, j, k;
	int d = 0;
	int a[10000] = { 1 };
	printf("«Î ‰»În:");
	scanf("%d", &n);
	for (i = 2; i <= n; i++)
	{
		for (k = 0; k <= d; k++)
		{
			num = a[k] * i + jw;
			a[k] = num % 10;
			jw = num / 10;
		}
		while (jw)
		{
			a[k] = jw % 10;
			jw = jw / 10;
			k++;
		}
		d = k - 1;
	}
	for (j = d; j >= 0; j--)
	{
		printf("%d", a[j]);
	}
	printf("\n");
	system("pause");
	return 0;
}