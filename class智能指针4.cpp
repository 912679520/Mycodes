
#include<list>
#include<iostream>
using namespace std;




#if 0
class Object
{
private:
	int value;
public:
	Object(int x = 0) :value(x)
	{
		cout << "construct Obj" << endl;
	}
	Object(int x, int y) :value(x + y)
	{
		cout << "construct obj" << endl;
	}
	~Object()
	{
		cout << "deconstruct obj" << endl;
	}
	int& Value() { return value; }
	const int& Value() const { return value; }
};

int main()
{
	list<std::shared_ptr<Object> > objlist;
	for (int i = 0; i < 10; ++i)
	{
		objlist.push_back(std::make_shared<Object>(i + 10));

	}
	list<std::shared_ptr<Object> >::iterator it = objlist.begin();
	for (; it != objlist.end();++it)
	{
		cout << (*it)->Value() << endl;
	}
	weak_ptr<Object> wp(objlist.front());
	objlist.pop_front();

	return 0;
}

double couldThrow()
{
	//throw 10;
	return 12.23;
}
void doSomething(std::shared_ptr<Object> pt, double d)
{
	cout << "end Dosonething" << endl;
}

int main()
{
	try
	{
		doSomething(std::shared_ptr<Object>(new Object(1024)), couldThrow());
	}
	catch (...)
	{
		cout << "throw 10" << endl;
	}
	cout << "main end" << endl;
	return 0;
}

class Object
{
private:
	int value;
public:
	Object(int x = 0) :value(x)
	{
		cout << "construct Obj" << endl;
	}
	Object(int x, int y) :value(x + y)
	{
		cout << "construct obj" << endl;
	}
	~Object()
	{
		cout << "deconstruct obj" << endl;
	}
	int& Value() { return value; }
	const int& Value() const { return value; }
};

int main()
{
std::shared_ptr<Object> pobja(new Object(10));
std::shared_ptr<Object> pobjb = make_shared<Object>(20);

//make_shared
std::shared_ptr<Object> pobjc = make_shared<Object>(20, 10);

}
#endif