#include<iostream>
#include<string>
using namespace std;



#if 0
class Person
{
private:
	char IdPerson[19];
	char Name[20];
public:
	Person() 
	{
		IdPerson[0] = '\0';
		Name[0] = '\0';
	}
	Person(char* id, char* name)
	{
		strcpy_s(IdPerson, 19, id);
		strcpy_s(Name,20,name);
	}
	~Person(){}
	void PrintPersonInfo() const
	{
		cout << "���֤�ţ�" << IdPerson << '\n' << "������" << Name << endl;
	}
};
class Student : public Person
{
private:
	char snum[10];
	float grade;
public:
	Student():Person(){}
	Student(char* id, char* name, char* sn) :Person(id, name)
	{
		strcpy_s(snum,10, sn);
		grade = 0.0;
	}
	~Student(){}
	void PrintStudentInfo() const
	{
		PrintPersonInfo();
		cout << "ѧ�ţ�" << snum << "\n" << "�ɼ���" << grade << endl;
	}
	void SetGrade(float ft)
	{
		grade = ft;
	}
};
int main()
{
	Person s1;
	Person s2("610321199910580845", "tulun");
	Student s3("610321199910580846", "tunlun", "20071010");
	s2.PrintPersonInfo();
	s3.SetGrade(149.2);
	s3.PrintPersonInfo();
}

//�̳�
//���м̳���������һ������˼
//˽�м̳д�������ʲô�����
class Object
{
private:
	int xa;
protected:
	int xb;
public:
	int xc;
	void Setoa(int x) { xa = x; }
	void Setob(int x) { xb = x; }
};
class Base :public Object
{
private:
	int ba;
	Object obj;
protected:
	int bb;
public:
	int bc;
	void fun()
	{
		/*
		��Ա��ϵ��������˽�й�ϵ����
		�̳й�ϵ�������չ��й�ϵ����
		*/
		ba = bb = bc = 0;
		//xa = 1;  //���ܷ���˽��
		xb = 2;
		xc = 3;

		obj.xc = 10;
		//obj.xb = 100;
	}
};

int main()
{
	Object obj;
	Base base;
	base.fun();
	base.bc = 10;
	//base.xc = 12;


	/*
	cout << sizeof(Object) << endl; //12���ֽ�
	cout << sizeof(Base) << endl;   //24���ֽ�
	*/
	return 0;
}



class Object
{
private:
	int value;
	static int num;
public:
	Object(int x = 0) : value(x) { cout << "���캯����" << ++num << endl; }
	~Object() { cout << "����������" << num-- << endl; }

	void fun() 
	{ 
		cout << value << " " << num << endl;
	}
	static void show() //no this
	{
		//cout<< value << endl;   no this
		cout << num << endl;
	}
};
int Object::num = 0;

int main()
{
	Object obj(10);
	obj.fun();
	obj.show();

	return 0;
}

//C++ static
class Object
{
private:
	static int num;
public:
	Object() { cout << "���캯����" << ++num << endl; }
	~Object() { cout << "����������" << num-- << endl; }
};
int Object::num = 0;
class Base :public Object
{
public:
	Base() {
		cout << "Base: " << endl;
	}
};
class Test :public Object
{
public:
	Test()
	{
		cout << "Test��" << endl;
	}
};
int main()
{
	Base base[2];
	Test test[3];

	return 0;
}

//int num = 0;
class Object
{
private:
	int value;
	static int num;
public:
	Object (int x = 0) : value(x)
	{
		cout << "���캯�� obj num: " << ++num << endl;
	}
	~Object()
	{
		cout << "�������� obj num: " << num -- << endl;
	}
};
int Object::num = 0;
int main()
{
	Object obj1(10);
	Object obj2(20);
	Object obj3(30);
	cout << sizeof(obj1) << " " << sizeof(Object) << endl;
	return 0;
}

class Int;
class Object
{
public:
	void fun(Int& it);
};
class Int
{
	friend class Object;
private:
	int value;
public:
	Int(int x = 0) : value(x) {}
	~Int() {}
};

class Float : public Int
{
private:
	float ft;
};

void Object::fun(Int& it)
{
	it.value = 100;
}

int main()
{
	Object obj;
	Int a(0);
	obj.fun(a);

	return 0;
}



//��Ա������Ԫ
class Int;
class Object
{
public:
	void fun(Int& it);
};
class Int
{
private:
	int value;
public:
	Int(int x = 0) : value(x) {}
	~Int() {}
	friend void Object::fun(Int& it);
};

void Object::fun(Int& it)
{
	it.value = 100;
}

//1��������Ԫ
//2����Ա������Ԫ
//3������Ԫ

/*
�ص㣺���򡢲����д����ԡ������м̳�����
*/

//������Ԫ
class Int
{
private:
	int value;
public:
	Int(int x = 0) : value(x) {}
	~Int() {}
	friend void fun(Int &it);
};


void fun(Int& it)
{
	it.value = 10;
}

int main()
{
	Int a(0);
	fun(a);
	return 0;
}
#endif
