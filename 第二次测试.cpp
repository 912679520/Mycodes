#include<string.h>
#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>

//11、求平方根
int Mysqrt(int n)
{
	int i;
	for(i = 0; i * i <= n; i++);

	return i-1;
}

//12、统计十进制数字位数
int GetNum(int n)
{
	if (n == 0) return 1;

	int count = 0;
	while(n != 0)
	{
		n /= 10;
		count++;
	}

	return count;
}

//13、给一个正整数，把它转为16进制，它是个几位数字
int GetHex(int n)
{
	if (n == 0) return 1;

	int count = 0;
	while(n != 0)
	{
		n /= 16;
		count++;
	}
	return count;
}

//14、顺序输出数字的每一位
void Myprint(int n)
{
	if (n > 10)
	{
		Myprint(n / 10);
	}
	printf("%d ",n % 10);
}

//15、逆序输出数字的每一位
void ReverNum(int n)
{

	while(n != 0)
	{
		int tmp = n % 10;
		printf("%d ",tmp);
		n /= 10;	
	}
	printf("\n");
}

//16、IP地址无效化
char* IpInvalid(char *address)
{
	char *str =(char *)malloc((strlen(address)+7)*sizeof(char));
	int i,j;
	for(i = 0, j = 0; address[i] != '\0'; i++)
	{
		if(address[i] == '.')
		{
			str[j++] = '[';
			str[j++] = '.';
			str[j++] = ']';
		}
		else str[j++] = address[i];	
	}

	str[j] = '\0';
	return str;
}

//17、整数的各位积和之差
int GetPoor(int n)
{
	if (n < 0) exit(0);

	int take = 1;
	int sum = 0;

	while(n > 0)
	{
		take *= (n % 10);
		sum += (n % 10);
		n /= 10;
	}	
	return take - sum;
}

//18、1~n中1的次数
int GetOne(int n)
{
	int count = 0;
	for(int i = 1; i <= n; i++)
	{
		while(i != 0)
		{
			if (i % 10 == 1) 
				count++;
			n /= 10;
		}
	}
	return count;
}

//19、所有奇数长度子数组的和
int cmp(const void * a, const void *b)
{
	return *(int *)a - *(int *)b;
}
void Qsort(int *arr, int len)
{
	qsort(arr, len, sizeof(int), cmp);
}

int main()
{
	printf("%d \n",GetOne(12));
	return 0;
}
