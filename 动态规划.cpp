#include<iostream>
using namespace std;

int Fib(int n)//1 1 2 3 5 8 13 21 
{
	int f[1000]={0};
	if(n==1 || n==2)
		f[n]=1;
	else
	{
		if(f[n]==0)
		{
			f[n]=Fib(n-1)+Fib(n-2);
		}
	}
	return f[n];
}



int main()
{
	cout<<Fib(7)<<endl;
	cout<<Fib(9)<<endl;
	cout<<Fib(1)<<endl;
	cout<<Fib(5)<<endl;
	cout<<Fib(3)<<endl;
	cout<<Fib(11)<<endl;
	return 0;
} 
