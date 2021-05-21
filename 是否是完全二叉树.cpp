#include<iostream>
#include<queue>
using namespace std;

/*
	思路： 按层遍历
	1）、有右孩子，没左，则false
	2）、有左没右，或者左右都没有，
	那么后面出现的必须都是叶子节点（后面出现的都没有孩子）
	3）、不违反1，2，则它是完全二叉树
*/

class Node
{
public:
	int val;
	Node* left;
	Node* right;

	Node(int value) : val(value) {}
};

static bool isCBT(Node* head)
{
	if (head == NULL) return true;

	queue<Node*> que;
	bool leaf = false; // 开启2
	Node* l = NULL;
	Node* r = NULL;
	que.push(head);
	while (!que.empty())
	{
		head = que.front();
		l = head->left;
		r = head->right;
		que.pop();

		if ((leaf && (l != NULL || r != NULL)) //开启2，
			|| (l == NULL && r != NULL)) // 1
			return false;
		if (l != NULL)
		{
			que.push(l);
		}
		if (r != NULL)
		{
			que.push(r);
		}
		else           /////    if(l == NULL || r == NULL) leaf = true;
		{
			leaf = true;
		}
	}
	return true;
}

//int main()
//{
//	Node *head = new Node(4);
//	head->left = new Node(2);
//	head->right = new Node(6);
//	head->left->left = new Node(1);
//	head->left->right = new Node(3);
//	head->right->right = new Node(5);
//
//	cout << isCBT(head) << endl;
//}
