#include<iostream>
using namespace std;

class DoubleNode
{
public:
	int value;
	DoubleNode* last;
	DoubleNode* next;
	DoubleNode(int data) : value(data) {}
	
};

static DoubleNode* reverseList(DoubleNode* head)
{
	DoubleNode* pre = NULL;
	DoubleNode* next = NULL;
	while (head != NULL)
	{
		next = head->next;
		head->next = pre;
		head->last = next;
		pre = head;
		head = next;
	}
	return pre;
}

static void print(DoubleNode* head)
{
	cout << "Double list::" << endl;
	DoubleNode* end = NULL;
	while (head != NULL)
	{
		cout << head->value << " ";
		end = head;
		head = head->next;
	}
	cout << "| " << endl;
	while (end != NULL)
	{
		cout << end->value << " ";
		end = end->last;
	}
	cout << endl;
}

//int main()
//{
//	DoubleNode *head = new DoubleNode(1);
//	head->next = new DoubleNode(2);
//	head->next->last = head;
//	head->next->next = new DoubleNode(3);
//	head->next->next->last = head->next;
//	head->next->next->next = new DoubleNode(4);
//	head->next->next->next->last = head->next->next;
//
//	print(head);
//	print(reverseList(head));
//}