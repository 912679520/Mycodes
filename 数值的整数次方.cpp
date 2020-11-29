#include<stdio.h>

double MyPow(double x, int y)
{
	int res = 1;
	int n;

	if (y < 0)
	{
		n = -y;
	}

	else if (y > 0) n = y;

	else if (y == 0) return 1;

	while (n!=0)
	{
		if (n & 1 == 1)
		{
			res = res * x;
		}
		x = x * x;
		n >>= 1;
		
	}
	return (y > 0) ? res : (double(1) / res);
}

int main()
{
	printf("%.3lf\n", MyPow(10.0,0));
	return 0;
}