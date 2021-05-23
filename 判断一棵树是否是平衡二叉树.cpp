#include<iostream>

using namespace std;

/*
	左子树和右子树的高度差不大于1
*/

static class Node
{
public:
	int val;
	Node* left;
	Node* right;

	Node(int data) : val(data) {}
};

static int getHeight(Node* head, int level, bool res[])
{
	if (head == NULL) return level;

	int LH = getHeight(head->left, level + 1, res);
	if (!res[0]) return level;

	int RH = getHeight(head->right, level + 1, res);
	if (!res[0]) return level;

	if (abs(LH - RH) > 1)
	{
		res[0] = false;
	}

	return max(LH, RH);
}

static bool isBalance(Node* head)
{
	bool res[1];
	res[0] = true;
	getHeight(head, 1, res);
	return res[0];
}

//int main()
//{
//	Node *head = new Node(1);
//	head->left = new Node(2);
//	head->right = new Node(3);
//	head->left->left = new Node(4);
//	head->left->right = new Node(5);
//	head->right->left = new Node(6);
//	head->right->right = new Node(7);
//
//	cout << isBalance(head) << endl;
//}
