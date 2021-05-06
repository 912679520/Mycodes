#include<iostream>
#include<unordered_map>
using namespace std;

static class Node
{
public:
	int val;
	Node* next;
	Node* random;
	Node(int value) :val(value) {}
};

static Node* copyListWithRand(Node* head)
{
	if (head == NULL) return head;

	unordered_map<Node*, Node*> map;
	for (Node* cur = head; cur != NULL; cur = cur->next)
	{
		map[cur] = new Node(cur->val);
	}

	for (Node* cur = head; cur != NULL; cur = cur->next)
	{
		map[cur]->next = map[cur->next];
		map[cur]->random = map[cur->random];
	}
	return map[head];
}

static void printList(Node* head)
{
	cout << "List :" << endl;
	Node* cur = head;
	while (cur != NULL)
	{
		cout << cur->val << "->";
		cur = cur->next;
	}
	cout << endl;
	cur = head;
	cout << "random: " << endl;
	while (cur != NULL)
	{
		if (cur->random == NULL)
		{
			cout << "-";
		}
		else
		{
			cout << cur->random->val << "->";
		}
		cur = cur->next;
	}
	cout << endl;
}

//int main()
//{
//	Node *head = NULL;
//	Node *res1 = NULL;
//
//	head = new Node(1);
//	head->next = new Node(2);
//	head->next->next = new Node(3);
//	head->next->next->next = new Node(4);
//	head->next->next->next->next = new Node(5);
//	head->next->next->next->next->next = new Node(6);
//
//	head->random = head->next->next->next->next->next; // 1 -> 6
//	head->next->random = head->next->next->next->next->next; // 2 -> 6
//	head->next->next->random = head->next->next->next->next; // 3 -> 5
//	head->next->next->next->random = head->next->next; // 4 -> 3
//	head->next->next->next->next->random = NULL; // 5 -> null
//	head->next->next->next->next->next->random = head->next->next->next; // 
//
//	printList(head);
//	res1 = copyListWithRand(head);
//	printList(res1);
//
//	return 0;
//}