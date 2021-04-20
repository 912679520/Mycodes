#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//将一个数放入桶中
static int bucket(long num, long len, long min, long max)
{
	return (int)((num - min) * len / (max - min));
}

static int maxGap(vector<int>& nums)
{
	if (&nums == nullptr || nums.size() < 2)
	{
		return 0;
	}
	int len = nums.size();
	int min_data = 0; // 最大值
	int max_data = 0;
	for (int i = 0; i < len; i++)
	{
		min_data = min(min_data, nums[i]);
		max_data = max(max_data, nums[i]);
	}

	if (min_data == max_data) return 0;

	vector<bool> hasNum(len + 1); //对应桶是否有数
	vector<int> maxs(len + 1);  //对应桶最大值
	vector<int> mins(len + 1);
	int bid = 0;
	for (int i = 0; i < len; i++) // 求每个桶的最大最小值
	{
		bid = bucket(nums[i], len, min_data, max_data);
		mins[bid] = hasNum[bid] ? min(mins[bid], nums[i]) : nums[i];
		maxs[bid] = hasNum[bid] ? max(mins[bid], nums[i]) : nums[i];
		hasNum[bid] = true;
	}
	int res = 0; // 求最大差值
	int lastMax = maxs[0];
	int i = 1;
	for (; i <= len; i++)
	{
		if (hasNum[i])
		{
			res = max(res, mins[i] - lastMax);
			lastMax = maxs[i];
		}
	}
	return res;
}


/// ///////////////

static int comparator(vector<int>& arr)
{
	if (&arr == nullptr || arr.size() < 2)
	{
		return 0;
	}
	sort(arr.begin(), arr.end());
	int gap = 0;
	for (int i = 1;i < arr.size();i++)
	{
		gap = max(arr[i] - arr[i - 1], gap);
	}
	return gap;
}

static vector<int> generateRandomArray(int maxsize, int maxValue)
{
	vector<int> arr;
	for (int i = 0; i < maxsize;i++)
	{
		arr.push_back(rand() % maxValue);
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

static void printArry(vector<int>& arr)
{
	if (&arr == nullptr) return;
	for (int i = 0; i < arr.size();i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

//int main()
//{
//	int testTime = 1000;
//	int maxsize = 100;
//	int maxvalue = 100;
//	bool succeed = true;
//	for (int i = 0; i < testTime; i++)
//	{
//		vector<int> arr1 = generateRandomArray(maxsize, maxvalue);
//		vector<int> arr2 = copyArray(arr1);
//
//		if (maxGap(arr1) != comparator(arr2))
//		{
//			succeed = false;
//			break;
//		}
//	}
//	if (succeed)
//	{
//		cout << "NICE" << endl;
//	}
//	else
//	{
//		cout << "FALSE" << endl;
//	}
//
//	return 0;
//}