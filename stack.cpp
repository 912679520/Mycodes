#include "stack.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>

static int AppendSpace(Stack* st)
{
	ElemType* s = (ElemType*)malloc(sizeof(ElemType) * st->size * 2);
	if (s == NULL) return 0;

	//将原来数据挪到s空间上
	for (int i = 0; i < st->top;i++)
	{
		s[i] = st->data[i];
	}

	free(st->data);
	st->data = s;
	st->size *= 2;
	return 1;
}

void InitStack(Stack* st)
{
	if (st == NULL) exit(0);

	st->data = (ElemType*)malloc(sizeof(ElemType) * INITSIZE);
	if (st->data == NULL) exit(0);

	st->top = 0;
	st->size = INITSIZE;

}

void Push(Stack* st, ElemType val)//入栈
{
	if (st == NULL) exit(0);

	if (st->size == st->top)
	{
		if (!AppendSpace(st))
		{
			return;
		}
	}

	st->data[st->top++] = val;
}

int Empty(Stack* st)//判空
{
	if (st == NULL) exit(0);

	return st->top == 0 ? 1 : 0;
}

int Top(Stack* st, ElemType* result)//取栈顶元素
{
	if (st == NULL) exit(0);

	if (Empty(st))
	{
		return 0;
	}

	*result = st->data[st->top - 1];
	return 1;
}

void Pop(Stack* st)
{
	if (st == NULL) exit(0);

	if (Empty(st)) return;

	st->top--;
}

void Destroy(Stack* st)
{
	if (st == NULL) exit(0);

	free(st->data);
	st->data = NULL;
	st->top = st->size = 0;
}

