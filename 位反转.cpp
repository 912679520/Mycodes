#include<stdio.h>

unsigned int Reverse_bits(unsigned int n)
{
	unsigned long long int m = 0;
	for (int i = 0; i < 32; i++)
	{
		if (((n >> i)&1) != 0)
		{
			m |= 1 << (31 - i);
		}
	}

	return m;
}


