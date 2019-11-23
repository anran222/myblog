#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
int Fac(int n, int k)
{
	if (k == 0 || k == n)
	{
		return k;
	}
	else
	{
		return Fac(n - 1, k) + Fac(n - 1, k - 1);
	}
}
int main()
{
	printf("«Î ‰»În∫Õk:\n");
	int n, k;
	scanf("%d %d", &n, &k);
	int result = Fac(n, k);
	printf("%d\n", result);
	system("pause");
	return 0;
}