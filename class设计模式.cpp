
#include<string>
#include<iostream>
#include<memory>
#include<map>			//顺序关联容器  key sort  rbtree
#include<unordered_map>//非		key not sort link_hash
using namespace std;

//简单工厂模式
class NotPayment
{
public:
	NotPayment(const string& type)
	{
		cout << "Cannot CreatPayment" << type << endl;
	}
};
struct Payment
{
	virtual void pay(float) = 0;
	static Payment* Factory(const string& type);
	virtual ~Payment() {}
};

class DebitCard : public Payment
{
	friend struct Payment;
protected:
	DebitCard() { cout << "Creat DebitCard:" << endl; }
public:
	~DebitCard() { cout << "Destroy DebitCard:" << endl; }
	void pay(float ft) { cout << "DebitCard pay:" << ft << endl; }
};

class CreditCard : public Payment
{
	friend struct Payment;
protected:
	CreditCard() { cout << "Creat CreditCard:" << endl; }
public:
	~CreditCard() { cout << "Destroy CreditCard:" << endl; }
	void pay(float ft) { cout << "CreditCard pay:" << ft << endl; }
};

class AliPay : public Payment
{
	friend struct Payment;
protected:
	AliPay() { cout << "Creat AliPay:" << endl; }
public:
	~AliPay() { cout << "Destroy AliPay:" << endl; }
	void pay(float ft) { cout << "AliPay pay:" << ft << endl; }
};

class WechatPay : public Payment
{
	friend struct Payment;
protected:
	WechatPay() { cout << "Creat WechatPay:" << endl; }
public:
	~WechatPay() { cout << "Destroy WechatPay:" << endl; }
	void pay(float ft) { cout << "WechatPay pay:" << ft << endl; }
};

Payment* Payment::Factory(const string& type)
{
	if (type == "Debit")
	{
		return new DebitCard();
	}
	else if (type == "Credit")
	{
		return new CreditCard();
	}
	else if (type == "Ali")
	{
		return new AliPay();
	}
	else if (type == "Wechat")
	{
		return new WechatPay();
	}
	else
	{
		//return nullptr;
		throw NotPayment(type);
	}
}

class PayFactory
{
private:
	std::unordered_map<string, shared_ptr<Payment>>paycon;
public:
	PayFactory() 
	{
		string type[] = {"Debit","Credit","Ali","Wechat"};
		for (auto& x : type)
		{
			paycon.insert(std::pair<string, shared_ptr <Payment>>(x, Payment::Factory(x)));
		}
	}
	~PayFactory() {}
	shared_ptr<Payment> GetPayObject(const string& type)
	{
		return shared_ptr<Payment>(paycon.at(type));
	}
};
int main()
{
	PayFactory pay;
	shared_ptr<Payment> pa;
	pa = pay.GetPayObject("Ali");
	pa->pay(12);
	pa = pay.GetPayObject("Wechat");
	pa->pay(14);

	return 0;
}




#if 0
class NotPayment
{
public:
	NotPayment(const string& type)
	{
		cout << "Cannot CreatPayment" << type << endl;
	}
};
struct Payment
{
	virtual void pay(float) = 0;
	static Payment* Factory(const string& type);
	virtual ~Payment() {}
};

class DebitCard : public Payment
{
	friend struct Payment;
protected:
	DebitCard() { cout << "Creat DebitCard:" << endl; }
public:
	~DebitCard() { cout << "Destroy DebitCard:" << endl; }
	void pay(float ft) { cout << "DebitCard pay:" << ft << endl; }
};

class CreditCard : public Payment
{
	friend struct Payment;
protected:
	CreditCard() { cout << "Creat CreditCard:" << endl; }
public:
	~CreditCard() { cout << "Destroy CreditCard:" << endl; }
	void pay(float ft) { cout << "CreditCard pay:" << ft << endl; }
};

class AliPay : public Payment
{
	friend struct Payment;
protected:
	AliPay() { cout << "Creat AliPay:" << endl; }
public:
	~AliPay() { cout << "Destroy AliPay:" << endl; }
	void pay(float ft) { cout << "AliPay pay:" << ft << endl; }
};

class WechatPay : public Payment
{
	friend struct Payment;
protected:
	WechatPay() { cout << "Creat WechatPay:" << endl; }
public:
	~WechatPay() { cout << "Destroy WechatPay:" << endl; }
	void pay(float ft) { cout << "WechatPay pay:" << ft << endl; }
};

Payment* Payment::Factory(const string& type)
{
	if (type == "Debit")
	{
		return new DebitCard();
	}
	else if (type == "Credit")
	{
		return new CreditCard();
	}
	else if (type == "Ali")
	{
		return new AliPay();
	}
	else if (type == "Wechat")
	{
		return new WechatPay();
	}
	else
	{
		//return nullptr;
		throw NotPayment(type);
	}
}

