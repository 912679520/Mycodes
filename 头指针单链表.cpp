#include"list.h"
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

//此处的list是头指针变量的地址
void InitList(List **list)
{
	if (list == NULL) exit(0);

	*list = NULL;
}

static List* _ApplyNode(ElemType val, List* next)
{
	List* s = (List*)malloc(sizeof(List));
	if (s == NULL) return NULL;

	s->data = val;
	s->next = next;

	return s;
}

void InsertListHead(List** list, ElemType val)
{
	if (list == NULL) exit(0);
	List* newNode = _ApplyNode(val, *list);
	if (newNode == NULL) exit(0);
	*list = newNode;
}

void InsertList(List** list, ElemType val, int pos)
{
	if (list == NULL) exit(0);

	if(pos < 0)
	{
		printf("Insert :: Pos is Error\n");
		return;
	}

	if(pos == 0)
	{
		InsertListHead(list, val);
	}
	else
	{
		List* p = *list;
		while (pos > 1 && p != NULL)
		{
			p = p->next;
			pos--;
		}
		if (p == NULL)
		{
			printf("Insert :: Pos is Error\n");
		}
		else
		{
			List* newNode = _ApplyNode(val, p->next);
			if (newNode == NULL) exit(0);
			p->next = newNode;
		}
	}
}

void ShowList(List** list)
{
	if (list == NULL) exit(0);

	List* p = *list;
	while(p != NULL)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("NULL\n");
}

void InsertListTail(List** list, ElemType val)
{
	if (list == NULL) exit(0);

	//当前链表是空的时候，调用了尾插
	if (*list == NULL)
	{
		InsertListHead(list, val);
		return;
	}
	List* p = *list;

	while (p->next != NULL)
	{
		p = p->next;
	}

	p->next = _ApplyNode(val, NULL);
}

void DeleteListHead(List** list)
{
	if (list == NULL) exit(0);

	if (*list == NULL)
	{
		printf("List is Empty\n");
		return;
	}

	List* p = *list;
	*list = p->next;
	free(p);
}

void DeleteListTail(List** list)
{
	if (list == NULL) exit(0);

	if (*list == NULL)
	{
		printf("List is Empty\n");
		return;
	}
	//仅剩一个节点的时候
	if ((*list)->next == NULL)
	{
		DeleteListHead(list);
		return;
	}

	//至少有两个结点的时候
	List* p = *list;
	List* q = p->next;

	while (q->next != NULL)
	{
		p = q;
		q = q->next;
	}

	p->next = NULL;
	free(q);
}

void DeleteList(List** list, int pos)
{
	if (list == NULL) exit(0);

	if (*list == NULL)
	{
		printf("List is Empty\n");
	}

	if (pos < 0)
	{
		printf("Delete:: Pos is Error\n");
		return;
	}
	if (pos == 0)
	{
		DeleteListHead(list);
	}
	else
	{
		List* p = *list;
		while (pos > 1 && p->next != NULL)
		{
			p = p->next;
			pos--;
		}

		if (p->next == NULL)
		{
			printf("Delete:: Pos is Error\n");
		}
		else
		{
			List* q = p->next;
			p->next = q->next;
			free(q);
		}
	}
}

void DeleteListValue(List** list, ElemType val)
{
	if (list == NULL) exit(0);
	if (*list == NULL) return;

	if ((*list)->data == val)
	{
		DeleteListHead(list);
		DeleteListValue(list, val);
	}
	else
	{
		List* p = *list;
		List* q = p->next;

		while (q != NULL)
		{
			if (q->data == val)
			{
				p->next = q->next;
				free(q);
				q = p->next;
			}
			else
			{
				p = q;
				q = q->next;
			}
		}
	}
}

void DestroyList(List** list)
{
	if (list == NULL) exit(0);

	while (*list != NULL)
	{
		DeleteListHead(list);
	}
}