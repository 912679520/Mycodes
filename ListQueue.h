#pragma once

typedef int ElemType;

typedef struct Node//������ṹ��
{
	ElemType data;
	struct Node* next;
}ListNode;

typedef struct Que//��ʽ���нṹ��
{
	ListNode* front;
	ListNode* rear;
}ListQue;

void InitListQue(ListQue *Que);

int Empty(ListQue* Que);

void Push(ListQue* Que, ElemType val);//���

void Pop(ListQue* Que);

int GetHead(ListQue* Que, ElemType *val);

void DestroyListQue(ListQue* Que);