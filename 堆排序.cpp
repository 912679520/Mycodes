#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
1、建立大根堆
2、一个数据变化后的调整
*/

static void swap(vector<int>& arr, int i, int j)
{
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

//建立大根堆
static void heapInsert(vector<int>& arr, int index)
{
	while (arr[index] > arr[(index - 1) / 2])
	{
		swap(arr, index, (index - 1) / 2);
		index = (index - 1) / 2;
	}
}

static void heapify(vector<int>& arr, int index, int size)
{
	int left = index * 2 + 1;
	while (left < size)
	{
		int max = left + 1 < size && arr[left + 1] > arr[left] ? left + 1 : left;
		max = arr[max] > arr[index] ? max : index;
		if (max == index) break;

		swap(arr, index, max);
		index = max;
		left = index * 2 + 1;
	}
}

static vector<int> heapsort(vector<int>& arr)
{
	if (&arr == nullptr || arr.size() < 2)
	{
		exit(0);
	}
	for (int i = 0; i < arr.size();i++)
	{
		heapInsert(arr, i);
	}
	int size = arr.size();
	swap(arr, 0, --size);
	while (size > 0)
	{
		heapify(arr, 0, size);
		swap(arr, 0, --size);
	}
	return arr;
}

static void comparator(vector<int>& arr)
{
	sort(arr.begin(), arr.end());
}

static vector<int> RandArray(int maxsize,int maxvalue)
{
	vector<int> arr;
	for (int i = 0; i < maxsize;i++)
	{
		arr.push_back( rand() % maxvalue);
	}
	return arr;
}

static vector<int> copyArray(vector<int>& arr)
{
	return arr;
}

static bool isEqual(vector<int>& arr1, vector<int>& arr2)
{
	if (arr1.empty() && !arr2.empty()) return false;
	if (!arr1.empty() && arr2.empty()) return false;
	if (arr1.empty() && arr2.empty()) return true;
	if (arr1.size() != arr2.size()) return false;
	for (int i = 0; i < arr1.size();i++)
	{
		if (arr1[i] != arr2[i]) return false;
	}
	return true;
}

static void Show(vector<int>& arr)
{
	for (int i = 0; i < arr.size();i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

#if 0
int main()
{
	int time = 1;
	int maxsize = 500;
	int maxvalue = 10;
	bool succeed = true;
	
	for (int i = 0; i < time;i++)
	{
		vector<int> arr1 = RandArray(maxsize, maxvalue);
		vector<int> arr2 = copyArray(arr1);
		heapsort(arr1);
		comparator(arr2);
		if (!isEqual(arr1, arr2))
		{
			succeed = false;
			//Show(arr1);
			//Show(arr2);
			break;
		}
	}
	if (succeed)
	{
		cout << "Nice" << endl;
	}
	else
	{
		cout << "fuck" << endl;
	}
	vector<int> arr = RandArray(maxsize, maxvalue);
	Show(arr);
	heapsort(arr);
	Show(arr);
	return 0;
}
#endif
