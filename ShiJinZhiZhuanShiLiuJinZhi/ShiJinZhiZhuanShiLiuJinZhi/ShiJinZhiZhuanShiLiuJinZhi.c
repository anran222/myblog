#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
int main()
{
	int i=0;
	char a[100];
	long m;
	int num;
	printf("请输入一个十进制数:");
	scanf("%d", &m);
	while (m > 0)
	{
		num =  m%16;
		switch (num)
		{
		case 0:a[i] = '0'; break;
		case 1:a[i] = '1';  break;
		case 2:a[i] = '2';  break;
		case 3:a[i] = '3';  break;
		case 4:a[i] = '4';  break;
		case 5:a[i] = '5';  break;
		case 6:a[i] = '6';  break;
		case 7:a[i] = '7'; break;
		case 8:a[i] = '8';  break;
		case 9:a[i] = '9';  break;
		case 10:a[i] = 'A';  break;
		case 11:a[i] = 'B';  break;
		case 12:a[i] = 'C';  break;
		case 13:a[i] = 'D';  break;
		case 14:a[i] = 'E'; break;
		case 15:a[i] = 'F';  break;
		}
		i++;
		m = m / 16;
	}
	printf("0x");
	for (i=i - 1; i >= 0; i--)
	{
		printf("%c", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}