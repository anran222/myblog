#include"game.h"

void menu()
{
	printf("****************************\n");
	printf("*****��ӭ������������Ϸ*****\n");
	printf("****************************\n");
	printf("****************************\n");
	printf("*****1.��ʼ      2.�˳�*****\n");
	printf("****************************\n");
}
int main()
{
	int select = 0;
	int flag = 0;
	while (!flag)//�������ѡ���Ƿ������Ϸ
	{
		menu();//��ʾ���ʼ���ѡ�����
		printf("��ѡ����Ҫ���еĲ���:\n");
		scanf("%d", &select);
		switch (select)
		{
		case 1://������ѡ��ʼ��Ϸ����ô��Ϸ��ʼ
			Game();
			break;
		case 2://������ѡ���˳����������Ϸ
			flag = 1;
			printf("bye bye!\n");
			break;
		default:
			printf("enter error!please enter again:\n");
				break;
		}
	}
	system("pause");
	return 0;
}