#include"game.h"
void Menu()
{
	printf("*************************\n");
	printf("****欢迎来到扫雷游戏*****\n");
	printf("*************************\n");
	printf("****1>开始    2>退出*****\n");
	printf("*************************\n");
}
int main()
{
	int quit = 0;
	while (!quit)
	{
		Menu();
		int select;
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			Game();
			break;
		case 2:
			quit = 1;
			printf("ByeBye!\n");
			break;
		default:
			printf("你的输入有误，请重新输入");
			break;
		}
	}
	system("pause");
	return 0;
}