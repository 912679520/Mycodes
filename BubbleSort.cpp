
#include"sort.h"

/*
	ʱ�临�Ӷȣ�O(n^2)
	�ռ临�Ӷȣ�O(1)
	�ȶ��ԣ��ȶ�
*/
void BubbleSort(int* arr, int len)
{
	for (int i = 0; i < len - 1;++i)
	{
		bool flag = true;//�Ż�

		for (int j = 0; j < len - 1 - i;++j)//len - 1 - jÿ����һ�ˣ���һ�ο����ٱȽ�һ������
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