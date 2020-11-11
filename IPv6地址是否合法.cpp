
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define IPV6_MAX 39

bool Ipv6(char* s)
{
	char split[8][IPV6_MAX];
	char buf[IPV6_MAX + 2];
	int len = 0;

	if (strlen(s) > IPV6_MAX) return false;
	if (sscanf(s, "%[0-9a-fA-F]:%[0-9a-fA-F]:%[0-9a-fA-F]:%[0-9a-fA-F]:%[0-9a-fA-F]:%[0-9a-fA-F]:%[0-9a-fA-F]:%[0-9a-fA-F]", split[0], split[1], split[2], split[3], split[4], split[5], split[6], split[7]) != 8)
		return false;

	for (int i = 0;i < 8;i++)
	{
		if (strlen(split[i]) > 4) return false;
		len += sprintf(buf + len, "%s:", split[i]);
	}

	buf[len - 1] = 0;
	if (strcmp(buf, s) != 0) return false;

	return true;
}
