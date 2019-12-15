#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
int main()
{
	int a[100][100] = { 0 };
	int b[100][100] = { 0 };
	int c[100][100] = { 0 };
	int i, j, k;
	int m, s, n;
	scanf("%d %d %d", &m, &s, &n);
	for (i = 0; i<m; i++)
	{
		for (j = 0; j<s; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	for (j = 0; j<s; j++)
	{
		for (k = 0; k<n; k++)
		{
			scanf("%d", &b[j][k]);
		}
	}
	for (i = 0; i<m; i++)
	{
		for (k = 0; k<n; k++)
		{
			for (j = 0; j<s; j++)
			{
				c[i][k] += a[i][j] * b[j][k];
			}
		}
	}
	for (i = 0; i<m; i++)
	{
		for (k = 0; k<n; k++)
		{
			printf("%2d", c[i][k]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}