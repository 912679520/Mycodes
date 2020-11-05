#include"looplist.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

static LoopList* _ApplyNode(ElemType val, LoopList* prior, LoopList* next)
{
	LoopList* s = (LoopList*)malloc(sizeof(LoopList));
	if (s == NULL) return NULL;

	s->data = val;
	s->next = next;
	s->prior = prior;

	return s;
}

void InitLoopList(LoopList* head)
{
	if (head == NULL) exit(0);

	head->next = head->prior = head;
}

void InsertLoopListPos(LoopList* head, ElemType val, int pos)
{
	if (head == NULL) exit(0);

	if (pos < 0) return;

	LoopList* p = head;
	while (pos)
	{
		p = p->next;
		pos--;
	}

	LoopList* s = _ApplyNode(val, p, p->next);
	if (s == NULL) return;

	p->next->prior = s;
	p->next = s;//将新节点插入

}

void InsertLoopListHead(LoopList* head, ElemType val)
{
		InsertLoopListPos(head, val, 0);

}

void InsertLoopListTail(LoopList* head, ElemType val)
{
	if (head == NULL) exit(0);

	LoopList* p = head;
	while (p->next != head)
	{
		p = p->next;
	}

	p->next = _ApplyNode(val, p->prior, head);
}

void DeleteLoopListPos(LoopList* head, int pos)
{
	if (head == NULL) exit(0);

	if (pos < 0) return;

	LoopList* p = head;
	while (pos && p->next != head)
	{
		p = p->next;
		pos--;
	}

	LoopList* q = p->next;

	p->next = q->next;
	q->next->prior = p;

	free(q);

}

void DeleteLoopListHead(LoopList* head)
{
	DeleteLoopListPos(head, 0);
}

void DeleteLoopListTail(LoopList* head)
{
	if (head == NULL) exit(0);

	LoopList* p = head;
	while (p->next != head)
	{
		p = p->next;
	}

	p->prior->next = head;
	head->prior = p->prior->prior;

	free(p);
}

void ShowLoopList(LoopList* head)
{
		if (head == NULL) return;

		LoopList* p = head;

		while (p->next != head)
		{
			printf("%d-->", p->next->data);
			p = p->next;
		}

		printf("NULL\n");

		while (p != head)
		{
			printf("%d-->", p->data);
			p = p->prior;
		}
		printf("NULL\n");
	}

void DestroyLoopList(LoopList* head)
{
	if (head == NULL) exit(0);
	while(head->next != head) 	DeleteLoopListHead(0);
}