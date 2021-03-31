#include<iostream>
#include<vector>
#include<assert.h>
#include<queue>
using namespace std;

//分治与递归

//快排
int Parition(int* ar, int left, int right)
{
	//assert(ar != nullptr);
	int tmp = ar[left];
	while(left < right)
	{
		while (left < right && ar[right] > tmp) --right;
		ar[left] = ar[right];

		while (left < right && ar[left] <= tmp) ++left;
		ar[right] = ar[left];
	}
	ar[left] = tmp;
	return left;
}

void QuickPass(int* ar, int left, int right)
{
	if (left < right)
	{
		int pos = Parition(ar, left, right);
		QuickPass(ar, left, pos - 1);
		QuickPass(ar, left + 1, right);
	}
}

void NiceQuickPass(int* ar, int left, int right)
{
	std::queue<int> qu;
	qu.push(left);
	qu.push(right);
	while (!qu.empty())
	{
		left = qu.front();
		qu.pop();
		right = qu.front();
		qu.pop();
		int pos = Parition(ar, left, right);
		if (left < pos - 1)
		{
			qu.push(left);
			qu.push(pos - 1);
		}
		if (pos + 1 < right)
		{
			qu.push(pos + 1);
			qu.push(right);
		}
	}
}

void QuickSort(int* ar, int n)
{
	NiceQuickPass(ar, 0, n - 1);
}

int main()
{
	int ar[] = { 56,12,89,90,23,34,100,56,45,56 };
	int n = sizeof(ar) / sizeof(ar[0]);
	for (auto& x : ar)
	{
		cout << x << " ";
	}
	cout << endl;
	QuickSort(ar, n);
	for (auto& x : ar) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}

#if 0
int fib(int left, int mid, int right)
{

}

int BFind(const vector<int>& ar, int val)
{
	int left = 0;
	int right = ar.size() - 1;
	int mid = (left + right) / 2;
	return fib(left,right,mid);
}


int BinFind(const vector<int>& ar, int val)
{
	int left = 0, right = ar.size() - 1;
	while (left <= right)
	{
		int mid = (right - left) / 2;
		if (ar[mid] == val) return ar[mid];
		else if (ar[mid] > val)
		{
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
	throw;
}


int main()
{
	std::vector<int> ar = { 12,23,34,45,56,67,78,89,90,100 };
	try
	{
		cout<< BinFind(ar, 12) << endl;
	}
	catch (exception& e)
	{
		cout << "no err" << endl;
	}
	

	return 0;
}



//斐波那契
int fun(int n)
{
	int a = 1, b = 1, c = 0;
	for (int i = 3;i <= n;++i)
	{
		c = a + b;
		b = a;
		a = c;
	}
	return c;
}//O(n)  S(1)

int fib(int n,int a,int b)
{
	if (n <= 2) return a;
	else
		return fib(n - 1, a + b, a);
}

int fib(int n)
{
	int a = 1, b = 1;
	return fib(n, a, b);
}

int main()
{
	cout<< fun(6) <<endl;

	return 0;
}


int fib(int n)
{
	if (n <= 2)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}//O(2^n)  S(n)



int fun(int n)
{
	int sum = 1;
	for (int i = 1;i <= n;++i)
	{
		sum = sum * i;
	}
	return sum;
}
int fac(int n)
{
	if (n <= 1) return 1;
	else
		return fac(n - 1) * n;
}//O(n) S(n)

int main()
{
	cout<< fac(12) << endl;

	return 0;
}


#endif
