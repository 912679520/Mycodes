#include<stdio.h>
#include<iostream>
using namespace std;
#if 0
class String
{
private:
	char* str;
public:
	String(const char* s)
	{
		if (s != nullptr)
		{
			int len = strlen(s) + 1;
			str = new char[len];
			strcpy_s(str, len, s);
		}
		else
		{
			str = new char[1];
			*str = '\0';
		}
	}
	~String()
	{
		if (str != nullptr)
		{
			delete[]str;
		}
		str = nullptr;
	}

	String(const String &s)
	{
		int len = strlen(s, str) + 1;
		str = new char[len];
		strcpy_s(str, len, s, str);
	}
};
int main()
{
	String s1("liangxuan");
	String s2("s1");

	return 0;
}




class Object
{
	int value;
	int* ip;
	int ar[100];
public:
	Object() :value(0), ip(nullptr)
	{
		for (int i = 0; i < 100; i++)
		{
			ar[i] = i;
		}
	}
	Object(const Object& obj)//缺省的拷贝构造函数
		:value(obj.value), ip(obj.ip)
	{
		for (int i = 0; i < 100; ++i)
		{
			ar[i] = obj.ar[i];
		}
}
/*
	什么情况下必须使用拷贝构造函数？
	    
*/



class Object
{
private:
	int value;
	float price;
public:
	Object(int val = 0, float ft = 0.0) :value(val), price(ft)
	{}
	~Object() {};

	//1、拷贝构造函数
	Object(const Object& cs)
	{
		value = cs.value;
		price = cs.price;
	}
	//2、
	/*
		Object(const Object& cs):value(obj.value),price(obj.price){}
	*/
}




int num = 10;
class Object
{
private:
	int value;
public:
	Object(int x = 0) : value(x) {
		cout << "construct object:" << this << ":" << ++num << endl;
	}
	~Object() { cout << "deconstruct object: " << this << endl; }
	void Print() const
	{
		cout << value << endl;
	}
};
int main()
{
	int n = 10;
	Object* op = new Object[n];
	//开始op指向第一个Object[0],如何让其指向Object[2]
	(op + 2)->Print();//*(op + 2).Print();//op[2].Print();

	delete []op;//一组对象
	//delete op;//一个对象

	return 0;
}


class CGoods
{
private:
	char Name[21];
	int Amount;
	float Price;
	float Total_value;
public:
	void RegisterGoods(const char[], int, float);//输入数据
	void CountTotal(void);//总价值
	void GetName(char[]);//读取商品名
	int GetAmount();//读取商品数量
	float GetPrice();//读取商品单价
	float GetTotal_value(); //读取商品总价值
};

float CGoods::GetTotal_value()
{
	return Total_value;
}

void CGoods::CountTotal(void)
{
	Total_value = Price * Amount;
	cout << Total_value << endl;
}

void CGoods::RegisterGoods(const char name[], int amount, float price)
{
	strcpy_s(Name, 21, name);
	Amount = amount;
	Price = price;
}

void CGoods::GetName(char name[])
{
	strcpy_s(name, 21, Name);
}

int CGoods::GetAmount(void)
{
	return (Amount);
}

float CGoods::GetPrice() { return(Price); }

int main()
{
	CGoods tea;
	CGoods book;
	tea.RegisterGoods("red_tea", 12, 560);
	tea.CountTotal();
}

template <class T>
const T& Max(const T& a, const T& b)
{
	return a > b ? a : b;
}

int main()
{
	int n = Max(12, 23);
	double d = Max(12.23, 25.24);

	cout << n << endl;
	cout << d << endl;
	return 0;
}

void Swap(int &x, int &y)
{
	int tmp = x;
	x = y;
	y = tmp;
}

int main()
{
	int a = 10;
	int b = 20;
	Swap(a, b);
	printf("%d %d", a, b);

	return 0;
}

int main()
{
	int a;
	char ch;
	scanf("%d %c", &a, &ch);
	printf("%d %f \n", a, ch);
	return 0;
}
#endif
