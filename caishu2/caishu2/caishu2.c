#include<stdio.h>
#include<windows.h>
#include<time.h>
#pragma warning(disable:4996)
#define USER "anran"//确定一个最初的账号
#define PSD "565656"//确定一个最初的密码
void game()
{
	srand(time(NULL));//调用函数产生随机数与我们将要输入的数做判断
	int n = rand() % 100 + 1;
	int num = 0;
	do{
		printf("please enter guess num;");//输入我们猜测的数字
		scanf("%d", &num);
		if (n < num)
		{
			printf("guess big\n");//如果输入的数过大，则提示玩家输入的数过大
		}
		else if (n>num)
		{
			printf("guess small\n");//如果输入的数过小，则提示玩家输入的数过小
		}
		else
		{
			printf("you are right :%d\n", num);//如果猜测正确，返回正确的数
			break;
		}
	} while (1);
}

void Interface()//判断输入的账号和密码是否正确
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
		if (strcmp(USER, name) == 0 && strcmp(PSD, password) == 0)//调用函数判断账号和密码是否都输入正确
		{
			break;
		}
		else
		{
			printf("you name or password error,please enter agin,you have %d times\n", count);//提示玩家输入错误，并告知玩家还有几次输入机会
		}
	}
	if (count > 0)
	{
		printf("login success！");
	}
	int i = 5;
	while (i > 0)
	{
		printf("\r");
		printf("loading......%d\r", i);//提示玩家正在加载中，请等待
		Sleep(1000);
		i--;
	}
	printf("loading done!");
	printf("\n");
}
void GameInterfence()//玩家选择界面
{
	printf("***************************");
	printf("***1.start        2.exit***");
	printf("***************************");
	printf("\n");
}
int main()//开始进行游戏
{
	Interface();
	int quit = 0;
	while (!quit)//确保游戏还能继续更新，能继续玩下去
	{
		GameInterfence();
		int n = 0;
		scanf("%d", &n);
		switch (n){
		case 1://继续游戏
			game();
			break;
		case 2:
			printf("bye bye\n");//退出游戏
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
