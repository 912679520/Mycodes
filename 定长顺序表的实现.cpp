
#include"fixedsqlist.h"


void FixedSqListInit(FixedSqList* sq)
{
	/*
		1����sqָ���data����洢Ԫ�صĿռ�
		2����sqָ���length����Ϊ0
	*/
	if (sq == NULL)
	{
		exit(0);
	}

	sq->data = (ElemType*)malloc(sizeof(ElemType)* INITSIZE);
	sq->length = 0;
	if (sq->data == NULL)
	{
		exit(0);
	}

	sq->length = 0;
}

void FixedSqListInsert(FixedSqList *sq, ElemType val, int pos)
{
	if (sq == NULL) exit(0);
	
	//�ж�˳����Ƿ�洢��
	if (sq->length == INITSIZE)
	{
		printf("SqList is Full\n");
		return;
	}

	//��posֵ�Ϸ��Ե��ж�
	if (pos < 0 || pos > sq->length)
	{
		printf("����λ�ò��Ϸ�\n");
		return;
	}

	//��posλ��֮�󣨰���posλ�ã����Ų
	for(int i = sq->length; i > pos; i--)
	{
		sq->data[i] = sq->data[i - 1];
	}

	//��valֵ�洢����pos��Ϊ�±��λ��
	sq->data[pos] = val;
	sq->length++;
}

void FixedSqListShow(FixedSqList* sq)
{
	if (sq == NULL) return;

	for (int i = 0; i < sq->length; ++i)
	{
		printf("%d:%d\n",i, sq->data[i]);
	}
}

void FixedSqListInsertHead(FixedSqList* sq, ElemType val)
{
	FixedSqListInsert(sq, val, 0);
}

void FixedSqListInsertTail(FixedSqList* sq,ElemType val)
{
	if (sq == NULL) exit(0);

	FixedSqListInsert(sq, val, sq->length);
}

void FixedSqListDeletepos(FixedSqList* sq, int pos)
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

void FixedSqListDeleteHead(FixedSqList* sq)
{
	FixedSqListDeletepos(sq, 0);
}

void FixedSqListDeleteTail(FixedSqList* sq)
{
	if (sq == NULL) exit(0);
	if (sq->length == 0) return;

	sq->length--;
}

void FixedSqListDeleteValue1(FixedSqList* sq, ElemType val)//��ֵɾ
{
	if(sq == NULL) exit(0);

	for(int i = 0; i < sq->length;)
	{
		if(val == sq->data[i])
		{
			FixedSqListDeletepos(sq, i);
		}
		else
			i++;
	}

}

void FixedSqListDeleteValue2(FixedSqList* sq, ElemType val)//��ֵɾ
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

int FindValueLast(FixedSqList* sq,ElemType val)
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

void DestoryFixedSqList(FixedSqList *sq)
{
	if (sq == NULL) exit(0);

	free(sq->data);
	sq->data = NULL;//��ֹ����Ұָ��
	sq->length = 0;
}
