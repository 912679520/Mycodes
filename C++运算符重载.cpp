
#include<iostream>
using namespace std;

#if 0
class Add_Int
{
private:
	int value;
public:
	Add_Int(int x = 0) : value(x) {}
	~Add_Int() {}
public:
	int operator() (int x, int y)
	{
		value = x + y;
		return value;
	}
};

int main()
{
	Add_Int add;

	int x = add(10, 20);
	int y = add.operator()(10, 20);

}


class Int
{
private:
	int value;
public:
	Int(int x = 0) : value(x) {}
	~Int() {}
	int& Value() { return value; }
	const int& Value() const { return value; }
};

class Object 
{
	int num;
	Int* pInt;
public:
	Object (int x = 0) : num(x), pInt (new Int(x + 10)){}
	~Object()
	{
		if (pInt != nullptr)
		{
			delete pInt;
		}
		pInt = nullptr;
	}
	/*
	int GetNum() { return num; }

	Int GetInt() { return *pInt; }

	Int* GetPInt() { return pInt; }*/

	Int& operator*() { return *pInt; }
	const Int& operator*() const { return *pInt; }

	Int* operator->() 
	{
		return pInt;
		return &**this;
	}
};

int main()
{
	Object obj(10);
	Int a = *obj;
	int x = (*obj).Value();
	(*obj).Value() = 100;

	return 0;
}

int main()
{
	Object obj(10);

	Int* p = obj.GetPInt();

	Int x = obj.GetInt();

	Int x = obj.GetInt();
	int a = obj.GetInt().Value();
	obj.GetInt().Value() = 100;

	return 0;
}

class Int
{
private:
	int value;
public:
	Int(int x = 0) : value(x) {}
	~Int() {}
	Int(const Int& it) : value(it.value) {}

	Int operator+ (const Int& x) const //c = a + b
	{
		return Int(this->value + x.value);
		//c = a+b,;  //c = a.operator + (b)   //c =operator + (&a,b); 
	}

	Int operator+(const int num) const //c = a + x
	{
		return Int(this->value + num);	
	}
};

Int operator+(const int x, const Int& y) // x + a
{
	return y + x;
}
int main()
{
	Int a(10), b(20), c;

	int x = 30;
	c = a + b;

	c = a + x;

	c = x + a;
}

class Complex
{
private:
	double Real, Image;
public:
	Complex(double r = 0.0, double i = 0.0) : Real(r), Image(i)
	{
		//构造函数
	}
	~Complex()
	{
		//析构函数
	}

	Complex(const Complex& com)
		:Real(com.Real), Image(com.Image)
	{
		//拷贝构造函数
	}

	//第一种方法
	/*
	Complex Add(Complex c)
	{
		Complex tmp(Real + c.Real, Image + c.Image);
		return tmp;
	}

	
	//第二种方法
	Complex Add(const Complex &c)
	{
		Complex tmp(Real + c.Real, Image + c.Image);
		return tmp;
	}
	*/
	//第三种方法
	Complex operator+(const Complex &c) const
	{
		Complex tmp(Real + c.Real, Image + c.Image);
		return tmp;
	}
	
};

int main()
{
	Complex c1(12, 23);
	Complex c2(45, 56);
	Complex c3;

	//c3 = c1.Add(c2);
	c3 = c1+c2;
	return 0;
}
#endif