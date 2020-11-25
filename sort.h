#pragma once


#define LEN 14

//������������
void Swap(int* a, int* b);

//�ж������Ƿ�����
bool IsSort(int* arr, int len);

void ShowArr(int* arr, int len);

//ð������
//ð������
//ʱ�临�Ӷȣ�O(n^2)
//�ռ临�Ӷȣ�O(1)
void BubbleSort(int* arr, int len);

//ѡ������
/*
ѡ������

	�ȱ���һ���������������ݣ��ҵ���ǰ����ֵ��λ��
	����ǵ����ֵ�뵱ǰ���һ��Ԫ�ؽ���
	�ظ������Ĺ��̣�ֱ��ֻʣ��һ������
	����Ĳ���ÿ����һ�Σ���һ�ξ��ٱ���һ�����ݣ������ҵ������ֵ��


ʱ�临�Ӷȣ�O(n^2)
�ռ临�Ӷȣ�O(1)
���ȶ�
*/
void SelectSort(int* arr, int len);

//ֱ�Ӳ�������
/*
	�����ݷֳ������֣�ǰһ�����Ѿ���������ݣ���ʼʱ��
	ǰһ������ֻ��һ��������һ������������ݡ�����������
	����һ������(��ߵ�һ������)�����뵽ǰһ�ε����������У���ʹ������
	���ݶ���������
	�ظ��������̣�ֱ���������ݶ�û������


ֱ�Ӳ��������������
˼������������ȫ������ʱ�临�Ӷ�ΪO(n)
���ۣ�����Խ����ֱ�Ӳ�������Խ�죬ʱ�临�Ӷ�������O(n)
*/
void InsertSort(int* arr, int len);

//ϣ�������������򣩣�
/*
	ʱ�临�Ӷȣ�O(n^1.3--1.5)
	�ռ临�Ӷȣ�O(1)
	�ȶ��ԣ��ȶ�
	Ŀ�ģ�ʹ����������Խ��Խ����
	˼�룺
	1���Ƚ����ݷ�Ϊd���飬��ÿ��������ʹ��ֱ�Ӳ��������㷨����������
	Shell
	2�����ż��������ݷ��飨��������Խ��ԽС�������һ�η���϶�Ϊ1
	ÿһ��������һ���ǻ��ʵġ�ShellSort
*/
void Shell(int* arr, int len, int group);

void ShellSort(int* arr, int len);

//������
void OneAdjust(int* arr, int len, int root);

void CreateHeap(int *arr, int len);

void HeapSort(int* arr, int len);

//����
int OneQuick(int* arr, int start, int end);

void Quick(int* arr, int start, int end);

void QuickSort(int* arr, int len);

//��·�鲢����
void Meger(int* arr, int len, int i);

void MegerSort(int* arr, int len);


//��������
void RadixSort(int* arr, int len);