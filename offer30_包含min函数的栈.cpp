
#include<iostream>
#include<stack>

using namespace std;


class MinStack 
{
    stack<int> DataStack;
    stack<int> helpStack;
public:
    MinStack() {
        
    }

    void push(int x) {
        DataStack.push(x);

        if (helpStack.size() == 0 || x <= helpStack.top())
            helpStack.push(x);

        if (x > helpStack.top()) 
            helpStack.push(helpStack.top());
        
    }

    void pop() {
        DataStack.pop();
        helpStack.pop();
    }

    int top() {
       return DataStack.top();
    }

    int min() {
       return helpStack.top();
    }
};

int main()
{
    MinStack  minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);

    cout << minStack.min() << endl;
    minStack.pop();
    cout << minStack.top() << endl; 
    cout << minStack.min() << endl;

    return 0;
}