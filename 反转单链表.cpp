#include<iostream>
#include<stack>
using namespace std;

class Node
{
public:
	int value;
	Node* next;
	Node(int val) : value(val) {}
};


//static struct Node
//{
//public:
//	int value;
//	Node* next;
//};
//
//static Node* create_Link()
//{
//	Node* head = NULL;
//	Node* cur = NULL;
//	Node* tmp = NULL;
//	int val = 0, num_node = 5;
//	for (int i = 0; i < num_node; i++)
//	{	
//		val = i + 1;	
//		if (i == 0)
//		{
//			cur = (Node*)new(Node);
//			cur->value = val;
//			cur->next = NULL;
//			head = cur;
//		}
//		else
//		{
//			tmp = (Node*)new(Node);
//			tmp->value = val;
//			tmp->next = NULL;
//			cur->next = tmp;
//			cur = cur->next;
//		}
//	}
//	return head;
//}

//栈实现
static Node* reverseList_Stack(Node *head)
{
	Node* cur = head;
	Node* new_head;
	Node* tmp = NULL;
	stack<Node*> sta;
	while (cur != NULL)
	{
		sta.push(cur);
		cur = cur->next;
	}

	if (sta.empty()) return NULL;

	cur = sta.top();
	sta.pop();
	new_head = cur;
	while (!sta.empty())
	{
		tmp = sta.top();
		sta.pop();
		cur->next = tmp;
		cur = tmp;
	}
	tmp->next = NULL;
	return new_head;
}

//递归实现
static void reverseList_Recursive(Node* head)
{
	//Node* new_head = NULL;
	if (head != NULL)
	{
		if(head->next != NULL)
			reverseList_Recursive(head->next);
		cout << head->value << "->";
	}
}

static Node* reverseList(Node* head)
{
	Node* pre = NULL;
	Node* next = NULL;
	while (head != NULL)
	{
		next = head->next;
		head->next = pre;
		pre = head;
		head = next;	
	}
	return pre;
}

static void print(Node* head)
{
	cout << "LinkList :" << endl;
	Node* cur = head;

	while (cur != NULL)
	{
		cout << cur->value << "->";
		cur = cur->next;
	}
	cout << endl;
}

//int main()
//{
//	Node* head = new Node(1);
//	head->next = new Node(2);
//	head->next->next = new Node(3);
//	head->next->next->next = new Node(4);
//	print(head);
//
//	Node* hed = reverseList(head);
//	print(hed);
//
//	return 0;
//}