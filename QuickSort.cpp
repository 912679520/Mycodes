
//#include"../˳��ջ/stack.cpp"
#include"../˳��ջ/stack.h"
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

//�ǵݹ�ʵ��
/*
	�ռ临�Ӷȣ���ջ��ʹ�ÿռ��������O��log��n����
	�����һ�����������������̵Ĵ���
	1����ʹ����һ�����̵Ĵ����Դ�ļ���ֱ��ʹ��include".cpp"�ļ�   ��һ�㲻ʹ�ã�
	2�����ù������ԣ��ڹ����м��������������̣�ͬʱ��Ҫ����Ĺ��̵��������͸�Ϊ��̬��;�̬��
*/
void Quick2(int* arr, int start, int end)
{
	stack st;
	InitStack(&st);
	ElemType val = {start, end};
	Push(&st, val); //���������ݶε���ʼλ�úͽ���λ��Push��ջ��

	while (!Empty(&st))
	{
		ElemType data;
		Top(&st, &data);
		Pop(&st);

		int mid = OneQuick(arr, data.start, data.end);
		if(mid - data.start > 1)
		{
			val.start = data.start;
			val.end = mid - 1;
			Push(&st, val);  //mid�����׼��������г���һ��������
		}
		if (data.end - mid > 1)
		{
			val.start = mid + 1;
			val.end = data.end;
			Push(&st, val);   //mid�����׼�����ұ��г���һ������
		}
	}

	Destroy(&st);
}


void QuickSort(int* arr, int len)
{
	Quick(arr, 0, len - 1);
}