

#include"sort.h"

int OneQuick(int* arr, int start, int end)
{
	int tmp = arr[start];
	int i = start, j = end;

	while (i < j)
	{
		while (i < j && arr[j] >= tmp) j--;
		arr[i] = arr[j];

		while (i < j && arr[i] <= tmp) i++;
		arr[j] = arr[i];
	}

	arr[i] = tmp;

	return i;
}

void Quick(int* arr, int start, int end)
{
	if (end - start < 1) return;

	int mid = OneQuick(arr, start, end);
	Quick(arr, start, mid - 1);
	Quick(arr, mid + 1, end);
}

void QuickSort(int* arr, int len)
{
	Quick(arr, 0, len - 1);
}