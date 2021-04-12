#include<iostream>
#include<vector>
using namespace std;

#if 0
void swap(vector<int> &arr,int left, int right)
{
	int tmp = arr[left];
	arr[left] = arr[right];
	arr[right] = tmp;
}

/*
给定一个数组arr，和一个数num，小于num的放在数组左边，等于的放中间
大于的放在右边
*/

static vector<int> Partition(vector<int>& arr, int num)
{
	int less = -1;
	int more = arr.size();
	int cur = 0;
	while (cur != more)
	{
		if (arr[cur] > num)
		{
			swap(arr, cur, --more);
		}
		else if (arr[cur] < num)
		{
			swap(arr, ++less, cur++);
		}
		else
		{
			cur++;
		}
	}
	return arr;
}


/*
	给定一个数组arr，和一个数num，小于等于num的放在数组左边
	大于的放在右边
*/
static vector<int> DtFlag(vector<int>& arr, int num)
{
	int less = -1;
	int cur = 0;
	while (cur != arr.size() - 1)  //4,5,6,2,1,3,9
	{
		if (arr[cur] > num)
		{
			cur++;
		}
		else
		{
			swap(arr,++less, cur++);
		}
	}
	return arr;
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

void printArry(vector<int>& arr)
{
	if (&arr == nullptr) return;
	for (int i = 0; i < arr.size();i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}


int main()
{
	vector<int> arr = generateRandomArray(12,10);
	printArry(arr);

	Partition(arr, 4);
	printArry(arr);

	DtFlag(arr, 5);
	printArry(arr);

	return 0;
}

#endif