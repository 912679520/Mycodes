#include<string>
#include<iostream>
using namespace std;

//智能指针
/*
裸指针的问题：int *p
1、难以区分指向的单个对象还是一个数组
2、使用完指针之后无法判断是否应该销毁指针，因为无法
判断指针是否拥有指向的对象
3、在已经确定需要销毁指针的情况下，也无法确定是用delete
关键字删除，还是有其它特殊的销毁机制，例如通过指针传入
某个特定的销毁函数来销毁指针
4、即便已经确定了销毁指针的方法，由于原因1，仍然无法确定
到底是用delete还是delete[]
5、假设上述问题都解决，也很难保证在代码的所有路径中，
有且仅有一次销毁指针操作；条件路径遗漏都可能造成
内存泄漏，而销毁多次会导致未定义行为
6、理论上没有方法分辨一个指针是否处于悬挂状态
*/

class Object
{
private:
	int value;
public:
	Object(int x = 0) :value(x) { cout << "构造 obj" << endl; }
	~Object() { cout << "析构 obj" << endl; }
	int& Value() { return value; }
	const int& Value() const { return value; }
};

int fun()
{
	std::auto_ptr<Object> op(new Object(10));

	return 0;
}

int main()
{
	fun();

	return 0;
}

#if 0
template <class T>
class C
{
public:
	void fun() { cout << "C T" << endl; }
};

int main()
{
	C<int> ic;
	C<int*> pic;
	C<double> dc;

	return 0;
}


//模板
template<class T, unsigned int SIZE>
class Stack
{
	T data[SIZE];
public:
};

int main()
{
	Stack<int, 10> is;
	Stack<double, 100> ds;
}



//模板类型参数
template <class T> // 等价 tempalte <typename T>
class Stack
{
	T* data;
public:
	Stack() :data(nullptr) {}
	void push(const T& a);
};

int main()
{
	Stack<int> is;
	Stack<double> ds;
}


class Object
{
private:
	int value;
public:
	Object(int x = 0) :value(x) {}
	virtual ~Object() {}
	virtual void add(int x) {}
	virtual void fun() = 0;
};


const double PI = 3.14;

class Shapes
{
private:
	string sname;
protected:
	Shapes(const string& sn) :sname(sn) {}
public:
	virtual ~Shapes() {}

public:
	virtual void disp() const = 0;
	const string& ShapesName() const { return sname; }
};

class Square :public Shapes
{
private:
	float length;
public:
	Square(const string& sn, float a) :Shapes(sn),length(a) {}
	~Square() {}
	void disp() const
	{
		cout << "矩形面积：" << length * length << endl;
	}
};

class Circle :public Shapes
{
private:
	float radius;
public:
	Circle(const string& sn, float r) :Shapes(sn), radius(r) {}
	~Circle() {}
	void disp() const
	{
		cout << "圆的面积：" << PI * radius * radius << endl;
	}
};

void fun(Shapes& sp)
{
	cout << sp.ShapesName() << endl;
	sp.disp();
}

int main()
{
	Square s("正方形", 10);
	Circle c("圆形",5);
	fun(s);
	fun(c);
	return 0;
}

//抽象类
class Object //纯虚函数导致其为抽象类
{
private:
	int value;
public:
	Object(int x = 0) :value(x) {}
	~Object() {}
	virtual void fun() = 0;//纯虚函数
};

int main()
{
	//Object obj(x);

	return 0;
}
#endif