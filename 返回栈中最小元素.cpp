#include<iostream>
#include<stack>
using namespace std;

class MyStack
{
public:
	stack<int> StackMin;
	stack<int> StackData;
public:
	MyStack()
	{
		
	}
	void push(int data)
	{
		StackData.push(data);
		if (StackMin.empty())
		{
			StackMin.push(data);
		}
		else if (data < getMin())
		{
			StackMin.push(data);
		}
		else
		{
			int newMin = StackMin.top();
			StackMin.push(newMin);
		}
	}
	int top()
	{
		return StackData.top();
	}
	void pop()
	{
		if (StackData.empty())
		{
			return;
		}
		StackMin.pop();
		StackData.pop();
	}
	int getMin()
	{
		if (StackMin.empty())
		{
			return NULL;
		}
		return  StackMin.top();
	}
};

//int main()
//{
//	MyStack stack1;
//	stack1.push(3);
//	cout << stack1.getMin() << endl;
//	stack1.push(4);
//	cout << stack1.getMin() << endl;
//	stack1.push(1);
//	cout << stack1.getMin() << endl;
//	stack1.push(6);
//	cout << stack1.getMin() << endl;
//	return 0;
//}