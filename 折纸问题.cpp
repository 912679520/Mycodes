#include<iostream>
using namespace std;

/*
	类似于二叉树的中序遍历，
	左子数是下，右子树是上，头树是下
*/

static void printProcess(int i, int N, bool down)
{
	if (i > N)
		return;

	printProcess(i + 1, N, true);
	cout << (down ? "down " : "up ");
	printProcess(i + 1, N, false);
}

static void printAllFolds(int N)
{
	printProcess(1, N, true);
}

//int main()
//{
//	int N = 4;
//
//	printAllFolds(N);
//}