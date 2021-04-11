#include<vector>
#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;

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

