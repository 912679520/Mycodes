#include<iostream>
using namespace std;

class ArrayStack
{
private:
	int* arr;
	int size;
public:
	ArrayStack(int initSize)
	{
		if (initSize < 0)
		{
			cout << "The init size is less than 0" << endl;
		}
		arr = new int[initSize];
		size = 0;
	}
	int peek() // 获取栈顶值
	{
		if (size == 0)
		{
			return NULL;
		}
		return arr[size - 1];
	}
	void push(int obj) // 压栈
	{
		if (size == sizeof(arr) / sizeof(arr[0]))
		{
			cout<< "The stack is full"<<endl;
		}
		arr[size++] = obj;
	}
	int pop()//出栈
	{
		if (size == 0)
		{
			cout<< "The stack is empty"<<endl;
		}
		return arr[--size];
	}
};

class ArrayQueue
{
private:
	int* arr;
	int size;
	int first;
	int last;
public:
	ArrayQueue(int initsize)
	{
		if (initsize < 0)
		{
			cout << " The init size is less than 0" << endl;
		}
		arr = new int[initsize];
	}
	int peek()
	{
		if (size == 0)
		{
			return NULL;
		}
		return arr[first];
	}
	void push(int obj)
	{
		if (size == sizeof(arr) / sizeof(arr[0]))
		{
			cout << "The queue is full" << endl;
		}
		size++;
		arr[last++] = obj;
		last = last == sizeof(arr) / sizeof(arr[0]) - 1 ? 0 : last + 1;
	}
	int poll()
	{
		if (size == 0)
		{
			cout << "The queue is empty" << endl;
		}
		size--;
		int tmp = first;
		first = first == sizeof(arr) / sizeof(arr[0]) - 1 ? 0 : first + 1;
		return arr[tmp];
	}

};

//int main()
//{
//	ArrayQueue que(3);
//	que.push(1);
//	que.push(2);
//	que.push(3);
//	
//	int pol = que.poll();
//	que.poll();
//
//	cout << "poll :" << pol << endl;
//
//	int pee = que.peek();
//	cout << "peek : " << pee << endl;
//
//	return 0;
//}