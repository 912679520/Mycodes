#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

char* String(char* str)
{
	int len = strlen(str);
	if (len <= 2) return str;

	char* Newstr = (char*)malloc(sizeof(char) * (2 * len));
	Newstr[0] = str[0];

	int count = 1, index = 1;

	for (int i = 1; i < len + 1; i++)
	{
		if (str[i] == str[i - 1])
		{
			count++;
		}
		else
		{
			int num = (int)log10(count) + index;
			index = num;

			while (count)
			{
				Newstr[num--] = count % 10 + '0';
				count /= 10;
			}

			Newstr[++index] = str[i];
			count = 1;
			++index;
		}
	}
	
	if (index >= len + 1) return str;

	return Newstr;
}



/*
char *Str(char* str1)
{
	char* Newstr = (char*)malloc(sizeof(char) * (2*strlen(str1)));

	int count = 0;
	int i = 0;
	char* l = str1;
	char* r = str1 + 1;

	if (strlen(str1) <= 2) 	return str1;

	while (*l != '\0')
	{
		while (*r != '\0' && *l == *r)
		{
			r++;		
		}

		Newstr[i] = *l;
		count = r - l;
		Newstr[i++] = count + '0';
		
		i = i + 2;
		l = r;
	}
	Newstr[i] = '\0';

	if (strlen(Newstr) > strlen(str1)) 
		return str1;

	return Newstr;
}
*/

