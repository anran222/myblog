#include<stdio.h>
#include<string.h>
#include<windows.h>
#pragma warning(disable:4996)
int main()
{
	int i=0;
	int m;
	int num;
	char a[100];//����һ�����飬����������ǽ�Ҫ������ַ���
	printf("������һ���ַ���:\n");
	scanf("%s",a);//���ַ������������Ѿ�����õ�������
	printf("��������Ҫ�����Ĵ���:");//��������Ҫ�����Ĵ���
	scanf("%d", &m);
	num = strlen(a);//���ַ����ĳ���
	while (m)///ȷ������Ҫ�����Ĵ���
	{
		char temp = a[0];//��һ���м�ֵ
		for (i= 0; i < num-1; i++)
		{
			a[i] = a[i + 1];//��ÿһλ��ǰ��һλ
		}
		a[i] = temp;//����һ��ֵ�����һλ
		m--;
	}
	printf("%s", a);
	system("pause");
	return 0;
}