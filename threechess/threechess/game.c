#include "game.h"

void InitialTable(char table[][COL], int row, int col)//��ʼ������
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
void ShowTable(char table[][COL], int row, int col)//��ʾ���̵Ĺ���
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
char Judge(char table[][COL], int row, int col)//�ж��Ƿ��Ѿ�������Ϸ���
{
	int i = 0;
	for (; i < row; i++)
	{
		if (table[i][0] != INT&&table[i][0] == table[i][1] && table[i][1] == table[i][2])
		{
			return table[i][0];//������������ŵ��������򷵻��ַ�
		}
	}
	for (i=0; i < col; i++)
	{
		if (table[0][i] != INT&&table[0][i] == table[1][i] && table[1][i] == table[2][i])
		{
			return table[0][i];//������������ŵ��������򷵻��ַ�
		}
	}
	if (table[1][1] != INT&&table[0][0] == table[1][1] && table[1][1] == table[2][2])
	{
		return table[1][1];//�ж�б�ŵ�3���Ƿ�����
	}
	if (table[1][1] != INT&&table[0][2] == table[1][1] && table[1][1] == table[2][0])
	{
		return table[1][1];//�ж�б�ŵ������Ƿ�����
	}
	for (i=0; i < row; i++)
	{
		int j = 0;
		for (; j < col; j++)
		{
			if (table[i][j] == INT)
			{
				return 'N';//������̻��п�λ�򷵻�N
			}
		}
	}
	return 'F';//��������˵������������F
}
void Computer(char table[][COL], int row, int col)//ȷ������Ҫ���ӵ�λ��
{
	while (1)
	{
		Sleep(1000);
		int x = rand()%row;
		int y = rand()%col;//�������һ����
		if (table[x][y] == INT)
		{
			table[x][y] = C_ICON;
			break;
		}
	}
}
int Guess()//������ķ�����ȷ����������»��ǵ�������
{
	int num = 0;
	printf("�������!\n");
	printf("0����Ӳ�ҵ����棬1����Ӳ�ҵķ���!\n");
	printf("��²�Ӳ�ҵ�������:\n");
	scanf("%d", &num);
	int guess = rand() % 2;//�������0��1
	if (guess == num)
		{
			printf("��¶��ˣ�������!\n");
			Sleep(1000);
			return 0;
		}
		else
		{
			printf("��´��ˣ���������!\n");
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
		system("cls");//ˢ�½���
		ShowTable(table, ROW, COL);
		switch (who){
		case 0:
			printf("�����������µ�λ��:\n");
			scanf("%d %d", &x, &y);
			if (x <= 0 || x > 3 || y <= 0 || y > 3)
			{
				printf("���������������������\n");//�����ӵķ�Χȷ��
				continue;
			}
			if (table[x - 1][y - 1] != INT)
			{
				printf("��λ���Ѿ��������ˣ�����������:\n");//�����ӵķ�Χȷ��
				continue;
			}
			table[x - 1][y - 1] = P_ICON;
			printf("���Ѿ����꣬��������˼����........\n");
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
		result = Judge(table, ROW, COL);//ͨ�����ص��ַ���ȷ����һ���Ĳ���
		ShowTable(table, ROW, COL);
		if (result != 'N')
		{
			break;
		}
	} while (1);
	if (result == P_ICON)//�����������ַ��������Ӯ
	{
		printf("��Ӯ��!\n");
	}
	else if (result == C_ICON)//������ص����ַ��������Ӯ
	{
		printf("������!\n");
	}
	else
	{
		printf("ƽ��!\n");//�����������˵��û��Ӯ�ң�Ϊƽ��
	}
	printf("\n");
}