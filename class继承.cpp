#include<string>
#include<iostream>
using namespace std;

class Object
{
private:
	int value;
public:
	Object(int x = 0) :value(x) {}
	virtual void add()
	{
		cout << "Object::add()" << endl;
	}
	virtual void fun()
	{
		cout << "Object::fun()" << endl;
	}
	virtual void print() const
	{
		cout << "Object::print()" << endl;
	}
};
class Base :public Object
{
private:
	int num;
public:
	Base(int x = 0) :Object(x + 10),num(x) {}
	virtual void add()
	{
		cout << "Base::add()" << endl;
	}
	virtual void fun()
	{
		cout << "Base::fun()" << endl;
	}
	virtual void show() const
	{
		cout << "Base::show()" << endl;
	}
};
class Test :public Base
{
private:
	int count;
public:
	Test(int x = 0) :Base(x), count(x + 10) {}
	virtual void add()
	{
		cout << "Test::add()" << endl;
	}
	virtual void fun()
	{
		cout << "Test::fun()" << endl;
	}
	virtual void show() const
	{
		cout << "Test::show()" << endl;
	}
};
void lx(Object* op)
{
	op->add();
	op->fun();
	op->print();
	printf("\n");
}
int main()
{
	Object obj;
	Base base;
	Test test;
	lx(&obj);
	lx(&base);
	lx(&test);

	return 0;
}

#if 0
class Animal
{
private:
	string name;
public:
	Animal(const string& na) :name(na)
	{

	}
	~Animal() {}
	//Ðéº¯Êý
	virtual void eat() {}
	virtual void walk() {}
	virtual void talk() {}
	virtual void PrintInfo() const {}
	const string& Getname() const { return name; }
};
class Dog :public Animal
{
private:
	string owner;
public:
	Dog(const string& own, const string& na) :Animal(na), owner(own) {}
	~Dog() {}
public:
	virtual void eat() { cout << "Dog eat:bone " << endl; }
	virtual void walk() { cout << "Dog walk:run " << endl; }
	virtual void talk() { cout << "Dog talk:wang~" << endl; }
	virtual void PrintInfo() const
	{
		cout<< "Dog owner: " << owner << endl;
		cout << "Dog name: " << Getname() << endl;
	}
};
class Cat :public Animal
{
private:
	string owner;
public:
	Cat(const string& own, const string& na) :Animal(na), owner(own) {}
	~Cat() {}
public:
	virtual void eat() { cout << "Cat eat: fish " << endl; }
	virtual void walk() { cout << "Cat walk: silent " << endl; }
	virtual void talk() { cout << "Cat talk:Miao~" << endl; }
	virtual void PrintInfo() const
	{
		cout << "Cat owner: " << owner << endl;
		cout << "Cat name: " << Getname() << endl;
	}
};

void fun(Animal& animal)
{
	animal.eat();
	animal.walk();
	animal.talk();
	animal.PrintInfo();
}
int main()
{
	Dog dog("lx", "2ha");
	Cat cat("lxx", "Persian");

	fun(dog);
	fun(cat);

	return 0;
}


//Í¬ÃûÒþ²Ø
class Object
{
public:
	void fun(int x)
	{
		cout << "Object :: fun" << x << endl;
	}
};
class Base :public Object
{
public:
	void fun(int x)
	{
		cout << "Base::fun" << x << endl;
	}
	void fun(int a, int b)
	{
		cout << "Base::fun(int,int):" << a << b << endl;
	}
};

int main()
{
	Base base;
	base.fun(12);
	base.fun(1, 2);

	return 0;
}

class Object
{
public:
	int value;
public:
	Object(int x = 0) :value(x) {}
};
class Base :public Object
{
public:
	int value;
	int num;
public:
	Base(int x = 0) :Object(x), value(x + 10), num(x + 20) {}
	void fun()
	{
		value = 10;
		num = 20;
		Object::value = 20;
	}
};
int main()
{
	Base base;
	base.value = 10;
	base.Object::value = 20;
	return 0;
}
#endif