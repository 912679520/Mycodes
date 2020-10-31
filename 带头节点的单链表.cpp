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

	//1���ҵ�Posλ�õ�ǰһ���ڵ� 2�����posλ�ó���Length��posΪ��
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

	LinkList *p = list->next;//pָ���һ�����ݽ��

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

	 LinkList *q = p->next;//ʹ��q��Ҫɾ���Ľڵ��¼
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

//Ҫ��ʱ�临�Ӷ�ΪO(n), �ܹ�ɾ���ظ���Ԫ��
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

//1��ɾ����β�ڵ�
bool DeleteNodeFromP(LinkList* list, LinkList* p)//������ϰ��
{
	if (list == NULL || p == NULL) return false;

	//���p��β�ڵ㣬ֱ�ӵ���βɾ
	if (p->next == NULL) 
	{
		DeleteLinkListTail(list);
		return true;
	}

	LinkList* q = p->next;//q�ǽ�������ɾ���Ľ��
	p->data = q->data;
	p->next = q->next;

	free(q);
	return true;
}

//2���ҵ�����k�����
LinkList* FindNodeOfK(LinkList* list, int k)
{
	/*
		����1�����󳤶ȣ�Ȼ���ǰ�����������length - k + 1
		����2��˫ָ�룬����һ��ָ����k�Σ�Ȼ������ָ��һ������ߣ�
		ֱ�����ߵ�ָ���ߵ���
	*/

	//����2
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

//3���ж������������Ƿ��ཻ������ཻ�����ཻ�ĵ�һ���ڵ�
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

//4���жϵ������Ƿ��л�������л������ػ��ĵ�һ���ڵ�
//����ָ��
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

// 5���ϲ��������������ϲ�����������
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

//6����������
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


