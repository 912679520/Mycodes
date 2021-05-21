#include<iostream>
#include<queue>
using namespace std;

/*
	˼·�� �������
	1�������Һ��ӣ�û����false
	2��������û�ң��������Ҷ�û�У�
	��ô������ֵı��붼��Ҷ�ӽڵ㣨������ֵĶ�û�к��ӣ�
	3������Υ��1��2����������ȫ������
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
	bool leaf = false; // ����2
	Node* l = NULL;
	Node* r = NULL;
	que.push(head);
	while (!que.empty())
	{
		head = que.front();
		l = head->left;
		r = head->right;
		que.pop();

		if ((leaf && (l != NULL || r != NULL)) //����2��
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
