#include<iostream>
#include<stack>
using namespace std;

static class Node
{
public:
	int value;
	Node* next;
	Node(int val) :value(val) {}
};

//利用栈
static bool isPalindrome1(Node* head)
{
	stack<Node*> st;
	Node* cur = head;
	while (cur != NULL)
	{
		st.push(cur);
		cur = cur->next;
	}
	while (head != NULL)
	{
		if (head->value != st.top()->value)
		{
			return false;
		}
		head = head->next;
		st.pop();
	}
	return true;
}

//将链表一半放入栈
static bool isPalindrome2(Node* head)
{
	Node* cur = head;
	Node* right = head->next;
	while (cur->next != NULL && cur->next->next != NULL)
	{
		right = right->next;
		cur = cur->next->next;
	}
	stack<Node*> st;
	while (right != NULL)
	{
		st.push(right);
		right = right->next;
	}
	while (!st.empty())
	{
		if (st.top()->value != head->value)
		{
			return false;
		}
		st.pop();
		head = head->next;
	}
	return true;
}

static bool isPalindrome3(Node* head)
{
	Node* n1 = head;
	Node* n2 = head;
	//找中点，为n1
	while (n2->next != NULL && n2->next->next != NULL)
	{
		n1 = n1->next;
		n2 = n2->next->next;
	}
	Node* n3 = NULL;
	n2 = n1->next;
	n1->next = NULL;
	while (n2 != NULL) // 将后半部分指针换方向
	{
		n3 = n2->next;
		n2->next = n1;
		n1 = n2;
		n2 = n3;
	}
	n3 = n1;
	n2 = head;
	bool fa = true;
	while (n1 != NULL && n2 != NULL) //比较前半部分和后半部分
	{
		if (n1->value != n2->value)
		{
			fa = false;
			break;
		}
		n1 = n1->next;
		n2 = n2->next;
	}
	n2 = n3->next;
	n3->next = NULL;
	while (n2 != NULL) // 恢复成链表
	{
		n1 = n2->next;
		n2->next = n3;
		n3 = n2;
		n2 = n1;
	}
	return fa;
}

static void printLinkedList(Node* node)
{
	cout << "Link List: ";
	while (node != NULL)
	{
		cout << node->value << " ";
		node = node->next;
	}
	cout << endl;
}

//int main()
//{
//	Node* head = NULL;
//	head = new Node(1);
//	head->next = new Node(3);
//	head->next->next = new Node(3);
//	head->next->next->next = new Node(2);
//	head->next->next->next->next = new Node(1);
//	printLinkedList(head);
//	if (isPalindrome3(head))
//	{
//		cout << "True" << endl;
//	}
//	else
//	{
//		cout << "False" << endl;
//	}
//	return 0;
//}