#include<iostream>
#include<vector>
using namespace std;

static void rotateEdge(vector<vector<int>>& m, int tR, int tC, int dR, int dC)
{
	int time = dR - tR;
	int tmp = 0;
	for (int i = 0; i < time; i++)
	{
		tmp = m[tR][tC + i];
		m[tR][tC + i] = m[dR - i][tC];
		m[dR - i][tC] = m[dR][dC - i];
		m[dR][dC - i] = m[tR + i][dC];
		m[tR + i][dC] = tmp;
	}
}

static void rotate(vector<vector<int>>& matrix)
{
	int tR = 0;
	int tC = 0;
	int dR = matrix.size() - 1; //3
	int dC = matrix[0].size() - 1; //3
	while (tR < dR)
	{
		rotateEdge(matrix, tR++, tC++, dR--, dC--);
	}
}



static void show(vector<vector<int>>& m)
{
	for (int i = 0; i < m.size();i++)
	{
		for (int j = 0; j < m[0].size();j++)
		{
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
}

//int main()
//{
//	vector<vector<int>> m = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
//	show(m);
//	cout << "顺时针旋转90度后：" << endl;
//	rotate(m);
//	show(m);
//	return 0;
//}