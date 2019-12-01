#include<stdio.h>
#include<windows.h>
#define mod 1000000007
#pragma warning(disable:4996)
int main()
{
	int i, j,m;
	int k, l;
	long long a[100][100] = {0};
	scanf("%d %d", &k,&l);
	for (i = 1; i < k; i++)
	{
		a[1][i] = 1;
	}
	for (i = 2; i <= l; i++)
	{
		for (j = 0; j < k; j++)
		{
			for (m = 0; m < k; m++)
			{
				if (m != j - 1 && m != j + 1)
				{
					a[i][j] += a[i - 1][m];
					a[i][j] = a[i][j] % mod;
				}
			}
		}
	}
	long long sum = 0;
	for (j = 0; j < k; j++)
	{
		sum = sum+a[l][j];
		sum =sum % mod;
	}
	printf("%I64d", sum);
	printf("\n");
	system("pause");
	return 0;
}