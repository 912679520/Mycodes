
#include"doublelist.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

static DList* _ApplyNode(ElemType val, DList* prior, DList* next)
{
	DList* s = (DList*)malloc(sizeof(DList));
	if (s == NULL) return NULL;
	
	s->data = val;
	s->next = next;
	s->prior = prior;

	return s;
}

void InitDList(DList* head)
{
	if (head == NULL) exit(0);

	head->next = head->prior = NULL;

}

void InsertPos(DList* head, ElemType val, int pos)
{
	if (head == NULL) exit(0);

	if (pos < 0) return;
	
	DList* p = head;
	while (pos && p != NULL)
	{
		p = p->next;
		pos--;
	}

	if (p == NULL) return;
	DList* s = _ApplyNode(val, p, p->next);
	if (s == NULL) return;

	if(p->next != NULL) p->next->prior = s;		
	p->next = s;//将新节点插入
	
}

void InsetrHead(DList* head, ElemType val)
{
	InsertPos(head, val, 0);
}

void InsertTail(DList* head, ElemType val)
{
	if (head == NULL) exit(0);

	DList* p = head;
	while (p->next != NULL) p = p->next;		
		
	p->next = _ApplyNode(val, p, NULL);
}

void DeletePos(DList* head, int pos)
{
	if (head == NULL) exit(0);

	if (pos < 0) return;

	DList* p = head;
	while (pos && p->next != NULL)
	{
		p = p->next;
		pos--;
	}

	if (p->next == NULL) return;

	DList* q = p->next;

	p->next = q->next;
	if(q->next != NULL)	q->next->prior = p;

	free(q);
}

void DeleteHead(DList* head)
{
	DeletePos(head, 0);
}

void DeleteTail(DList* head)
{
	if (head == NULL) exit(0);

	DList* p = head;
	while (p->next != NULL)
	{
		p = p->next;
	}

	if (p == head) return;//要是头节点

	p->prior->next = NULL;//尾删

	free(p);
}

void ShowDList(DList* head)
{
	if (head == NULL) return;

	DList* p = head;

	while (p->next != NULL)
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

void Destroy(DList* head)
{
	if (head == NULL) exit(0);

	while (head->next != NULL) DeleteHead(head);
}
