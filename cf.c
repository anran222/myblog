#include<stdio.h>
#include<windows.h>
int main()//��ӡ9*9�˷��ھ���
{
	int i, j,num;
	for (i = 1; i <= 9; i++)//ѭ��9��---��������
	{
		for (j = 1; j <= i; j++)
		{
			num = i*j;
			printf("%3d*%d=%d",j,i, num);//��ӡÿ�еı��ʽ
		}
		printf("\n");
	}
	system("pause");
	return 0;
}