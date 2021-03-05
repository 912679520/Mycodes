#include"sort.h"
#include"../链式队列/ListQueue.h"

/*
	时间复杂度：O(d*n) d是位数
	空间复杂度：O(n)
	稳定性：稳定  没有跳跃的交换数据
*/

//得到最大数据的位数
int GetDigit(int *arr, int len)
{
	int max = arr[0];
	for (int i = 0; i < len;++i)//找最大值
	{
		if (max < arr[i]) max = arr[i];
	}

	int digit = 0;
	while (max)
	{
		digit++;
		max /= 10;
	}

	return digit;
}

//获取数据相应位置上的值
int GetRadix(int val, int digit)
{
	int radix = val % 10;
	while (digit)
	{
		val /= 10;
		radix = val % 10;
		digit--;
	}

	return radix;
}

void RadixSort(int* arr, int len)
{
	int maxDigit = GetDigit(arr,len);

	ListQue que[10];
	for (int i = 0;i < 10;++i)
	{
		InitListQue(&que[i]);
	}

	//根据不同的位数处理整个数据 
	for (int i = 0;i < maxDigit;++i)
	{
		//将arr中的所有数据取其i这个位数的值，并且插入到相应值的队列中
		for (int j = 0;j < len;++j)
		{
			int radix = GetRadix(arr[j], i);
			Push(&que[radix], arr[j]);
		}

		//将所有队列按照从前到后的顺序把值全部出到arr中
		int index = 0;
		for (int k = 0;k < 10;++k)
		{
			while (Empty(&que[k]))
			{
				GetHead(&que[k],&arr[index]);
				Pop(&que[k]);
			}
		}
	}

	for (int i = 0;i < 10;++i)
	{
		DestroyListQue(&que[i]);
	}
}