#include<iostream>
#include<vector>

using namespace std;

class TreeNode
{
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
	{
		if (preorder.empty() || inorder.empty()) return NULL;

		if (preorder.size() != inorder.size()) return NULL;

		return createTree(preorder, inorder, 0, 0, inorder.size() - 1);
	}
	int FindIs(const vector<int>& inorder, int val)
	{
		int pos = -1;
		for (int i = 0; i < inorder.size(); i++)
		{
			if (inorder[i] == val)
			{
				pos = i;
				break;
			}
		}
		return pos;
	}
	TreeNode* createTree(vector<int>& preorder, vector<int>& inorder, int root,int start,int end)
	{
		if (start > end) return NULL;
		TreeNode* s = new TreeNode(preorder[root]);

		int pos = FindIs(inorder,preorder[root]);

		s->left = createTree(preorder, inorder, root + 1, start, pos - 1);
		s->right = createTree(preorder, inorder, root + 1 + pos - start, pos + 1, end);

		return s;
	}
};

//int main()
//{
//	vector<int> pre = { 3,9,20,15,7 };
//	vector<int> ino = { 9,3,15,20,7 };
//
//	Solution s;
//	s.buildTree(pre, ino);
//	return 0;
//}