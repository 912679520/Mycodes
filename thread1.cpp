#include<iostream>
#include<thread>
using namespace std;

int g_max = 0;
const int n = 5;


#if 0
class Object
{
	int value;
public:
	Object(int x = 0) : value(x) {}
	Object(const Object& obj) :value(obj.value)
	{
		cout << "copy" << endl;
	}
	void fun()
	{
		cout << "fun" << endl;
		value++;
	}
	int GetValue() const { return value; }
};

int main()
{
	Object obj(10);
	cout << obj.GetValue() << endl;
	//std::thread t1(&Object::fun, &obj);
	std::thread t2(&Object::fun, obj);
	//t1.join();
	t2.join();
	cout << obj.GetValue() << endl;
	return 0;
}


struct Object
{
	void operator()()
	{
		cout << "operator()" << endl;
	}
	void operator()(int a)
	{
		cout << "operator(int a)" << endl;
	}
	void operator()(int a, int b) {}
};

int main()
{
	Object obj;
	std::thread t1(obj,10,20);
	t1.join();
	return 0;
}


class Object
{
	int value;
public:
	Object(int x = 0) :value(x) {}
	Object(const Object& obj) :value(obj.value)
	{
		cout << "copy creat" << endl;
	}
	~Object() {}
	virtual void fun(int a)
	{
		cout << "fun(int a)" << endl;
		value += 1;
	}
	void funa(int& a)
	{
		cout << "fun(int &a)" << endl;
		value += 1;
	}
	void funb(int* p)
	{
		if (p == nullptr) return;
		cout << "funb(int *p)" << endl;
		value += 1;
	}
	int GetValue()const { return value; }
	static void show() { cout << "show" << endl; }
};

int main()
{
	int a = 10;
	Object obj(10);
	cout << obj.GetValue() << endl;
	std::thread t1(&Object::fun, obj, a);
	std::thread t2(&Object::funa, obj, std::ref(a));
	std::thread t3(&Object::funb, obj, &a);
	std::thread t4(&Object::show);
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	cout << obj.GetValue() << endl;

	return 0;
}


void funa(int& a)
{
	for (int i = 0; i < n; ++i)
	{
		cout << "thread a:" << a++ << endl;
	}
}

int main()
{
	int x = 10, y = 20;
	std::thread t1(funa, std::ref(x));
	std::thread t2(funa, std::ref(x));
	t1.join();
	t2.join();
	//cout << x << " " << y << endl;
	return 0;

}


int g_max = 0;
const int n = 5;

void funa(int a, int* p)
{
	if (p == nullptr) return;
	for (int i = 0; i < n;++i)
	{
		cout << a++ << " " << (*p)++ << endl;
	}
	//cout << p << endl;
}

int main()
{
	int x = 10, y = 20;
	//cout << &y << endl;
	std::thread t1(funa, x, &y);
	std::thread t2(funa, x, &y);
	t1.join();
	t2.join();
	cout << x << " " << y << endl;
	return 0;

}


int g_max = 0;
const int n = 5;

void funa()
{
	int x = 0;
	for (int i = 0; i < 5;++i)
	{
		cout << "thread g_max : " << g_max++ << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
	}
}

int main()
{
	std::thread t1(funa);
	std::thread t2(funa);

	std::this_thread::sleep_for(std::chrono::seconds(2));
	t1.join();
	t2.join();
	return 0;
}


const int n = 5;
void funa()
{
	int x = 0;
	for (int i = 0; i < 5;++i)
	{
		cout << "thread x : " << x++ << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
	}
}

int main()
{
	std::thread t1(funa);
	std::thread t2(funa);

	std::this_thread::sleep_for(std::chrono::seconds(2));
	t1.join();
	t2.join();
	return 0;
}


const int n = 5;
void funa(int a)
{
	for (int i = 0; i < n;++i)
	{
		cout << "thread 1 \n"<< a << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
	}
}

int main()
{
	int x = 10;
	std::thread t1(funa, x);

	std::this_thread::sleep_for(std::chrono::seconds(1));
	t1.join();
	return 0;
}
#endif