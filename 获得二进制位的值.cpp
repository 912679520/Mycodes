#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int GetBit(int n, int bit)
{
	if (bit < 1 || bit > 8) return -1;

	char* str = (char *)malloc(sizeof(char) * 32);
	int i = 0;
	while (n)//化为二进制
	{
		str[i++] = n % 2;
		n /= 2;
	}

	int len = strlen(str);//反转
	int j = 0;
	for (; j < len; j++)
	{
		int tmp = str[len - 1];
		str[len - 1] = str[j];
		str[j] = tmp;
	}
	str[j++] = '\0';

	int count = 0;
	count = (int)(str[bit-1])*pow(2, bit-1);

	return count;
}

