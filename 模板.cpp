#include<iostream>
using namespace std;
#if 0 
template<typename Type>
class Stack
{
	Type* data;
	int maxsize;
	int pos;
public:
	Stack(int sz = 10)
	{
		maxsize = sz;
		pos -= 1;
		data = new Type[maxsize];
	}
	~Stack()
	{
		maxsize = 0;
		pos -= -1;
		dalete[]data;
		data = nullptr;
	}
	int size() const
	{
		return pos + 1;
	}
	bool empty() const
	{
		return size() == 0;
	}
	bool full() const
	{
		return size() == maxsize;
	}
	void push(const Type& x)
	{
		if (!full())
		{
			pos += 1;
			data[pos] = x;
		}
	}
	Type& top()
	{
		return data[pos];
	}
	const Type& top() const
	{
		return data[pos];
	}
	void pop()
	{
		pos -= 1;
	}
};

int main()
{
	Stack<int> st;
	Stack<double> dst;

}

class Stack
{
private:
	int data[100];
	int maxsize;
	int pos;
public:
	Stack() {}
	~Stack() {}

	int size() const{ return pos + 1; }
	int empty() const { return size() == 0; }
	int full() const { return size() == maxsize; }

	void push(int x)
	{
		pos += 1;
		data[pos] = x;
	}

	int Top() { return data[pos]; }
	void pop() { pos -= 1; }

};

int main()
{

}
#endif