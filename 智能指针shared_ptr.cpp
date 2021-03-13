//·ÂÐ´shared_ptr
#include<memory>
#include<atomic>
#include<iostream>
using namespace std;

template<typename T>
class RefCnt
{
private:
	T* mPtr;
	std::atomic<int> mCnt;//Ô­×Ó²Ù×÷
public:
	RefCnt(T* ptr = nullptr) :mPtr(ptr)
	{
		if (mPtr != nullptr)
		{
			mCnt = 1;
		}
	}
	void addRef() { mCnt++; }
	int deleRef() { return --mCnt; }
	~RefCnt() {}
};

template<typename T>
class MyDeletor
{
public:
	void operator()(T* ptr) const
	{
		delete ptr;
	}
};

template<typename T, typename Deletor = MyDeletor<T>>
class Shared_ptr
{
public:
	Shared_ptr(T* ptr = nullptr) :mPtr(ptr)
	{
		mpRefCnt = new RefCnt<T>(ptr);
	}
	~Shared_ptr()
	{
		if (mpRefCnt->deleRef() == 0)
		{
			mDeletor(mPtr);
			mPtr = nullptr;
		}
	}
	T& operator*()
	{
		return *mPtr;
	}
	T* operator->()
	{
		return mPtr;
	}

	Shared_ptr(const Shared_ptr<T>& src)
		:mPtr(src.mPtr),mpRefCnt(src.mpRefCnt)
	{
		if (mPtr != nullptr)
		{
			mpRefCnt->addRef();
		}
	}

	Shared_ptr& operator=(const Shared_ptr<T>& src)
	{
		if (this == &src)
		{
			return *this;
		}

		if (mpRefCnt->deleRef() == 0)
		{
			mDeletor(mPtr);
			mPtr = nullptr;
		}
		mPtr = src.mPtr;
		mpRefCnt = src.mpRefCnt;
		mpRefCnt->addRef();
		return *this;
	}

private:
	T* mPtr;
	RefCnt<T>* mpRefCnt;
	Deletor mDeletor;
};

int main()
{
	Shared_ptr<int> p1(new int(10));
	Shared_ptr<int> p2 = p1;
	Shared_ptr<int> p3;
	p3 = p1;
	*p1 = 20;
	cout << *p2 << " " << *p3 << endl;

	return 0;
}