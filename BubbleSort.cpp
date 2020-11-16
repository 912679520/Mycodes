
#include"sort.h"

/*
	时间复杂度：O(n^2)
	空间复杂度：O(1)
	稳定性：稳定
*/
void BubbleSort(int* arr, int len)
{
	for (int i = 0; i < len - 1;++i)
	{
		bool flag = true;//优化

		for (int j = 0; j < len - 1 - i;++j)//len - 1 - j每经过一趟，下一次可以少比较一次数据
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(&arr[j], &arr[j + 1]);
				flag = false;
			}
		}

		if (flag)
		{
			return;
		}
	}
}