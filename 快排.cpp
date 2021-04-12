#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

/*
1、一次快排 partition
2、递归   QuickSort
*/

static void swap(vector<int>& arr, int left, int right)
{
	int tmp = arr[left];
	arr[left] = arr[right];
	arr[right] = tmp;
}

static vector<int> partition(vector<int>& arr,int left,int right)
{
	int less = left - 1;
	int more = right;

	while (left < more)
	{
		if (arr[left] < arr[right])
		{
			swap(arr, ++less, left++);
		}
		else if (arr[left] > arr[right])
		{
			swap(arr, left, --more);
		}
		else
		{
			left++;
		}
	}
	swap(arr, more, right);
	vector<int> p = { less + 1, more };
	return p;
}

//非递归
static void QuickSort1(vector<int>& arr, int left, int right)
{
	stack<int> s;
	//swap(arr, left + (int)(rand() % (right - left + 1)), right);
	vector<int> p = partition(arr, left, right);

	if (p[0] - 1 > left) // 左分区存在
	{
		s.push(left);
		s.push(p[0] - 1);
	}
	if (p[1] + 1 < right) //右分区存在
	{
		s.push(p[1] + 1);
		s.push(right);
	}

	while (!s.empty())
	{
		int right = s.top();
		s.pop();
		int left = s.top();
		s.pop();

		p = partition(arr, left, right);
		if (p[0] - 1 > left)
		{
			s.push(left);
			s.push(p[0] - 1);
		}
		if (p[1] + 1 > right)
		{
			s.push(p[1] + 1);
			s.push(right);
		}
	}
}

static void QuickSort(vector<int>& arr, int left, int right)
{
	if (left < right)
	{
		swap(arr, left + (int)(rand() % (right - left +1)) , right);
		vector<int> p = partition(arr, left, right);
		QuickSort(arr, left, p[0] - 1);
		QuickSort(arr, p[1] + 1, right);
	}
}

static void Sort(vector<int>& arr)
{
	if (&arr == NULL || arr.size() < 2) return;
	QuickSort1(arr, 0, arr.size() - 1);
}

//////////////////////////////////
//对数器测试
static void comparator(vector<int>& arr)
{
	sort(arr.begin(), arr.end());
}

static vector<int> RandArray(int maxsize, int maxvalue)
{
	vector<int> arr;
	for (int i = 0; i < maxsize; i++)
	{
		arr.push_back(rand() % maxvalue);
	}
	return arr;
}

static vector<int> copyArray(vector<int>& arr)
{
	return arr;
}

static bool isEqual(vector<int>& arr1, vector<int>& arr2)
{
	if (arr1.empty() == arr2.empty()) return true;
	if ((arr1.empty() && !arr2.empty()) ||
		(!arr1.empty() && arr2.empty()))
	{
		return true;
	}
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
/*
int main()
{
	vector<int> arr = RandArray(10, 10);
	Show(arr);
	Sort(arr);
	Show(arr);

	int testtime = 1;
	int maxSize = 10;
	int maxValue = 10;
	bool succeed = true;
	for (int i = 0; i < testtime; i++)
	{
		vector<int> arr1 = RandArray(maxSize, maxValue);
		vector<int> arr2 = copyArray(arr1);
		Sort(arr1);
		comparator(arr2);

		if (!isEqual(arr1, arr2))
		{
			succeed = false;
			Show(arr1);
			Show(arr2);
			break;
		}	
	}
	if (succeed)
	{
		cout << "Nice" << endl;
	}
	else
	{
		cout << "error" << endl;
	}
	
	vector<int> arr = RandArray(maxSize, maxValue);
	Show(arr);
	Sort(arr);
	Show(arr);


	return 0;
}*/