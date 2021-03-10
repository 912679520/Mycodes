#include<string>
#include<iostream>
using namespace std;

//����ָ��
/*
��ָ������⣺int *p
1����������ָ��ĵ���������һ������
2��ʹ����ָ��֮���޷��ж��Ƿ�Ӧ������ָ�룬��Ϊ�޷�
�ж�ָ���Ƿ�ӵ��ָ��Ķ���
3�����Ѿ�ȷ����Ҫ����ָ�������£�Ҳ�޷�ȷ������delete
�ؼ���ɾ����������������������ٻ��ƣ�����ͨ��ָ�봫��
ĳ���ض������ٺ���������ָ��
4�������Ѿ�ȷ��������ָ��ķ���������ԭ��1����Ȼ�޷�ȷ��
��������delete����delete[]
5�������������ⶼ�����Ҳ���ѱ�֤�ڴ��������·���У�
���ҽ���һ������ָ�����������·����©���������
�ڴ�й©�������ٶ�λᵼ��δ������Ϊ
6��������û�з����ֱ�һ��ָ���Ƿ�������״̬
*/

class Object
{
private:
	int value;
public:
	Object(int x = 0) :value(x) { cout << "���� obj" << endl; }
	~Object() { cout << "���� obj" << endl; }
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


//ģ��
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



//ģ�����Ͳ���
template <class T> // �ȼ� tempalte <typename T>
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
		cout << "���������" << length * length << endl;
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
		cout << "Բ�������" << PI * radius * radius << endl;
	}
};

void fun(Shapes& sp)
{
	cout << sp.ShapesName() << endl;
	sp.disp();
}

int main()
{
	Square s("������", 10);
	Circle c("Բ��",5);
	fun(s);
	fun(c);
	return 0;
}

//������
class Object //���麯��������Ϊ������
{
private:
	int value;
public:
	Object(int x = 0) :value(x) {}
	~Object() {}
	virtual void fun() = 0;//���麯��
};

int main()
{
	//Object obj(x);

	return 0;
}
#endif