#include<stdio.h>
#include<string.h>
#include<stdlib.h>

bool Set_bit(int& n, int bit)
{
	if (bit < 1 || bit > 8) return false;

	n |= 1 << (bit - 1);

	return true;
}
