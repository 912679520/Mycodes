#include<iostream>

using namespace std;

/*
	思路：
	满二叉树的节点个数为：2的层数次方减一
	1）头节点右子树左边界到最后一层，则头节点左子树为满二叉树
	然后递归求右数节点个数
	2）右子树左边界不到最后一层，则右子树必然是满的
	左树是完全二叉树，递归求节点
*/

class Node
{
public:
	int val;
	Node* left;
	Node* right;

	Node(int value) : val(value) {}
};

//求高度
static int countLevel(Node* head)
{
	int level = 0;
	while (head != NULL)
	{
		level++;
		head = head->left;
	}
	return level;
}

//节点个数
static int countNodes(Node* head)
{
	if (head == NULL) return 0;

	int left = countLevel(head->left); //左子树高度
	int right = countLevel(head->right); //右子树高度

	if (left == right) //1 右子树到最后一层了，左子树满
	{
		return countNodes(head->right) + (1 << left);
	}
	else // 2 右子树满到倒数第二层，左子树递归
	{
		return countNodes(head->left) + (1 << right);
	}
}

//int main()
//{
//	Node *head = new Node(1);
//	head->left = new Node(2);
//	head->right = new Node(3);
//	head->left->left = new Node(4);
//	head->left->right = new Node(5);
//	head->right->left = new Node(6);
//
//	cout << countNodes(head) << endl;
//}