class PayFactory
{
public:
	PayFactory() {}
	~PayFactory() {}
	unique_ptr<Payment> GetPayObject(const string& type)
	{
		return unique_ptr<Payment>(Payment::Factory(type));
	}
};
int main() try
{
	PayFactory pay;
	unique_ptr<Payment> pa;
	pa = pay.GetPayObject("A");
	pa->pay(12);
	pa = pay.GetPayObject("lx");
	pa->pay(14);

	return 0;
}
catch (NotPayment)
{
	exit(1);
}

struct Shape
{
	virtual void draw() const = 0;
	virtual void erea() const = 0;
	virtual void SetValue(float ft) = 0;
	static Shape* factory(const string& type);
	virtual ~Shape() {}
};

class Circle :public Shape
{
	friend class Shape;
private:
	float radius;
	static const float pi;
protected:
	Circle(float r = 0) :radius(r) { cout << "Create Circle" << endl; }
public:
	~Circle() { cout << "Destory Circle" << endl; }
	void SetValue(float ft) { radius = ft; }
	void draw() const { cout << "draw: Circle" << endl; }
	void erea() const { cout << "Circle erea:" << pi * radius * radius << endl; }

};

const float Circle::pi = 3.14;

class Square :public Shape
{
	friend class Shape;
private:
	float side;
protected:
	Square(float a = 0) :side(a) { cout << "Create Square" << endl; }
public:
	~Square() { cout << "Destroy Square" << endl; }
	void SetValue(float ft) { side = ft; }
	void draw() const { cout << "draw:Square" << endl; }
	void erea() const { cout << "Square eara" << side * side << endl; }
};

Shape* Shape::factory(const string& type)
{
	if (type == "Circle")
	{
		return new Circle();
	}
	else if (type == "Square")
	{
		return new Square();
	}
	else
	{
		return nullptr;
	}
}
class ShapeFactory
{
public:
	ShapeFactory() {}
	~ShapeFactory() {}

	shared_ptr<Shape> GetShape(const string& type)
	{
		return shared_ptr<Shape> (Shape::factory(type));
	}
};

int main()
{
	unique_ptr<ShapeFactory> uqs(new ShapeFactory());

	shared_ptr<Shape> sp1 = uqs->GetShape("Circle");
	sp1->SetValue(12);
	sp1->draw();
	sp1->erea();

	sp1 = uqs->GetShape("lx");
	if (sp1)
	{
		sp1->SetValue(10);
		sp1->draw();
		sp1->erea();
	}
	

	return 0;
}


struct Shape
{
	virtual void draw() const = 0;
	virtual void erea() const = 0;
	virtual void SetValue(float ft) = 0;
	static Shape* factory(const string& type);
	virtual ~Shape() {}
};

class Circle:public Shape
{
	friend class Shape;
private:
	float radius;
	static const float pi;
protected:
	Circle(float r = 0) :radius(r) { cout << "Create Circle" << endl; }
public:
	~Circle() { cout << "Destory Circle" << endl; }
	void SetValue(float ft) { radius = ft; }
	void draw() const { cout << "draw: Circle" << endl; }
	void erea() const { cout << "Circle erea:" << pi * radius * radius << endl; }

};

const float Circle::pi = 3.14;

class Square :public Shape
{
	friend class Shape;
private:
	float side;
protected:
	Square(float a = 0) :side(a) { cout << "Create Square" << endl; }
public:
	~Square() { cout << "Destroy Square" << endl; }
	void SetValue(float ft) { side = ft; }
	void draw() const { cout << "draw:Square" << endl; }
	void erea() const { cout << "Square eara" << side * side << endl; }
};

Shape* Shape::factory(const string& type)
{
	if (type == "Circle")
	{
		return new Circle();
	}
	else if (type == "Square")
	{
		return new Square();
	}
	else
	{
		return nullptr;
	}
}
class ShapeFactory
{
public:
	ShapeFactory() {}
	~ShapeFactory() {}

	Shape* GetShape(const string& type)
	{
		return Shape::factory(type);
	}
};

int main()
{
	/*
	//Shape* s = Shape::factory("Circle");
	ShapeFactory* shape = new ShapeFactory();
	Shape* s = shape->GetShape("Circle");
	s->draw();
	s->SetValue(12);
	s->erea();
	delete s;
	s = nullptr;

	Shape* p = shape->GetShape("Square");
	p->draw();
	p->SetValue(10);
	p->erea();
	delete p;
	p = nullptr;
*/
	return 0;
}
#endif