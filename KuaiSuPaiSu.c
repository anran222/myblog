#include <stdio.h>
#include <stdlib.h>
#include<windows.h>

#define N 7
void dayin(int array[], int max)    //maxΪ����Ԫ�����ֵ
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
		//int v = array[low];     //����Ԫ��v
		i = low + 1;            // array[low]��Ϊ��׼��(һ���һ��)����array[begin+1]��ʼ���׼���Ƚ�
		j = high;               // array[high]����������һλ
		while (i < j)
		{
			if (array[i] > array[low])  // ����Ƚϵ�����Ԫ�ش��ڻ�׼�����򽻻�λ�á�
			{
				swap(&array[i], &array[j]);  // ����������
				j--;
			}
			else
			{
				i++;                    // �����������һλ���������׼���Ƚϡ�
			}
		}

		if (array[i] >= array[low])  // ȡ��>=
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
	printf("����ǰ������\n");
	dayin(array, max);
	quicksort(array, max, 0, max - 1);  // ��������
	printf("����������\n");
	dayin(array, max);
	system("pause");
	return 0;
}