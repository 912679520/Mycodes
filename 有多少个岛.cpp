
/*
˼·��
����1�������������Ҹ�д��2��������+1������0������2ֱ��
����
*/

#include<iostream>
#include<vector>

using namespace std;

static void infect(vector<vector<int>>& m,int i, int j, int N, int M)
{
	if (i < 0 || j < 0 || i >= N || j >= M || m[i][j] != 1)
	{
		return;
	}
	m[i][j] = 2;
	infect(m, i + 1, j, N, M); //��Ⱦ��
	infect(m, i - 1, j, N, M);//��
	infect(m, i, j - 1, N, M);//��
	infect(m, i, j + 1, N, M);//��

}

static int countIslands(vector<vector<int>>& m)
{
	if (m.empty()) return NULL;

	int N = m.size();
	int M = m[0].size();
	int res = 0; //��������
	for(int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			if (m[i][j] == 1)
			{
				res++;
				infect(m, i, j, N, M);
			}
		}
	return res;
}

//int main()
//{
//	vector<vector<int> > m = { { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
//						{ 0, 1, 1, 1, 0, 1, 1, 1, 0 },
//						{ 0, 1, 1, 1, 0, 0, 0, 1, 0 },
//						{ 0, 1, 1, 0, 0, 0, 0, 0, 0 },
//						{ 0, 0, 0, 0, 0, 1, 1, 0, 0 },
//						{ 0, 0, 0, 0, 1, 1, 1, 0, 0 },
//						{ 0, 0, 0, 0, 0, 0, 0, 0, 0 }, };
//
//	cout << countIslands(m) << endl;
//
//	vector<vector<int> > m1 = { { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
//						{ 0, 1, 1, 1, 1, 1, 1, 1, 0 },
//						{ 0, 1, 1, 1, 0, 0, 0, 1, 0 },
//						{ 0, 1, 1, 0, 0, 0, 1, 1, 0 },
//						{ 0, 0, 0, 0, 0, 1, 1, 0, 0 },
//						{ 0, 0, 0, 0, 1, 1, 1, 0, 0 },
//						{ 0, 0, 0, 0, 0, 0, 0, 0, 0 }, };
//	cout << countIslands(m1) << endl;
//}