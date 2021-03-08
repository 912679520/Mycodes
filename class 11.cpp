
#include<iostream>
using namespace std;



#if 0
class Object
{
	int value;
public:
	Object(int x = 0) :value(x)
	{
		cout << "���� Object��" << this << endl;
	}
	Object(const Object& obj) :value(obj.value)
	{
		cout << "���� Object��" << this<<endl;
	}
	Object& operator=(const Object& obj)
	{
		if (this != &obj)
		{
			value = obj.value;
		}
		cout << "Object = " << endl;
		return *this;
	}
	~Object()
	{
		cout << "���� Object��" << this << endl;
	}
};
class Base :public Object
{
private:
	int num;
public:
	Base(int x = 0) :num(x + 10), Object(x)
	{
		cout << "���� Base:" << this << endl;
	}
	Base(const Base& base) :num(base.num), Object(base)
	{
		cout << "���� Base��" << this << endl;
	}
	Base& operator=(const Base& base)
	{
		if (this != &base)
		{
			num = base.num;
		}
		cout << "Base = " << endl;
		return *this;
	}
	~Base()
	{
		cout << "���� Base: " << this << endl;
	}
};

int main()
{
	Base base1(10); //sizeof(Base) 8bytes
	Base base2(100);
	base1 = base2;

	return 0;
}


class Person
{
	string id;
	string name;
public:
	Person(string i, string na) :id(i), name(na) {}
	~Person() {}
};

class Student :public Person
{
	string school;
public:
	Student(string id, string na, string s) :Person(id, na), school(s)
	{}
	~Student() {}
	void Print() const
	{
		cout << "school: " << endl;
	}
};
int main()
{
	Person ps("90900001", "lxuan");
	Student s("0111111", "lx", "tulun");

	Student* sp = &s;

	sp = (Student*) &ps;
	sp->Print();
}

 
int main()
{
	Person ps("09999", "lx");
	Student s("11111", "lxuan", "tulun");

	//��Ƭ����
	//ps = s;

	Person* p = &ps;

	p = &s;

	int x = sizeof(string);

	return 0;
}


/*
static�ص㣺
��̬��Ա���Ա��̳С�
�Ӷ��󽫹��������������ľ�̬���ݳ�Ա
*/
template<class T>
class Object
{
private:
	static int num;//���� //�������������ⶨ��
	int value;
public:
	Object(int x = 0) : value(x)
	{
		cout << "Object: " << ++num << endl;
	}
	~Object()
	{
		cout << "Object: "<< num-- << endl;
	}
	int Getvalue();
	static void Print();
};
template <class T>
int Object<T>::num = 0;//����

template<class T>
int Object<T>::Getvalue() { return value; }

template<class T>
void Object<T>::Print() { cout << num << ednl; }

class Base : public Object<Base>
{
public:
	Base(int x) : Object(x) 
	{
		cout << "Base: " << endl;
	}
	~Base() {}

};

class Test :public Object<Test>
{
public:
	Test(int x = 0) : Object(x) 
	{
		cout << "Test: " << endl;
	}
	~Test() {}
};

int main()
{
	Base base1(1);
	Base base2(2);
	Base base3(3);
	Test t1(1);
	Test t2(2);
	Test t3(3);

	return 0;
}

int main()
{
	Object obj1(10);
	Object obj2(20);
	Object obj3(30);

	return 0;
}

#endif