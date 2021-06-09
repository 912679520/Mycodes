#include<iostream>

using namespace std;

/*
贪心：尽可能多的剪3，当剩下绳子为4时，不剪3，剪2
*/

class Solution
{
public:
	int cuttingRope(int n)
	{
		if (n < 2) return 0;
		if (n == 2) return 1;
		if (n == 3) return 2;

		int cur3 = n / 3;

		//当剩下绳子是4时
		if (n - cur3 * 3 == 1) cur3 -= 1;

		int cur2 = (n - cur3 * 3) / 2;

		return (pow(3, cur3)) * (pow(2, cur2));
	}
	int cuttingRope1(int n)
	{
		if (n == 1 || n == 2) return 1;
		if (n == 3) return 2;

		long sum = 1;
		while (n > 4)
		{
			sum = sum * 3;
			sum = sum % 1000000007;
			n -= 3;
		}
		
		return (int)(sum * n % 1000000007);
	}
};

int main()
{
	Solution s;
	int num = s.cuttingRope1(120);
	cout << num << endl;

	return 0;
}