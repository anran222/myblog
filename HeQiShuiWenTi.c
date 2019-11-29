#include<stdio.h>
#include<windows.h>
int main()
{
	int i=15;
	int sum = 0;
	int count = 0;
	while (i)
	{
		sum += i;
		i = i+count;
		count = i % 2;
		i = i / 2;

	}
	printf("%d", sum);
	system("pause");
	return 0;
}