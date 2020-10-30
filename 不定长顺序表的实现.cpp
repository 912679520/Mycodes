#include<stdio.h>
#include"Sqlist.h"
#include<malloc.h>
#include<string.h>
#include<stdlib.h>

//��C���� ����һ��static ����ʱ���˺���ֻ�ܱ���ǰ�ļ��е�������������
static int AppendSpace(SqList* sq)
{
	ElemType *s = (ElemType* )malloc(sizeof(ElemType) * sq->size * 2);
	if(s == NULL) return -1;

	//��ԭʼ�ռ������ȫ�����뵽�µĿռ���
	for(int i = 0; i < sq->size; ++i)
	{
		s[i] = sq->data[i];
	}

	//��ԭ���Ŀռ��ͷţ�Ȼ����sq->dataָ���µĿռ�s
	free(sq->data);
	sq->data = s;
	
	//����¼�ռ��С��size�ı�
	sq->size *= 2;

	return 0;
}

void InitSqlist(SqList* sq)
{
	if (sq == NULL) exit(0);

	sq->data = (ElemType*)malloc(sizeof(ElemType) * INITSIZE);
	if(sq->data == NULL) exit(0);

	sq->length = 0;
	sq->size =INITSIZE;

}

void InsertSqListPos(SqList *sq, ElemType val, int pos)
{
	if (sq == NULL) exit(0);
	if(pos < 0 || pos > sq->length) 
	{
		printf("INsert::Pos is Error\n");
		return;
	}

	if (sq->length == sq->size)
	{
		if(-1 == AppendSpace(sq))
		{
			printf("Insert:: AppendSpace fail\n");
			return;
		}
	}

	for(int i = sq->length; i > pos; i--)
	{
		sq->data[i] = sq->data[i - 1];
	}

	//��valֵ�洢����pos��Ϊ�±��λ��
	sq->data[pos] = val;
	sq->length++;
}

void SqListShow(SqList* sq)
{
	if (sq == NULL) return;

	for (int i = 0; i < sq->length; ++i)
	{
		printf("%d:%d\n",i, sq->data[i]);
	}
}

void SqListInsertHead(SqList* sq, ElemType val)
{
	InsertSqListPos(sq, val, 0);
}

void SqListInsertTail(SqList* sq,ElemType val)
{
	if (sq == NULL) exit(0);

	InsertSqListPos(sq, val, sq->length);
}

void SqListDeletepos(SqList* sq, int pos)
{
	if(sq == NULL) exit(0);
	if(pos < 0 || pos >= sq->length)
	{
		printf("Delete: pos is error\n");
		return;
	}

	//��posλ�ÿ�ʼ��������Ԫ����ǰŲ
	for(int i = pos; i < sq->length - 1; i++)
	{
		sq->data[i] = sq->data[i+1];
	}
	
	sq->length--;
}

void SqListDeleteHead(SqList* sq)
{
	SqListDeletepos(sq, 0);
}

void SqListDeleteTail(SqList* sq)
{
	if (sq == NULL) exit(0);
	if (sq->length == 0) return;

	sq->length--;
}

void SqListDeleteValue1(SqList* sq, ElemType val)//��ֵɾ
{
	if(sq == NULL) exit(0);

	for(int i = 0; i < sq->length;)
	{
		if(val == sq->data[i])
		{
			SqListDeletepos(sq, i);
		}
		else
			i++;
	}

}

void SqListDeleteValue2(SqList* sq, ElemType val)//��ֵɾ
{
	if (sq == NULL) exit(0);

	int count = 0;

	for(int i = 0; i + count < sq -> length;)
	{
		if(val == sq->data[i])
		{
			count++;
		}
		else
		{
			i++;
		}

		sq->data[i] = sq->data[i + count];
	}
	sq->length = count;
}

int FindValueLast(SqList* sq,ElemType val)
{
	if (sq == NULL) exit(0);

	int index = -1;

	for(int i = 0; i < sq->length; ++i)
	{
		if(sq->data[i] == val)
			index  = i;
	}

	return index;
}

void DestorySqList(SqList *sq)
{
	if (sq == NULL) exit(0);

	free(sq->data);
	sq->data = NULL;//��ֹ����Ұָ��
	sq->length = 0;
}