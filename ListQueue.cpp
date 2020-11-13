#include "ListQueue.h"
#include<stdlib.h>
#include<string.h>

static ListNode* ApplyNode(ElemType val, ListNode* next)
{
	ListNode* s = (ListNode*)malloc(sizeof(ListNode));
	if (s == NULL) return NULL;

	s->data = val;
	s->next = next;

	return s;
}

void InitListQue(ListQue *Que)
{
	if (Que == NULL) exit(0);

	Que->front = Que->rear = NULL;

}

int Empty(ListQue* Que)
{
	if (Que == NULL) exit(0);

	return Que->rear == NULL ? 1 : 0;
}

void Push(ListQue* Que, ElemType val)
{
	if (Que == NULL) exit(0);

	ListNode* newnode = ApplyNode(val, NULL);
	if (newnode == NULL) return;

	if (Empty(Que))//如队前，空
	{
		Que->front = Que->rear = newnode;
	}
	else//入队前，非空
	{
		Que->rear->next = newnode;
		Que->rear = newnode;
	}
}

void Pop(ListQue* Que)
{
	if (Que == NULL) exit(0);

	if (Empty(Que)) return;

	//队列只有一个结点
	if (Que->front == Que->rear)
	{
		free(Que->front);
		Que->front = Que->rear = NULL;
	}
	//队列有两个以上结点
	else
	{
		ListNode* p = Que->front;
		Que->front = Que->front->next;
		free(p);
	}
}

int GetHead(ListQue* Que, ElemType *val)
{
	if (Que == NULL) exit(0);

	if (Empty(Que)) return 0;

	*val = Que->front->data;
	return 1;
}

void DestroyListQue(ListQue* Que)
{
	while (!Empty(Que))
	{
		Pop(Que);
	}
}

