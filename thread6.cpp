#include<iostream>
#include<memory>
#include<mutex>
#include<semaphore>
#include<thread>
#include<vector>
#include<typeinfo>
#include <queue>
#include<condition_variable>
#include<atomic>
using namespace std;
#if 0
template<class T>
class UnLockStack
{
private:
	struct StackNode
	{
		T data;
		StackNode* next;
	public:
		StackNode(const T& x) :data(x), next(nullptr) {}
	};
private:
	std::atomic<StackNode*> head;
	std::atomic<int> cursize;
public:
	UnLockStack() :head(nullptr) {}
	~UnLockStack() {}
	void Push(const T& val)
	{
		StackNode* s = new StackNode(val);
		do
		{
			s->next = head.load();
		} while (!head.compare_exchange_strong(s->next, s));
		cursize++;
	}
	void Pop(T& val)
	{
		StackNode* p = nullptr;
		do
		{
			p = head.load();
		} while (!head.compare_exchange_strong(p, p->next));
		if (p != nullptr)
		{
			val = p->data;
			delete p;
		}
	}
	bool Empty() const;
	bool Full() const;
	size_t Size() const;
	const T& Top() const;
	void Pop();
	void Clear();
};



std::mutex mtx;
std::condition_variable cv;
bool ready = false;
int a = 100;

void do_print_id(int id)
{
	std::unique_lock<std::mutex> locker(mtx);
	/*while (!ready)
	{
		cv.wait(locker);
	}*/
	cv.wait(locker, []() {return ready;});
	cout << "thread" << id << endl;
}

void go()
{
	std::unique_lock<mutex> locker(mtx);
	ready = true;
	cv.notify_all();
}

int main()
{
	std::thread threads[10];
	for (int i = 0; i < 10;++i)
	{
		threads[i] = std::thread(do_print_id, i);
	}
	go();
	for (auto& x : threads)
	{
		x.join();
	}
	return 0;
}


//¦Ë±í´ïÊ½
class CountEven
{
	int& count;
public:
	CountEven(int& c) :count(c) {}
	void operator() (int val) const
	{
		if (val % 2 == 0) ++count;
	}
};

void funa()
{
	std::vector<int> ar = { 1,2,3,4,5,6,7,8,9 };
	int x = 0;
	std::for_each(ar.begin(), ar.end(), CountEven(x));
	cout << x << endl;
}

void funb()
{
	std::vector<int> ar = { 1,2,3,4,5,6,7,8,9 };
	int x = 0;
	std::for_each(ar.begin(), ar.end(), [&x](int val)->void
		{
			if (val % 2 == 0) x += 1;
		});
	cout << x << endl;
}

typedef enum
{
	add = 0,
	sub,
	mul,
	divi
}type;

int main()
{
	int a = 10;
	int b = 100;

	auto func = [=](type i)->int
	{
		switch (i)
		{
		case add:
			return a + b;
		case sub:
			return a - b;
		case mul:
			return a * b;
		case divi:
			return a / b;
		}
	};

	cout << func(sub) << endl;
}


typedef enum
{
	add = 0,
	sub,
	mul,
	divi
}type;

class Calc
{
private:
	int m_x;
	int m_y;
public:
	Calc(int x, int y) :m_x(x), m_y(y) {}

	int operator()(type i)
	{
		switch(i)
		{
		case add:
			return m_x + m_y;
		case sub:
			return m_x - m_y;
		case mul:
			return m_x * m_y;
		case divi:
			return m_x / m_y;
		}
	}
};

int main()
{
	Calc addObj(10, 20);
	cout << addObj(add) << endl;

	return 0;
}
#endif