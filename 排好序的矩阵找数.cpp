#include<iostream>
#include<vector>
using namespace std;

static bool isContains(vector<vector<int>>& matrix, int K)
{
	int row = 0;					// 右上角的行
	int cur = matrix[0].size() - 1;	//右上角的列
	while (row < matrix.size() && cur > -1)
	{
		if (matrix[row][cur] > K)
		{
			cur--;
		}
		else if (matrix[row][cur] < K)
		{
			row++;
		}
		else
		{
			return true;
		}
	}
	return false;
}

//int main()
//{
//	vector<vector<int>> m = { { 0, 1, 2, 3 },// 0
//							{ 10, 12, 13, 15 },// 1
//							{ 23, 24, 25, 26 },// 2
//							{ 44, 45, 46, 47 },// 3
//												};
//	int K = 2222;
//	cout << isContains(m, K) << endl;
//	return 0;
//}