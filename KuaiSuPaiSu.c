#include <stdio.h>
#include <stdlib.h>
#include<windows.h>

#define N 7
void dayin(int array[], int max)    //max为数组元素最大值
{

	for (int i = 0; i < max; i++)
	{
		printf("%-3d", array[i]);
	}
	printf("\n");
}
void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void quicksort(int array[], int max, int low, int high)
{
	int i, j;

	if (low < high)
	{
		//int v = array[low];     //中轴元素v
		i = low + 1;            // array[low]作为基准数(一般第一个)，从array[begin+1]开始与基准数比较
		j = high;               // array[high]是数组的最后一位
		while (i < j)
		{
			if (array[i] > array[low])  // 如果比较的数组元素大于基准数，则交换位置。
			{
				swap(&array[i], &array[j]);  // 交换两个数
				j--;
			}
			else
			{
				i++;                    // 将数组向后移一位，继续与基准数比较。
			}
		}

		if (array[i] >= array[low])  // 取等>=
		{
			i--;
		}

		swap(&array[low], &array[i]);

		quicksort(array, max, low, i);
		quicksort(array, max, j, high);
	}
}

int main()
{
	int array[N] = { 5, 2, 4, 3, 8, 7, 9, };
	int max = N;
	printf("排序前的数组\n");
	dayin(array, max);
	quicksort(array, max, 0, max - 1);  // 快速排序
	printf("排序后的数组\n");
	dayin(array, max);
	system("pause");
	return 0;
}