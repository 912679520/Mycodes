#include<string.h>
#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>

//11����ƽ����
int Mysqrt(int n)
{
	int i;
	for(i = 0; i * i <= n; i++);

	return i-1;
}

//12��ͳ��ʮ��������λ��
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

//13����һ��������������תΪ16���ƣ����Ǹ���λ����
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

//14��˳��������ֵ�ÿһλ
void Myprint(int n)
{
	if (n > 10)
	{
		Myprint(n / 10);
	}
	printf("%d ",n % 10);
}

//15������������ֵ�ÿһλ
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

//16��IP��ַ��Ч��
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

//17�������ĸ�λ����֮��
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

//18��1~n��1�Ĵ���
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

//19��������������������ĺ�
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
