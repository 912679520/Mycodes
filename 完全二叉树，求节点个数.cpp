#include<iostream>

using namespace std;

/*
	˼·��
	���������Ľڵ����Ϊ��2�Ĳ����η���һ
	1��ͷ�ڵ���������߽絽���һ�㣬��ͷ�ڵ�������Ϊ��������
	Ȼ��ݹ��������ڵ����
	2����������߽粻�����һ�㣬����������Ȼ������
	��������ȫ���������ݹ���ڵ�
*/

class Node
{
public:
	int val;
	Node* left;
	Node* right;

	Node(int value) : val(value) {}
};

//��߶�
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

//�ڵ����
static int countNodes(Node* head)
{
	if (head == NULL) return 0;

	int left = countLevel(head->left); //�������߶�
	int right = countLevel(head->right); //�������߶�

	if (left == right) //1 �����������һ���ˣ���������
	{
		return countNodes(head->right) + (1 << left);
	}
	else // 2 ���������������ڶ��㣬�������ݹ�
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


