#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
int main()
{
	int num1;
	int num2;
	printf("�������һ����:");
	scanf("%d", &num1);
	printf("������ڶ�����:");
	scanf("%d", &num2);
	int sum, carry;
	do{
		sum = num1^num2;
		carry = (num1&num2) << 1;
		num1 = sum;
		num2 = carry;
	} while (num2 != 0);
	printf("%d\n", num1);
	system("pause");
	return 0;
}