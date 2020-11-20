
#include"sort.h"

void OneAdjust(int* arr, int len, int root)
{
	int i = root;
	int j = 2 * i + 1;
	int tmp = arr[root];

	while (j < len)
	{
		if (j + 1 < len && arr[j] < arr[j + 1]) j++;//找到最大的子孩子

		if (arr[j] < tmp) break;

		arr[i] = arr[j];
		i = j;
		j = 2 * i + 1;
	}

	arr[i] = tmp;
}

void CreateHeap(int* arr, int len)
{
	int lastroot = (len - 2) / 2;

	for (int i = lastroot; i >= 0; i--)
	{
		OneAdjust(arr,len,i);
	}
}

void HeapSort(int* arr, int len)
{
	CreateHeap(arr, len);

	for (int i = 0; i < len - 1; i++)
	{
		Swap(&arr[0], &arr[len - 1 - i]);
		OneAdjust(arr, len - 1 - i, 0);
	}
}