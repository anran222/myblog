#include<stdio.h>
#include<windows.h>
#include<time.h>
#pragma warning(disable:4996)
#define USER "anran"//ȷ��һ��������˺�
#define PSD "565656"//ȷ��һ�����������
void game()
{
	srand(time(NULL));//���ú�����������������ǽ�Ҫ����������ж�
	int n = rand() % 100 + 1;
	int num = 0;
	do{
		printf("please enter guess num;");//�������ǲ²������
		scanf("%d", &num);
		if (n < num)
		{
			printf("guess big\n");//������������������ʾ��������������
		}
		else if (n>num)
		{
			printf("guess small\n");//������������С������ʾ������������С
		}
		else
		{
			printf("you are right :%d\n", num);//����²���ȷ��������ȷ����
			break;
		}
	} while (1);
}

void Interface()//�ж�������˺ź������Ƿ���ȷ
{
	char name[100];
	char password[100];
	int count = 3;
	while (count > 0)
	{
		count--;
		printf("please enter you name:\n");
		scanf("%s", &name);
		printf("plesse enter password:\n");
		scanf("%s", &password);
		if (strcmp(USER, name) == 0 && strcmp(PSD, password) == 0)//���ú����ж��˺ź������Ƿ�������ȷ
		{
			break;
		}
		else
		{
			printf("you name or password error,please enter agin,you have %d times\n", count);//��ʾ���������󣬲���֪��һ��м����������
		}
	}
	if (count > 0)
	{
		printf("login success��");
	}
	int i = 5;
	while (i > 0)
	{
		printf("\r");
		printf("loading......%d\r", i);//��ʾ������ڼ����У���ȴ�
		Sleep(1000);
		i--;
	}
	printf("loading done!");
	printf("\n");
}
void GameInterfence()//���ѡ�����
{
	printf("***************************");
	printf("***1.start        2.exit***");
	printf("***************************");
	printf("\n");
}
int main()//��ʼ������Ϸ
{
	Interface();
	int quit = 0;
	while (!quit)//ȷ����Ϸ���ܼ������£��ܼ�������ȥ
	{
		GameInterfence();
		int n = 0;
		scanf("%d", &n);
		switch (n){
		case 1://������Ϸ
			game();
			break;
		case 2:
			printf("bye bye\n");//�˳���Ϸ
			quit = 1;
			break;
		default:
			printf("enter error");
			break;
		}
	}
	system("pause");
	return 0;
}
