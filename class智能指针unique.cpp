#include<iostream>
#include<memory>
#include<vector>
using namespace std;

//shared_ptr

#if 0
//�����͸�ֵ
class Object
{
private:
	string value;
public:
	Object(string x = 0) :value(x)
	{
		cout <<value<< "����Obj: " << endl;
	}
	~Object()
	{
		cout <<value<< "����Obj: " << endl;
	}
	string& Value() { return value; }
	const string& Value() const { return value; }
};
int main()
{
	shared_ptr<Object> pObj = make_shared<Object>("a object");
	shared_ptr<Object> pObj2 = make_shared<Object>("b object");
	
	cout << pObj.use_count() << endl;
	cout << pObj2.use_count() << endl;
	pObj = pObj2;
	cout << pObj->Value() << endl;
	cout << pObj2->Value() << endl;
}


int main()
{
	shared_ptr<string> pStr = make_shared<string>(10, 'f');
	cout << pStr.use_count() << endl;//1
	shared_ptr<string> pStr2(pStr);
	cout << pStr.use_count() << endl;//2
	cout << pStr2.use_count() << endl;//2
}


//make_shared����
int main()
{
	shared_ptr<string> pstr = make_shared<string>(10,'x');
	cout << *pstr << endl;

	int* p = new int(10);
	shared_ptr<int> pp(p);
	cout << *pp << endl;

	return 0;
}



class Object
{
private:
	int value;
public:
	Object(int x = 0) :value(x)
	{
		cout << "����Obj: " << endl;
	}
	~Object()
	{
		cout << "����Obj: " << endl;
	}
	int& Value() { return value; }
	const int& Value() const { return value; }
};
int main()
{
	shared_ptr<Object> pObj(new Object(100));
	cout << (*pObj).Value() << endl;
	cout << "pObj ���ü�����" << pObj.use_count() << endl;
	shared_ptr<Object> pObj2 = pObj;
	cout << "pObj ���ü�����" << pObj.use_count() << endl;
	cout << "pObj2 ���ü�����" << pObj2.use_count() << endl;
	return 0;
}


//unique_ptr��д
namespace U_ptr
{

	template<class _Tp>
	struct default_delete //ɾ����
	{
		constexpr default_delete() noexcept = default;

		void operator()(_Tp* ptr) const
		{
			delete ptr;
		}
	};

	template<typename _Tp,typename _Dp = default_delete<_Tp>>
	class unique_ptr
	{
	private:
		_Tp* ptr;
	public:
		typedef _Tp* pointer;
		typedef _Tp element_type;
		typedef _Dp delete_type;
	public:
		//û�п������캯��unique_ptr<int> pInt2(pInt);
		unique_ptr(const unique_ptr&) = delete;
		unique_ptr& operator=(const unique_ptr&) = delete;

		delete_type get_deleter()
		{
			return delete_type;
		}
	public:
		unique_ptr() :ptr(nullptr) {}
		//unique_ptr<int> p;
		explicit unique_ptr(pointer p) : ptr(p) {}

		//unique_ptr<int> pInt2 = std::move(pInt);
		unique_ptr(unique_ptr&& u) noexcept
		{
			ptr = u.release();
		}

		//pInt3 = pInt;
		unique_ptr& operator=(unique_ptr&& u)
		{
			reset(u.release());
			return *this;
		}
		~unique_ptr()
		{
			if (ptr != nullptr)
			{
				get_deleter()(ptr);
			}
			ptr = nullptr;
		}
		pointer get() const { return ptr; }
		_Tp& operator*() const { return *get; }
		pointer operator->() const { return get(); }

		explicit operator bool() const noexcept
		{
			return get() == nullptr ? false : true;
		}

		pointer release() noexcept
		{
			pointer p = ptr;
			ptr = nullptr;
			return p;
		}

		void reset(pointer p = nullptr)
		{
			get_deleter()(ptr);
			ptr = p;
		}

		void swap(unique_ptr& u) noexcept
		{
			using std::swap;
			swap(ptr, u.ptr);
		}
	};
}

int main()
{
	/*
	unique_ptr<int> ptr(new int(5));
	cout << *ptr.get() << endl;*/
}
 
//����̬����
int main()
{
	unique_ptr<int[]> p(new int[5]{ 1,2,3,4,5 });
	p[0] = 0;//������operator[]
	cout << p[0] << endl;
}


//�������ڱ���ָ��
int main()
{
	vector<unique_ptr<int> > vec;
	unique_ptr<int> pInt(new int(5));
	vec.push_back(std::move(pInt));
}



//���Է���unique_ptr
unique_ptr<int> clone(int a)
{
	unique_ptr<int> pInt(new int(a));
	//����unique_ptr
	return pInt;
}
int main()
{
	int x = 5;
	unique_ptr<int> reta = clone(x);
	unique_ptr<int> retb;
	retb = clone(x);
	cout << *reta << endl;
	cout << *retb << endl;
}

int main()
{
	unique_ptr<int> pInt(new int(5));
	//ת������Ȩ
	unique_ptr<int> pInt2 = std::move(pInt);
	//cout << *pInt << endl; //pIntΪ��
	cout << *pInt2 << endl;
	unique_ptr<int> pInt3(std::move(pInt2));
	cout << *pInt3 << endl;
}


int main()
{
	unique_ptr<int> pInt(new int(5));
	//�޷����ƹ���͸�ֵ
	//û�п������캯��
	unique_ptr<int> pInt2(pInt);
	unique_ptr<int> pInt3;
	pInt3 = pInt;
}


int main()
{
	unique_ptr<int> Pint(new int(2));
	cout << *Pint;
}
#endif