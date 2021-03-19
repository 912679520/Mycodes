#include<iostream>
#include<list>
using namespace std;



#if 0
struct MyObserver //π€≤Ï’ﬂ
{
	virtual void response() = 0;
};

class Mouse :public MyObserver
{
public:
	void response() { cout << "Ã”≈‹" << endl; }
};

class Dog :public MyObserver
{
public:
	void response() { cout << "π∑Ω–" << endl; }
};

class MySubject
{
protected:
	std::list<MyObserver*> obslist;
public:
	void attach(MyObserver* obs)
	{
		obslist.push_back(obs);
	}
	void detach(MyObserver* obs)
	{
		obslist.remove(obs);
	}
	virtual void cry() = 0;
};

class Cat :public MySubject
{
public:
	void cry()
	{
		cout << "√®Ω–£°" << endl;
		cout << "--------------" << endl;
		for (auto& x : obslist)
		{
			x->response();
		}
	}
};

int main()
{
	MySubject* sp = new Cat();
	MyObserver* oba = new Mouse();
	MyObserver* obb = new Dog();
	sp->attach(oba);
	sp->attach(obb);
	sp->cry();
	sp->detach(oba);
	sp->cry();
	return 0;
}


class Car
{
public:
	virtual void Show() = 0;
	virtual ~Car() {}
};

class BydCar :public Car
{
public:
	BydCar() { cout << "Byd::Byd()" << endl; }
	~BydCar() {}
	virtual void Show()
	{
		cout << "Byd auto" << endl;
	}
};

class GeelyCar :public Car
{
public:
	GeelyCar() { cout << "Geely::Geely()" << endl; }
	~GeelyCar() {}
	virtual void Show()
	{
		cout << "Geely auto" << endl;
	}
};

class Factory
{
public:
	virtual Car* creatCar() = 0;
};

class BydFactory :public Factory
{
public:
	virtual Car* craetCar() { return (new BydCar()); }
};

class GeelyFactory :public Factory
{
public:
	virtual Car* craetCar() { return (new GeelyCar()); }
};

int main()
{
	Factory* factory = new BydFactory();
	Car* bydCar = factory->creatCar();
	factory = new GeelyFactory();
	Car* GeelyCar = factory->creatCar();

	delete factory;
	delete bydCar;
	delete GeelyCar;

	return 0;
}
#endif