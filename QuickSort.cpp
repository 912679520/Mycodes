
//#include"../顺序栈/stack.cpp"
#include"../顺序栈/stack.h"
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

//非递归实现
/*
	空间复杂度：由栈的使用空间决定——O（log（n））
	如果在一个工程引用其他工程的代码
	1、在使用另一个工程的代码的源文件中直接使用include".cpp"文件   （一般不使用）
	2、设置工程属性，在工程中加入引用其他工程，同时将要引入的工程的配置类型改为动态库和静态库
*/
void Quick2(int* arr, int start, int end)
{
	stack st;
	InitStack(&st);
	ElemType val = {start, end};
	Push(&st, val); //将整个数据段的起始位置和结束位置Push到栈中

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
			Push(&st, val);  //mid这个基准数据左边有超过一个的数据
		}
		if (data.end - mid > 1)
		{
			val.start = mid + 1;
			val.end = data.end;
			Push(&st, val);   //mid这个基准数据右边有超过一个数据
		}
	}

	Destroy(&st);
}


void QuickSort(int* arr, int len)
{
	Quick(arr, 0, len - 1);
}