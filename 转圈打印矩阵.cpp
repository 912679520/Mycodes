#include<iostream>
#include<vector>
using namespace std;

void printEdge(vector<vector<int>> &matrix, int tR, int tC, int dR, int dC)
{
	if (tR == dR) // ֻ��һ��
	{
		for (int i = tC; i <= dC; i++)
		{
			cout << matrix[tR][i] << " ";
		}
	}
	else if (tC == dC)  //ֻ��һ��
	{
		for (int i = tR; i <= dR; i++)
		{
			cout << matrix[i][tC] << " ";
		}
	}
	else
	{
		int curC = tC; //��
		int curR = tR; //��
		while (curC != dC)
		{
			cout << matrix[tR][curC] << " ";
			curC++;
		}
		while (curR != dR)
		{
			cout << matrix[curR][dC] << " ";
			curR++;
		}
		while (curC != tC)
		{
			cout << matrix[dR][curC] << " ";
			curC--;
		}
		while (curR != tR)
		{
			cout << matrix[curR][tC] << " ";
			curR--;
		}
	}
}

void spira10derPrint(vector<vector<int>> &matrix)
{
	int tR = 0; //���Ͻ���
	int tC = 0; //���Ͻ���
	int dR = matrix.size() - 1; //���½�����
	int dC = matrix[0].size() - 1;
	while (tR <=dR && tC <= dC)
	{
		printEdge(matrix, tR++, tC++, dR--, dC--);
	}
}

//
//int main()
//{
//	vector<vector<int>> m = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
//
//	spira10derPrint(m);
//
//	return 0;
//}