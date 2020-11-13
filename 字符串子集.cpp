#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//有一个集合由A-Z这26个字母组成，
//打印这个集合的所有子集，每个子集一行，
//用代码实现，不能使用递归

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