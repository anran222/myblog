#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
void Init(int arr[],int m)
{
	int i;
	printf("Rest array:\n");
	for (i = 0; i<m; i++){
		printf("please enter number:");
		scanf("%d", &arr[i]);
	}
	printf("After initialization, the array is:\n");
	for (i = 0; i < m; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");
}
void Empty(int arr[], int n)
{
	int i;
	int j;
	printf("Empty array:\n");
	for (i = 0; i < n; i++)
	{
		arr[i] = '\0';
	}
	for (j = 0; j < n; j++)
	{
		printf("%d  ", arr[j]);
	}
	printf("\n");
}
void reverse(int arr[],int p)
{
	int i;
	for (i = 0; i <= (p / 2); i++)
	{
		int temp = arr[i];
		arr[i] =arr[p - i - 1];
		arr[p - i - 1] = temp;
	}
	for (i = 0; i <p; i++)
	{
		printf("%4d", arr[i]);
	}
}
int main()
{
	int arr[] = { 12, 52, 65, 954, 841, 522, 34, 52, 44 };
	int num = sizeof(arr) / sizeof(arr[0]);
    Init(arr, num);
	Empty(arr, num);
	reverse(arr, num);
	system("pause");
	return 0;
}