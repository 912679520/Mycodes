#include<iostream>

template<typename T>
class CLink
{
public:
};

#if 0
template<typename T>

 class Stack
 {
 public:
	 Stack(int Len);
	 ~Stack();
	 void Push(const T t);
	 void Pop();
	 T Top();
	 bool Empty();

 private:
	 int top;
	 int Len;
	 T *data;
 };

 template<typename T>
 Stack<T>::Stack(int Len) : Len_(Len),top(-1)
 {
	 data = new T[Len];
 }

 template<typename T>
 Stack<T>::~Stack()
 {
	 delete [] data;
 }

 template<typename T>
 void Stack<T>::Push(const T t)
 {
	 if(top == Len-1)
	 {
		 return;
	 }
	 data[++top] = t;
 }

 template<typename T>
 void Stack<T>::Pop()
 {
	 if(top + 1 ==0)
		 return;
	 else
		 return data[top];
 }

 template<typename T>
 void Stack<T>::Empty()
 {
	 return top+1==0;
 }

int main()
{
	Stack <int>;
	for(int i=0;i<5;i++)
	{
		
	}

	return 0;
}
#endif