#include<iostream>
using namespace std;

class Object
{
private:
	int value;
public:
	Object(int x = 0) :value(x)
	{
		cout << "construct object" << endl;
	}
	~Object()
	{
		cout << "deconstruct object" << endl;
	}
	int& Value() { return value; }
	const int& Value() const { return value; }
};

class Child;
class Parent
{
public:
	weak_ptr<Child> c;
	~Parent()
	{
		cout << "Bye Parent" << endl;
	}
	void hi() const
	{
		cout << "hello Parent" << endl;
	}
};
class Child
{
public:
	weak_ptr<Parent> p;
	~Child()
	{
		cout << "Bye Child" << endl;
	}
};

int main()
{
	//shared_ptr<Parent> par = make_shared<Parent>();
	shared_ptr<Parent> par(new Parent());
	shared_ptr<Child> pch(new Child());
	par->c = pch;
	pch->p = par;
	//pch->p->hi();
	//if (pch->p.expired())
	//{
	//	pch->p.lock()->hi();
	//}
	return 0;
}

#if 0
class Object
{
private:
	int value;
public:
	Object(int x = 0) :value(x)
	{
		cout << "construct object" << endl;
	}
	~Object()
	{
		cout << "deconstruct object" << endl;
	}
	int& Value() { return value; }
	const int& Value() const { return value; }
};

int main()
{
	shared_ptr<Object> sp(new Object(100));
	weak_ptr<Object> wp(sp);
	sp.reset();
	if (shared_ptr<Object> pa = wp.lock())
	{
		cout << pa->Value() << endl;
	}
	else
	{
		cout << wp.expired() << endl;
		cout << "wp nullptr" << endl;
	}

	return 0;
}


int main()
{
	shared_ptr<Object> pobja(new Object(10));
	cout << "pobja cnt" << pobja.use_count() << endl;
	weak_ptr<Object> wp(pobja);

	cout << "pobja cnt: " << pobja.use_count() << endl;
	return 0;
}

class Child;
class Parent
{
public:
	shared_ptr<Child> c;
	~Parent()
	{
		cout << "Bye Parent" << endl;
	}
	void hi() const
	{
		cout << "hello Parent" << endl;
	}
};
class Child
{
public:
	shared_ptr<Parent> p;
	~Child()
	{
		cout << "Bye Child" << endl;
	}
};

int main()
{
	//shared_ptr<Parent> par = make_shared<Parent>();
	shared_ptr<Parent> par(new Parent());
	shared_ptr<Child> pch(new Child());
	par->c = pch;
	pch->p = par;
	pch->p->hi();

	return 0;
}

#endif
