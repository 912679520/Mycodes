#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//替换字符串中的？
char *Replace(char* s)
{
	for(int i = 0; i < strlen(s); i++)
	{
		if (s[i] == '?')
		{
			//替换
			char tmp = 'a';	
			if (i > 0)
			{
				while (s[i-1] == tmp || s[i+1] == tmp) tmp++;			
			}
			s[i] = tmp;
		}
	}
	return s;
}

//括号的最大嵌套深度
int DepthVps(char* s)
{
	int Depth = 0,relse = 0;
	for (int i = 0;s[i] != '\0';i++)
	{
		if (s[i] == '(')
			Depth += 1;
		if (s[i] == ')')
		{
			relse = Depth > relse ? Depth : relse;
			Depth -= 1;
		}
	}
	return relse;
}

//把字符串转换成整数
int StrToInt(char* s)
{
	if (s == NULL) return 0;
	long long num = 0;

	int Fh = 0;
	while (*s != '\0')
	{
		if (*s == ' ') s++;
		if (*s == '+') s++;
		if (*s == '-')
		{
			Fh = 1;
			s++;
		}
		num = num * 10 + (*s - '0');
		s++;

		if (Fh == 0 && num > 231)
			return 231 - 1;
		if (Fh == 1 && num < -231)
			return -231;
	}

	return Fh == 0  ? (int)num : (int)-num;
}

//将整数数字转为字符串
char *MyItoa(int num,char *str)
{
	int Fh = 0,i=0;
	if (num < 0)
	{
		Fh = 1;
		num = -num;
		str[i++] = '-';
	}

	while (num != 0)
	{
		str[i++] = num % 10 + '0';
		num /= 10;
	}
	str[i] = '\0';

	int j = 0;
	if (Fh == 1) j++;

	for (--i;i > j; j++, i--)
	{
		char tmp = str[j];
		str[j] = str[i];
		str[i] = tmp;
	}
	return str;
}

//将整数转为指定进制的字符串
char *MyItoaPlus(int n, char* str, int redix)
{
	const char *arr = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	int i = 0,tmp = 0;

	while (n != 0)
	{
		tmp = n % redix;
		str[i++] = arr[tmp];
		n /= redix;
	}
	str[i] = '\0';

	int j = 0;
	for (--i;i > j; j++, i--)
	{
		char tmp = str[j];
		str[j] = str[i];
		str[i] = tmp;
	}
	return str;
}

int main()
{
	char str[10];
	MyItoaPlus(123, str,36);
	for (int i = 0; i < strlen(str); i++)
	{
		printf("%c",str[i]);
	}


	//char s[100] = " -259";
	//printf("%d \n",StrToInt(s));

	/*char s[100] = "()()((((()((()))))))";
	printf("%d\n",DepthVps(s));*/


	//char s[100] = "??bw?ipkj?";
	//Replace(s);
	//for (int i = 0;i < strlen(s);i++)
	//{
	//	printf("%c",s[i]);
	//}
	return 0;
}
