#include<stdio.h>
#include<string.h>
#include<windows.h>
#pragma warning(disable:4996)
int main()
{
	int i=0;
	int m;
	int num;
	char a[100];//定义一个数组，用来存放我们将要输入的字符串
	printf("请输入一个字符串:\n");
	scanf("%s",a);//将字符串存入我们已经定义好的数组中
	printf("请输入你要左旋的次数:");//输入我们要左旋的次数
	scanf("%d", &m);
	num = strlen(a);//求字符串的长度
	while (m)///确定我们要左旋的次数
	{
		char temp = a[0];//用一个中间值
		for (i= 0; i < num-1; i++)
		{
			a[i] = a[i + 1];//将每一位往前移一位
		}
		a[i] = temp;//将第一个值给最后一位
		m--;
	}
	printf("%s", a);
	system("pause");
	return 0;
}