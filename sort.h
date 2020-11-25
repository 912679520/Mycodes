#pragma once


#define LEN 14

//交换两个数据
void Swap(int* a, int* b);

//判断数据是否有序
bool IsSort(int* arr, int len);

void ShowArr(int* arr, int len);

//冒泡排序
//冒泡排序
//时间复杂度：O(n^2)
//空间复杂度：O(1)
void BubbleSort(int* arr, int len);

//选择排序
/*
选择排序

	先遍历一遍整个待排序数据，找到当前最大的值的位置
	将标记的最大值与当前最后一个元素交换
	重复上述的过程，直到只剩下一个数据
	上面的步骤每遍历一次，下一次就少遍历一次数据（本次找到的最大值）


时间复杂度：O(n^2)
空间复杂度：O(1)
不稳定
*/
void SelectSort(int* arr, int len);

//直接插入排序
/*
	将数据分成两部分，前一段是已经有序的数据（初始时，
	前一段数据只有一个），后一段是无序的数据。从无序数据
	中拿一个数据(左边第一个数据)，插入到前一段的有序数据中，并使得有序
	数据段依旧有序。
	重复上述过程，直到无序数据段没有数据


直接插入排序分析进阶
思考：若数据完全有序，则时间复杂度为O(n)
结论：数据越有序，直接插入排序越快，时间复杂度趋近于O(n)
*/
void InsertSort(int* arr, int len);

//希尔排序（增量排序）：
/*
	时间复杂度：O(n^1.3--1.5)
	空间复杂度：O(1)
	稳定性：稳定
	目的：使得整个数据越来越有序
	思想：
	1、先将数据分为d个组，在每组数据中使用直接插入排序算法来进行排序。
	Shell
	2、接着继续将数据分组（分组数会越来越小），最后一次分组肯定为1
	每一个分组数一般是互质的。ShellSort
*/
void Shell(int* arr, int len, int group);

void ShellSort(int* arr, int len);

//堆排序
void OneAdjust(int* arr, int len, int root);

void CreateHeap(int *arr, int len);

void HeapSort(int* arr, int len);

//快排
int OneQuick(int* arr, int start, int end);

void Quick(int* arr, int start, int end);

void QuickSort(int* arr, int len);

//二路归并排序
void Meger(int* arr, int len, int i);

void MegerSort(int* arr, int len);


//基数排序
void RadixSort(int* arr, int len);