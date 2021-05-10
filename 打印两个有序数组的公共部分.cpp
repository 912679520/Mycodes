#include<iostream>
using namespace std;

class Node
{
public:
	int val;
	Node* next;
	Node(int value) :val(value) {}
};

static void printCommonPart(Node* head1, Node* head2)
{
	cout << "common part is : " << endl;
	Node* p = head1;
	Node* q = head2;
	while (p != NULL && q != NULL)
	{
		if (p->val < q->val)
		{
			p = p->next;
		}
		else if (p->val > q->val)
		{
			q = q->next;
		}
		else
		{
			cout << p->val << endl;
			p = p->next;
			q = q->next;
		}
	}
	cout << endl;
}

static void printLinkList(Node* head)
{
	cout << " LinkList:" << endl;
	while (head != NULL)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

//int main()
//{
//	Node *node1 = new Node(2);
//	node1->next = new Node(3);
//	node1->next->next = new Node(9);
//	node1->next->next->next = new Node(9);
//
//	Node *node2 = new Node(1);
//	node2->next = new Node(2);
//	node2->next->next = new Node(9);
//	node2->next->next->next = new Node(9);
//	node2->next->next->next->next = new Node(9);
//	
//	printLinkList(node1);
//	printLinkList(node2);
//	printCommonPart(node1, node2);
//
//	return 0;
//}