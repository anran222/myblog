#include"game.h"
void Menu()
{
	printf("*************************\n");
	printf("****��ӭ����ɨ����Ϸ*****\n");
	printf("*************************\n");
	printf("****1>��ʼ    2>�˳�*****\n");
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
			printf("���������������������");
			break;
		}
	}
	system("pause");
	return 0;
}