#include "game.h"

void InitialTable(char table[][COL], int row, int col)//初始化棋盘
{
	int i = 0;
	for (; i < row; i++)
	{
		int j = 0;
		for (; j < col; j++)
		{
			table[i][j] = INT;
		}
	}
}
void ShowTable(char table[][COL], int row, int col)//显示棋盘的构局
{
	printf("    | 1  | 2  | 3  | \n");
	printf("---------------------\n");
		int i =1 ;
	for (i; i <=row; i++)
	{
		printf("%d   |",i);
		int j = 0;
		for (j; j < col; j++){
			printf(" %c  |", table[i-1][j]);
		}
		printf("\n");
		printf("----------------------\n");
	}
}
char Judge(char table[][COL], int row, int col)//判定是否已经产生游戏结果
{
	int i = 0;
	for (; i < row; i++)
	{
		if (table[i][0] != INT&&table[i][0] == table[i][1] && table[i][1] == table[i][2])
		{
			return table[i][0];//如果有连续横着的三个，则返回字符
		}
	}
	for (i=0; i < col; i++)
	{
		if (table[0][i] != INT&&table[0][i] == table[1][i] && table[1][i] == table[2][i])
		{
			return table[0][i];//如果有连续竖着的三个，则返回字符
		}
	}
	if (table[1][1] != INT&&table[0][0] == table[1][1] && table[1][1] == table[2][2])
	{
		return table[1][1];//判断斜着的3个是否连续
	}
	if (table[1][1] != INT&&table[0][2] == table[1][1] && table[1][1] == table[2][0])
	{
		return table[1][1];//判断斜着的三个是否连续
	}
	for (i=0; i < row; i++)
	{
		int j = 0;
		for (; j < col; j++)
		{
			if (table[i][j] == INT)
			{
				return 'N';//如果棋盘还有空位则返回N
			}
		}
	}
	return 'F';//都不满足说明已满，返回F
}
void Computer(char table[][COL], int row, int col)//确定电脑要落子的位置
{
	while (1)
	{
		Sleep(1000);
		int x = rand()%row;
		int y = rand()%col;//随机生成一个数
		if (table[x][y] == INT)
		{
			table[x][y] = C_ICON;
			break;
		}
	}
}
int Guess()//用随机的方法来确定是玩家先下还是电脑先下
{
	int num = 0;
	printf("请猜数字!\n");
	printf("0代表硬币的正面，1代表硬币的反面!\n");
	printf("请猜测硬币的正反面:\n");
	scanf("%d", &num);
	int guess = rand() % 2;//随机生成0或1
	if (guess == num)
		{
			printf("你猜对了，你先走!\n");
			Sleep(1000);
			return 0;
		}
		else
		{
			printf("你猜错了，电脑先走!\n");
			Sleep(1000);
			return 1;
		}
}
void Game()
{
	srand((unsigned long)time(NULL));
	char result=0;
	char table[ROW][COL];
	InitialTable(table,ROW,COL);
	ShowTable(table, ROW, COL);
	int x = 0;
	int y = 0;
	int who = Guess();
	do
	{
		system("cls");//刷新界面
		ShowTable(table, ROW, COL);
		switch (who){
		case 0:
			printf("请输入你想下的位置:\n");
			scanf("%d %d", &x, &y);
			if (x <= 0 || x > 3 || y <= 0 || y > 3)
			{
				printf("你的输入有误，请重新输入\n");//将落子的范围确定
				continue;
			}
			if (table[x - 1][y - 1] != INT)
			{
				printf("此位置已经有棋子了，请重新输入:\n");//将落子的范围确定
				continue;
			}
			table[x - 1][y - 1] = P_ICON;
			printf("你已经走完，电脑正在思考中........\n");
			Sleep(1000);
			who = 1;
			break;
		case 1:
			Computer(table, ROW, COL);
			who = 0;
			break;
		default:
			break;
		}
		result = Judge(table, ROW, COL);//通过返回的字符来确定下一步的操作
		ShowTable(table, ROW, COL);
		if (result != 'N')
		{
			break;
		}
	} while (1);
	if (result == P_ICON)//如果返回玩家字符，则玩家赢
	{
		printf("你赢了!\n");
	}
	else if (result == C_ICON)//如果返回电脑字符，则电脑赢
	{
		printf("你输了!\n");
	}
	else
	{
		printf("平局!\n");//如果棋盘已满说明没有赢家，为平局
	}
	printf("\n");
}