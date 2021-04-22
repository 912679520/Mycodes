#include<iostream>
#include<stack>
using namespace std;

class TwoStackQueue
{
private:
	stack<int> stackPush;
	stack<int> stackPop;
public:
	void push(int pushInt)
	{
		stackPush.push(pushInt);
	}
	void poll()
	{
		if (stackPop.empty() && stackPush.empty())
		{
			cout << "The queue is empty" << endl;
			return;
		}
		else if (stackPop.empty())
		{
			while (!stackPush.empty())
			{
				stackPop.push(stackPush.top());
				stackPush.pop();
			}
		}
		stackPop.pop();
	}
	int peek()
	{
		if (stackPop.empty() && stackPush.empty())
		{
			cout << "The queue is empty" << endl;
			return NULL;
		}
		else if (stackPop.empty())
		{
			while (!stackPush.empty())
			{
				stackPop.push(stackPush.top());
				stackPush.pop();
			}
		}
		return stackPop.top();
	}

};

int main()
{
	TwoStackQueue que1;
	que1.push(1);
	que1.push(2);
	que1.push(3);
	cout << que1.peek() << endl;

	que1.poll();
	
	que1.poll();
	cout << que1.peek() << endl;
	return 0;
}