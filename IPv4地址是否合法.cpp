#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define IPV4_MAX 16

bool IPv4(char* str)
{
	if (str == NULL) exit(0);
	if (str[0] == '0' || str[0] == '.') return false;

	int split[4];
	char Newstr[IPV4_MAX + 2];
	int len = 0;
	if (strlen(str) > IPV4_MAX) return false;
	if (sscanf(str, "%d.%d.%d.%d", &split[0], &split[1], &split[2], &split[3]) != 4)
		return false;

	for (int i = 0;i < 4;i++)
	{
		if (split[i] < 0 || split[i] > 255) return false;
		len += sprintf(Newstr + len, "%d.", split[i]);
	}

	Newstr[len - 1] = 0;
	if (strcmp(Newstr, str) != 0) return false;

	return true;
}
