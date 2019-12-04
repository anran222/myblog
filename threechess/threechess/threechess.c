#include"game.h"

void menu()
{
	printf("****************************\n");
	printf("*****欢迎来到三子棋游戏*****\n");
	printf("****************************\n");
	printf("****************************\n");
	printf("*****1.开始      2.退出*****\n");
	printf("****************************\n");
}
int main()
{
	int select = 0;
	int flag = 0;
	while (!flag)//让玩家来选择是否继续游戏
	{
		menu();//显示出最开始玩家选择界面
		printf("请选择你要进行的操作:\n");
		scanf("%d", &select);
		switch (select)
		{
		case 1://如果玩家选择开始游戏，那么游戏开始
			Game();
			break;
		case 2://如果玩家选择退出，则结束游戏
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