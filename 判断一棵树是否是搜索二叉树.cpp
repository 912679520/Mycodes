#include<iostream>
#include<stack>

using namespace std;

/*
	搜索二叉树：中序遍历有序
*/

class Node
{
public:
	int val;
	Node* left;
	Node* right;

	Node(int data) : val(data) {}
};

static bool isBSTTree(Node* head)
{
	if (head == NULL) return true;
	int pre = 0;
	bool p = true;

	if (head != NULL)
	{
		stack<Node*> st;
		while (head != NULL || !st.empty())
		{
			if (head != NULL)
			{
				st.push(head);
				head = head->left;
			}
			else
			{
				head = st.top();
				if (head->val >= pre)
				{
					p = true;
					pre = head->val;
				}
				else
					return false;

				st.pop();
				head = head->right;
			}
		}
	}
	return p;
}

//int main()
//{
//	Node *head = new Node(4);
//	head->left = new Node(2);
//	head->right = new Node(6);
//	head->left->left = new Node(1);
//	head->left->right = new Node(3);
//	head->right->left = new Node(5);
//
//	cout << isBSTTree(head) << endl;
//}