#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//��һ��������A-Z��26����ĸ��ɣ�
//��ӡ������ϵ������Ӽ���ÿ���Ӽ�һ�У�
//�ô���ʵ�֣�����ʹ�õݹ�

int main()
{
	int num = 26;
	char str[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	for (int i = 0;i < (i << num);i++)
	{
		for (int j = 0;j < num;j++)
		{
			if ((i & (1 << j)) != 0)
			{
				printf("%c", str[j]);
			}
		}
		printf("\n");
	}
}