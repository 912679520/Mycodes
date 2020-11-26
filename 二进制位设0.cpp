#include<stdio.h>

bool Clear_bit(int& n, int bit)
{
	if (bit < 1 || bit > 8) return false;

	n &=  ~(1 << (bit - 1));

	return true;
}

