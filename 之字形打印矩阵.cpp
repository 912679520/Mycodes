#include<vector>
#include<iostream>
using namespace std;

static void printLevel(vector<vector<int>>& matrix, int tR, int tC, int dR, int dC,
						bool f)
{
	if (f)
	{
		while (tR != dR + 1)
		{
			cout << matrix[tR++][tC--] << " ";
		}
	}
	else
	{
		while (dR != tR - 1)
		{
			cout << matrix[dR--][dC++] << " ";
		}
	}
}

static void printMatrixZigZag(vector<vector<int>>& matrix)
{
	int tR = 0, tC = 0;
	int dR = 0, dC = 0;
	int endR = matrix.size() - 1;
	int endC = matrix[0].size() - 1;
	bool f = false;
	while (tR != endR + 1)
	{
		printLevel(matrix, tR, tC, dR, dC, f);
		tR = tC == endC ? tR + 1 : tR;
		tC = tC == endC ? tC : tC + 1;
		dC = dR == endR ? dC + 1 : dC;
		dR = dR == endR ? dR : dR + 1;
		f = !f;
	}
	cout << endl;
}

//int main()
//{
//	vector<vector<int>> m = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
//	printMatrixZigZag(m);
//	return 0;
//}