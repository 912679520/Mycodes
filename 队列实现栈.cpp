#include<iostream>
#include<queue>
using namespace std;

class TwoQueueStack
{
private:
	queue<int> que;
	queue<int> help;
public:
	void push(int pushInt)
	{
		que.push(pushInt);
	}
	int peek()
	{
		if (que.empty())
		{
			cout << "Stack is Empty" << endl;
		}
		while (que.size() != 1)
		{
			help.push(que.front());
			que.pop();
		}
		int res = que.front();
		help.push(res);
		swap();
		return res;
	}
	void pop()
	{
		if (que.empty())
		{
			cout << "The Stack is empty" << endl;
		}
		while (que.size() > 1)
		{
			help.push(que.front());
			que.pop();
		}
		int res = que.front();
		que.pop();
		swap();
	}
	void swap()
	{
		queue<int> tmp = help;
		help = que;
		que = tmp;
	}
	
};

//int main()
//{
//	TwoQueueStack stack1;
//	stack1.push(3);
//	cout << stack1.peek() << endl;
//	stack1.push(2);
//	cout << stack1.peek() << endl;
//	stack1.push(1);
//	cout << stack1.peek() << endl;
//
//	stack1.pop();
//	cout << stack1.peek() << endl;
//	stack1.pop();
//	cout << stack1.peek() << endl;
//	return 0;
//}