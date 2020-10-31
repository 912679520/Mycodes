#include"linklist.h"
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

static LinkList* AppLyNode(ElemType val, LinkList* next)
{
	LinkList *s =(LinkList*)malloc(sizeof(LinkList));
	if (s ==NULL) return NULL;

	s->data =val;
	s->next = next;

	return s;
}

void InitLinkList(LinkList* list)
{
	if(list == NULL) exit(0);

	list->next =NULL;
}

void InsertLinkList(LinkList* list, ElemType val,int pos)
{
	if (list == NULL) exit(0);

	if(pos < 0)
	{
		printf("Pos is Error\n");
		return;
	}

	LinkList *p = list;

	//1、找到Pos位置的前一个节点 2、如果pos位置超过Length则pos为空
	while(pos && p != NULL)
	{
		p = p->next;
		pos--;
	}

	if (p == NULL)
	{
		printf("Pos is Error\n");//Pos > Length
		return;
	}
	LinkList *newNode = AppLyNode(val, p->next);
	if(newNode == NULL) return;

	p->next = newNode;
}

void ShowLinkList(LinkList *list)
{
	if (list == NULL) exit(0);

	LinkList *p = list->next;//p指向第一个数据结点

	while(p != NULL)
	{
		printf("%d -->",p->data);
		p = p->next;
	}
	printf("NULL\n");
}

void InsertLinkListHead(LinkList* list, ElemType val)
{
	if(list == NULL) exit(0);

	InsertLinkList(list, val, 0);
}

void InsertLinkListTail(LinkList* list, ElemType val)
{
	if(list == NULL) exit(0);

	LinkList *p = list;

	while(p->next != NULL) p = p->next;

	LinkList *s = AppLyNode(val, NULL);
	if(s == NULL) return;
	p->next = s;
}

void DeleteLinkList(LinkList* list,int pos)
{
	 if (list == NULL) exit(0);

	 LinkList *p = list;

	 while(pos && p != NULL)
	 {
		 p = p->next;
		 pos--;
	 }

	 if (p->next == NULL) return;

	 LinkList *q = p->next;//使用q将要删除的节点记录
	 p->next = q->next;
	 free(q);
}

void DeleteLinkListHead(LinkList *list)
{
	if (list == NULL) exit(0);

	DeleteLinkList(list, 0);
}

void DeleteLinkListTail(LinkList *list)
{
	if (list == NULL) exit(0);

	LinkList *p = list;
	LinkList *q = p->next;

	while (q != NULL && q->next != NULL)
	{
		p = p->next;
		q= q->next;
	}

	if (q == NULL) return;

	p->next = NULL;
	free(q);
}

//要求时间复杂度为O(n), 能够删除重复的元素
void DeleteLinkListValue(LinkList *list, ElemType val)
{
	if (list == NULL) exit(0);

	LinkList *p = list;
	LinkList *q = p->next;

	while (q != NULL)
	{
		if(q->data == val)
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

void DestroyLinkList(LinkList *list)
{
	if(list == NULL) exit(0);

	while(list->next != NULL)
	{
		DeleteLinkListHead(list);
	}
}

//////////////////////////////////////////////////////////////////////

//1、删除非尾节点
bool DeleteNodeFromP(LinkList* list, LinkList* p)//单链表习题
{
	if (list == NULL || p == NULL) return false;

	//如果p是尾节点，直接调用尾删
	if (p->next == NULL) 
	{
		DeleteLinkListTail(list);
		return true;
	}

	LinkList* q = p->next;//q是将来真正删除的结点
	p->data = q->data;
	p->next = q->next;

	free(q);
	return true;
}

//2、找倒数第k个结点
LinkList* FindNodeOfK(LinkList* list, int k)
{
	/*
		方案1、先求长度，然后从前向后找正数第length - k + 1
		方案2、双指针，先让一个指针走k次，然后两个指针一起向后走，
		直到先走的指针走到空
	*/

	//方案2
	if (list == NULL || k <= 0) return NULL;

	LinkList* p = list, * q = list;

	while (k && q != NULL)
	{
		q = q->next;
		k--;
	}

	if (q == NULL) return NULL;

	while (q != NULL)
	{
		p = p->next;
		q = q->next;
	}

	return p;
}

//3、判断两个单链表是否相交，如果相交返回相交的第一个节点
LinkList* IsInterSection(LinkList* list1, LinkList* list2)
{
	if (list1 == NULL || list2 == NULL) return NULL;

	LinkList* p = list1;
	LinkList* q = list2;

	while (p != q)
	{
		p = p->next == NULL ? list2 : p->next;
		q = q->next == NULL ? list1 : q->next;
	}
	/*
	while (p != q)
	{
		p = p->next;
		q = q->next;

		if (p == NULL)
		{
			p = list2;
		}

		if (q == NULL)
		{
			q = list1;
		}
	}
	*/
	return p;
}

//4、判断单链表是否有环，如果有环，返回环的第一个节点
//快慢指针
LinkList* IsLoop(LinkList* list)
{
	if (list == NULL || list->next == NULL) return NULL;

	LinkList* p = list, * q = list;

	while (p != NULL && p->next != NULL)
	{
		p = p->next->next;
		q = q->next;

		if (p = q)
		{
			break;
		}
	}

	if (p != q) return NULL;

	while (p != q)
	{
		p = p->next;
		q = q->next;
	}

	return p;
}

// 5、合并两个有序单链表，合并后依旧有序
void MegerLinkList(LinkList* list1, LinkList* list2)
{
	if (list1 == NULL || list2 == NULL) return;
	
	LinkList* p = list1->next;
	LinkList* q = list2->next;
	LinkList* tail = list1;
	list2->next = NULL;

	while (p != NULL && q != NULL)
	{
		if (p->data < q->data)
		{
			tail->next = p;
			p = p->next;
		}
		else
		{
			tail->next = q;
			q = q->next;			
		}
		tail = tail->next;
	}

	if (p != NULL)
		tail->next = p;
	if (q != NULL)
		tail->next = q;
}

//6、逆置链表
void ReverseLinkList(LinkList* list)
{
	if (list == NULL || list->next) return;

	LinkList* p = list->next;
	LinkList* q = p->next;

	list->next = NULL;
	while (p != NULL)
	{
		p->next = list->next;
		list->next = p;
		p = q;

		if (q != NULL)
		{
			q = q->next;
		}
	}
}


