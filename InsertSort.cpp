
#include"sort.h"

/*
	时间复杂度：O(n^2)
	空间复杂度：O(1)
	稳定性：稳定
*/
void InsertSort(int* arr, int len)
{
	for (int i = 1; i < len;++i)//i负责遍历无序数据段
	{
		int tmp = arr[i];
		int j = i - 1;
		for (; j >= 0; --j)
		{
			if (arr[j] <= tmp)
			{
				break;
			}

			arr[j + 1] = arr[j];
		}
		
		arr[j + 1] = tmp;
	}
}