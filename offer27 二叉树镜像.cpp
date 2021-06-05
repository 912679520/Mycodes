#include<iostream>
#include<queue>
using namespace std;

/*
二叉树镜像：
1、将二叉树按层遍历反过来，先入右孩子
二叉树按层遍历：队列

*/

class TreeNode
{
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	TreeNode* mirrorTree(TreeNode* root)
	{
		queue<TreeNode*> q;
		if (root != NULL)
		{
			q.push(root);
		}

		while (!q.empty())
		{
			cout << q.front()->val << ",";
			if (q.front()->right != NULL)
			{
				q.push(q.front()->right);
			}
			if (q.front()->left != NULL)
			{
				q.push(q.front()->left);
			}
			q.pop();
		}
		return root;
	}

	//递归
	TreeNode* mirrorTree1(TreeNode* root)
	{
		if (root == nullptr) return NULL;
		if (root->left == nullptr && root->right == nullptr)
			return NULL;

		swap(root->left, root->right);

		if (root->left) mirrorTree1(root->left);
		if (root->right) mirrorTree1(root->right);
	}
};

//int main()
//{
//	TreeNode* root = new TreeNode(4);
//	root->left = new TreeNode(2);
//	root->right = new TreeNode(7);
//
//	root->left->left = new TreeNode(1);
//	root->left->right = new TreeNode(3);
//
//	root->right->left = new TreeNode(6);
//	root->right->right = new TreeNode(9);
//
//	Solution a;
//	a.mirrorTree(root);
//
//	return 0;
//}