#include"sort.h"

/*
	ʱ�临�Ӷȣ�O(n^2)
	�ռ临�Ӷȣ�O(1)
	�ȶ��ԣ����ȶ�
*/
void SelectSort(int* arr, int len)
{
	
	for (int j = 0; j < len - 1; ++j)
	{	
		int maxindex = 0;//��¼���ֵ���±�
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
