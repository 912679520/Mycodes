#pragma once

typedef int ElemType;

typedef struct Node//单链表结构体
{
	ElemType data;
	struct Node* next;
}ListNode;

typedef struct Que//链式队列结构体
{
	ListNode* front;
	ListNode* rear;
}ListQue;

void InitListQue(ListQue *Que);

int Empty(ListQue* Que);

void Push(ListQue* Que, ElemType val);//入队

void Pop(ListQue* Que);

int GetHead(ListQue* Que, ElemType *val);

void DestroyListQue(ListQue* Que);