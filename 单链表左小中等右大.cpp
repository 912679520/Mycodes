#include<iostream>
#include<vector>
using namespace std;

static class Node
{
public:
	int val;
	Node* next;
	Node(int data) :val(data) {}
};

static void arrPartition(vector<Node*> arr, int privot)
{
	int small = -1;
	int big = arr.size();
	int index = 0;
	while (index != big)
	{
		if (arr[index]->val > privot)
		{
			swap(arr[index]->val, arr[--big]->val);
		}
		else if (arr[index]->val < privot)
		{
			swap(arr[++small]->val, arr[index++]->val);
		}
		else
		{
			index++;
		}
	}
}

static Node* listParttition1(Node* head, int privot)
{
	if (head == NULL) return NULL;
	Node* cur = head;
	int i = 0;
	while (cur != NULL) //³¤¶È
	{
		i++;
		cur = cur->next;
	}
	vector<Node*> arr(i);
	cur = head;
	i = 0;
	for (i = 0; i != arr.size(); i++)
	{
		arr[i] = cur;
		cur = cur->next;
	}
	arrPartition(arr, privot);
	
	for (i = 1; i != arr.size(); i++)
	{
		arr[i - 1]->next = arr[i];
	}
	arr[i - 1]->next = NULL;

	return arr[0];
}

static void show(Node* head)
{
	cout << "Link List: " << endl;
	while (head != NULL)
	{
		cout << head->val << "->";
		head = head->next;
	}
	cout << endl;
}

//int main()
//{
//	Node *head1 = new Node(9);
//	head1->next = new Node(0);
//	head1->next->next = new Node(3);
//	head1->next->next->next = new Node(3);
//	head1->next->next->next->next = new Node(1);
//
//	show(head1);
//
//	head1 = listParttition1(head1, 3);
//	show(head1);
//
//	return 0;
//}