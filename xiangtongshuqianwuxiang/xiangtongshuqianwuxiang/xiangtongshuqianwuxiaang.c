#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
int main()
{
	int sn = 0;//���������������ĺ�
	int a = 0;
	int i,j;
	printf("������һ����\n");
		scanf("%d", &a);
		j = a;//������һ������ֵ
		sn = j;
	for (i = 0; i < 4; i++)//��ѭ��������ÿһ������λ��
	{
		a = a * 10+j;
		sn+=a;
	}
	printf("%d\n", sn);//������Ľ��
	system("pause");
		return 0;
}