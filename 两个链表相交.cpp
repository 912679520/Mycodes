#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Node
{
public:
	int value;
	Node* next;
	Node(int val) : value(val) {}
};

//判断链表是否有环，有返回环节点，无则返回NULL
static Node* getLoopNode(Node* head)
{	
	if (head == NULL) return NULL;
	
	Node* fast = head->next->next;
	Node* last = head->next;
	
	while (fast != last) //找到环节点
	{
		if (fast->next == NULL || fast->next->next == NULL)
		{
			return NULL;
		}
		last = last->next;
		fast = fast->next->next;
	}
	fast = head;
	while (fast != last)
	{
		last = last->next;
		fast = fast->next;
	}
	return last;
}

//无环相交
static Node* noLoop(Node* head1, Node* head2)
{
	if (head1 == NULL || head2 == NULL)
	{
		return NULL;
	}
	Node* cur1 = head1;
	Node* cur2 = head2;

	int n = 0;

	while (cur1 != NULL)
	{
		n++;
		cur1 = cur1->next;
	}
	while (cur2 != NULL)
	{
		n--;
		cur2 = cur2->next;
	}

	cur1 = n > 0 ? head1 : head2;
	cur2 = cur1 == head1 ? head2 : head1;
	n = abs(n);
	while (n != 0)
	{
		n--;
		cur1 = cur1->next;
	}

	while (cur1 != cur2)
	{
		cur1 = cur1->next;
		cur2 = cur2->next;
	}
	return cur1;
}

//两个有环链表相交
static Node* bothLoop(Node* head1, Node* loop1, Node* head2, Node* loop2)
{
	Node* cur1 = NULL;
	Node* cur2 = NULL;
	int len = 0;
	//若相交
	if (loop1 == loop2)
	{
		cur1 = head1;
		cur2 = head2;
		while (cur1 != NULL)
		{
			len++;
			cur1 = cur1->next;
		}
		while (cur2 != NULL)
		{
			len--;
			cur2 = cur2->next;
		}

		cur1 = len > 0 ? head1 : head2;
		cur2 = cur1 == head1 ? head2 : head1;
		len = abs(len);
		while (len != 0)
		{
			len--;
			cur1 = cur1->next;
		}
		while (cur1 != cur2)
		{
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		return cur1;
	}

	else
	{
		cur1 = loop1->next;
		while (cur1 != loop2)
		{
			if (cur1 == loop2)
			{
				return loop1;
			}
			cur1 = cur1->next;
		}
		return NULL;
	}
}

static Node* getIntersectNode(Node* head1, Node* head2)
{
	if (head1 == NULL || head2 == NULL)
	{
		return NULL;
	}
	Node* loop1 = getLoopNode(head1);
	Node* loop2 = getLoopNode(head2);
	if (loop1 == NULL && loop2 == NULL) //无环节点相交
	{
		return noLoop(head1, head2);
	}
	if (loop1 != NULL && loop2 != NULL)
	{
		return bothLoop(head1, loop1, head2, loop2);
	}
	return NULL;
}



void main()
{
	// 1->2->3->4->5->6->7->null
	Node *head1 = new Node(1);
	head1->next = new Node(2);
	head1->next->next = new Node(3);
	head1->next->next->next = new Node(4);
	head1->next->next->next->next = new Node(5);
	head1->next->next->next->next->next = new Node(6);
	head1->next->next->next->next->next->next = new Node(7);

	// 0->9->8->6->7->null
	Node *head2 = new Node(0);
	head2->next = new Node(9);
	head2->next->next = new Node(8);
	head2->next->next->next = head1->next->next->next->next->next; // 8->6
	cout << getIntersectNode(head1, head2)->value << endl;
	

	// 1->2->3->4->5->6->7->4->->->
	head1 = new Node(1);
	head1->next = new Node(2);
	head1->next->next = new Node(3);
	head1->next->next->next = new Node(4);
	head1->next->next->next->next = new Node(5);
	head1->next->next->next->next->next = new Node(6);
	head1->next->next->next->next->next->next = new Node(7);
	head1->next->next->next->next->next->next = head1->next->next->next; // 7->4

	// 0->9->8->2->->->
	head2 = new Node(0);
	head2->next = new Node(9);
	head2->next->next = new Node(8);
	head2->next->next->next = head1->next; // 8->2
	cout << getIntersectNode(head1, head2)->value << endl;

	// 0->9->8->6->4->5->6->->
	head2 = new Node(0);
	head2->next = new Node(9);
	head2->next->next = new Node(8);
	head2->next->next->next = head1->next->next->next->next->next; // 8->6
	cout << getIntersectNode(head1, head2)->value << endl;

}