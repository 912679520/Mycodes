
#include<iostream>
#include<string>
#include<memory>
#include<unordered_map>
#include<thread>
#include<mutex>
#include<list>

using namespace std;

//�۲���ģʽ
class Subject;//֪ͨ��
class Observer//����۲���
{
protected:
	string name;
	Subject* sub;
public:
	Observer(string na, Subject* s) :name(na), sub(s) {}
	virtual ~Observer() {}
	virtual void updata() = 0;
};
//����۲���
class StockObserver :public Observer
{
public:
	StockObserver(string na, Subject* sub) :Observer(na,sub) {}
	void updata();
};

class NBAObserver :public Observer
{
public:
	NBAObserver(string na, Subject* sub) :Observer(na, sub) {}
	void updata();
};

//֪ͨ��
class Subject
{
protected:
	list<Observer*> observers;
public:
	string event;
	virtual void attach(Observer*) = 0;
	virtual void detach(Observer*) = 0;
	virtual void notify() = 0;
};

class Secretary : public Subject
{
public:
	void attach(Observer* obs)
	{
		observers.push_back(obs);
	}
	void detach(Observer* obs)
	{
		observers.remove(obs);
	}
	void notify()
	{
		for (auto& x : observers)
		{
			x->updata();
		}
	}
};

void StockObserver::updata()
{
	cout << name << "�յ���" << sub->event << endl;
	if (sub->event == "Boss ���ˣ�")
	{
		cout << "���Ϲرճ��������װ���湤��" << endl;
	}
}

void NBAObserver::updata()
{
	cout << name << "�յ���" << sub->event << endl;
	if (sub->event == "Boss ���ˣ�")
	{
		cout << "���Ϲر�NBA��װ���湤��" << endl;
	}
}

int main()
{
	Subject* dwq = new Secretary();
	Observer* xs = new NBAObserver("С��",dwq);
	Observer* lm = new NBAObserver("����", dwq);
	Observer* wf = new StockObserver("����",dwq);

	dwq->attach(xs);
	dwq->attach(lm);
	dwq->attach(wf);

	dwq->event = "ȥ�Է�";
	dwq->notify();
	cout << endl;

	dwq->event = "Boss ���ˣ�";
	dwq->detach(xs);
	dwq->notify();
	cout << endl;

}


#if 0
//����ģʽ
//ȷ�������Ψһ��
std::mutex g_mtx;
template<class T>
class Singleton
{
public:
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
protected:
	Singleton() {};
	virtual ~Singleton() {}
public:
	static T* instance()
	{
		static T *theInstance = nullptr;
		if (theInstance == nullptr)
		{
			std::lock_guard<std::mutex> locker(g_mtx);
			theInstance = new T;
		}
		return theInstance;
	}
};

class MyClass :public Singleton<MyClass>
{
private:
	int value;
protected:
	friend class Singleton<MyClass>;
	MyClass(int x = 0) :value(x) {}
public:
	void SetValue(int x) { value = x; }
	int GetValue() const { return value; }
};

int main()
{
	MyClass* p = MyClass::instance();
	MyClass* s = MyClass::instance();

	cout << p << endl;
	cout << s << endl;
	return 0;
}


std::mutex g_mtx;
class Singleton
{
private:
	int value;

	Singleton(int x = 0) :value(x) {}
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	static Singleton* instance;
	
public:
	~Singleton() {}

	static Singleton* GetInsta()
	{
		if (instance == nullptr)
		{
			//�û�������������֤�̰߳�ȫ
			std::lock_guard<std::mutex> locker(g_mtx);
			instance = new Singleton(10);
		}
		return instance;
	}
};

Singleton* Singleton::instance = nullptr;


class Singleton
{
private:
	int value;

	Singleton(int x = 0) :value(x) {}
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

	static Singleton instance;
public:
	~Singleton() {}

	static Singleton& GetInsta()
	{
		return instance;
	}
};

int main()
{
	Singleton& s = Singleton::GetInsta();

	return 0;
}

//����ģʽ
class Singleton
{
private:
	int value;

	Singleton(int x = 0):value(x) {}
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	
	static Singleton instance;
public:
	~Singleton() {}
	static Singleton* GetInstance()
	{
		return &instance;
	}
	static Singleton& GetInsta()
	{
		return instance;
	}
};

Singleton Singleton::instance(10);

void funa()
{
	Singleton& p1 = Singleton::GetInsta();
	cout << &p1 << endl;
}

void funb()
{
	Singleton& p2 = Singleton::GetInsta();
	cout << &p2 << endl;
}

int main()
{
	thread t1(funa);
	thread t2(funb);
	t1.join();
	t2.join();
	return 0;
}


//��������
struct Logger
{
	virtual void writeLog() = 0;
	virtual ~Logger() {}
};

class DatabaseLogger :public Logger
{
public:
	DatabaseLogger() {}
	~DatabaseLogger() {}
	void writeLog() { cout << "���ݿ���־��¼��" << endl; }

};

class FileLogger :public Logger
{
public:
	FileLogger() {}
	~FileLogger() {}
	void writeLog() { cout << "�ļ���־��¼��" << endl; }
};

struct LoggerFactory
{
public:
	//virtual Logger* creatLogger() = 0;
	virtual unique_ptr<Logger> creatLogger() = 0;
};

class DatabaseLoggerFactory :public LoggerFactory
{
public:
	unique_ptr<Logger> creatLogger()
	{
		unique_ptr<Logger> logger = new DatabaseLogger();
		return logger;
	}
};

class FileLoggerFactory :public LoggerFactory
{
public:
	unique_ptr<Logger> creatLogger()
	{
		unique_ptr<Logger> log(new FileLogger());
		return log;
	}
};
int main()
{
	unique_ptr<LoggerFactory> up(new FileLoggerFactory());

	unique_ptr<Logger> plog(nullptr);
	
	plog = up->creatLogger();
	plog->writeLog();
	return 0;
}
#endif