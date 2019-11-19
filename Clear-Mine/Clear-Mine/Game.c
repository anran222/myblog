#include"game.h"

void SetMine(char mine[][COL],int row,int col,int *x,int *y)
{
	int time=NUMBER;
	while (time)
	{
		int x = rand() % (ROW - 2) + 1;
		int y = rand() % (COL - 2) + 1;
		if (mine[x][y] != '1')
		{
			mine[x][y] = '1';
			time--;
		}
	}
	int i;
	int j;
	for (i = 1; i < ROW - 1; i++)
	{
		for (j = 1; j < COL - 1; j++)
		{
			if (mine[i][j] == '0')
			{
				*x = i;
				*y = j;
			}
			break;
		}
	}
}
void ShowTable(char show[][COL],int row,int col)
{
	int i;
	printf("   ");
	for (i = 1; i < 11; i++)
	{
		printf("  %d  |", i);
	}
	printf("\n");
	int j,k;
	for (j = 1; j < 11; j++)
	{
		printf("  ------------------------------------------------------");
		printf("------\n");
		printf("%2d|", j);
		for (k = 1; k < 11; k++)
		{
			printf("  %c  |", show[j][k]);
		}
		printf("\n");
	}
	printf("  ------------------------------------------------------");
	printf("------\n");
}
int CountMine(char mine[][COL], int x, int y)
{
	return mine[x - 1][y - 1] + mine[x][y - 1] + mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1]\
		+ mine[x][y + 1] + mine[x - 1][y + 1] + mine[x - 1][y] - 8 * '0';
}
void Open(char show[][COL], char mine[][COL], int x, int y)
{
	int i, j;
	if (!CountMine(mine, x, y))
	{
		show[x][y] = ' ';
		for (i = x - 1; i <= x + 1; i++)
		{
			for (j = y - 1; j <= y + 1; j++)
			{
				if (show[i][j] == '*'&&i>0 && i<11 && j>0 && j < 11)
				{
					Open(show, mine, i, j);
				}
			}
		}
	}
	else
	{
		show[x][y] = CountMine(mine, x, y) + '0';
	}
}
void Game()
{
	int times =100-NUMBER;
	srand((unsigned long)time(NULL));
	int x;
	int y;
	int flag = 0;
	char mine[ROW][COL];
	char show[ROW][COL];
	memset(mine, '0', sizeof(mine));
	memset(show, '*', sizeof(show));
	SetMine(mine,ROW,COL, &x, &y);
	ShowTable(show, ROW, COL);
	while (!flag)
	{
		system("cls");
		ShowTable(show, ROW, COL);
		printf("请输入你的坐标:\n");
		int x0, y0;
		scanf("%d %d", &x0, &y0);
		if (x0<1 || x0>10 || y0 < 1 || y0>10)
		{
			printf("你的输入有误，请重新输入;\n");
			continue;
		}
		if (show[x0][y0] != '*')
		{
			printf("该位置已经排除过了，请重新输入!\n");
			continue;
		}
		if (mine[x0][y0] == '1')
		{
			if (times == 70)
			{
				mine[x0][y0] = '0';
				mine[x][y] = '1';
			}
			else
			{
				printf("你踩到雷了，游戏结束!\n");
				ShowTable(mine, x0, y0);
				printf("请稍后!\n");
				int j = 5;
				for (; j > 0; j--)
				{
					printf("%d\r", j);
					Sleep(1000);
				}
				system("cls");
				break;
			}
		}
		Open(show, mine, x0, y0);
		times--;
		int count = CountMine(mine, x0, y0);
		show[x0][y0]=count+'0';
		ShowTable(show, x0, y0);
	}
}