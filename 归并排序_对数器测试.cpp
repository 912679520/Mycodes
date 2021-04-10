#include<vector>
#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;

class memgeSort
{
public:
	static void memge(vector<int> &arr, int left, int mid, int right)
	{
		vector<int> help(right - left + 1);
		int i = 0;
		int p1 = left, p2 = mid + 1;
		while (p1 <= mid && p2 <= right)
		{
			help[i++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
		}
		while (p1 <= mid)
		{
			help[i++] = arr[p1++];
		}
		while (p2 <= right)
		{
			help[i++] = arr[p2++];
		}
		for (int i = 0; i < help.size(); i++)
		{
			arr[left + i] = help[i];
		}
	}
	static void mergeSort(vector<int> &arr, int left, int right)
	{
		if (left == right) return;
		int mid = left + ((right - left) >> 1);
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		memge(arr, left, mid, right);
	}
	static void mergeSort(vector<int>& arr)
	{
		if (&arr == nullptr || arr.size() < 2)
		{
			return;
		}
		mergeSort(arr, 0, arr.size() - 1);
	}
	//void Show(vector<int> &arr)
	//{
	//	if (&arr == nullptr) return;

	//	for (int i = 0; i < arr.size(); i++)
	//	{
	//		cout << arr[i] << " ";
	//	}
	//	cout << endl;
	//}

//¶ÔÊýÆ÷
/////////////////////////////////////////////////////////////////////////// 
	void comparator(vector<int>& arr)
	{
		sort(arr.begin(), arr.end());
	}

	vector<int> generateRandomArray(int maxsize, int maxValue)
	{
		vector<int> arr;
		for (int i = 0; i < maxsize;i++)
		{
			arr.push_back(rand() % maxValue);
		}
		return arr;
	}

	vector<int> copyArray(vector<int>& arr)
	{
		return arr;
	}

	bool isEqual(vector<int>& arr1, vector<int>& arr2)
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

	void printArry(vector<int>& arr)
	{
		if (&arr == nullptr) return;
		for (int i = 0; i < arr.size();i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

int main()
{
	memgeSort a;

	int testTime = 50;
	int maxSize = 10;
	int maxValue = 100;
	bool succeed = true;

	for (int i = 0;i < testTime;i++)
	{
		vector<int> arr1 = a.generateRandomArray(maxSize, maxValue);
		vector<int> arr2 = a.copyArray(arr1);
		a.mergeSort(arr1);
		a.comparator(arr2);
		if (!a.isEqual(arr1, arr2))
		{
			succeed = false;
			a.printArry(arr1);
			a.printArry(arr2);
			break;
		}
	}
	if (succeed) cout << "Nice" << endl;
	else
		cout << "Error" << endl;

	vector<int> arr = a.generateRandomArray(maxSize, maxValue);
	a.printArry(arr);
	a.mergeSort(arr);
	a.printArry(arr);

}
