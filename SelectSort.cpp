#include"sort.h"

/*
	时间复杂度：O(n^2)
	空间复杂度：O(1)
	稳定性：不稳定
*/
void SelectSort(int* arr, int len)
{
	
	for (int j = 0; j < len - 1; ++j)
	{	
		int maxindex = 0;//记录最大值的下标
		for (int i = 0;i < len - j;++i)
		{
			if (arr[i] > arr[maxindex])
			{
				maxindex = i;
			}
		}

		Swap(&arr[maxindex], &arr[len - 1 - j]);
	}	
}
