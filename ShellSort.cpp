
#include"sort.h"

void Shell(int* arr, int len,int group)
{
	for (int i = group; i < len; ++i)//i控制本次直接插入排序在哪个组
	{
		int tmp = arr[i];
		int j = i - group;

		for (; j >= 0; j -= group)
		{
			if (arr[j] <= tmp)
			{
				break;
			}

			arr[j + group] = arr[j];
		}

		arr[j + group] = tmp;
	}
}

void ShellSort(int* arr, int len)
{
	int group[] = { 5,3,1 };

	for (int i = 0; i < sizeof(group) / sizeof(group[0]);++i)
	{
		Shell(arr, len, group[i]);
	}
}