
#include<iostream>
#include<string>
#include<memory>
#include<map>
#include<unordered_map>
#include<thread>
#include<mutex>
#include<queue>
using namespace std;

//适配器模式
class Target
{
public:
	virtual void request() { cout << "Targer::request:" << endl; }
};

class Adaptee
{
public:
	virtual void SepcificRequest() { cout << "Adaptee::SpecificRequest" << endl; }
};

class Adapter :public Target
{
private:
	Adaptee* adaptee;
public:
	Adapter() : adaptee(new Adaptee()) {}
	void requset()
	{
		adaptee->SepcificRequest();
	}
};

int main()
{
	Target* target = new Adapter();
	target->request();

	return 0;
}


#if 0
//代理模式
//接口,只有纯虚函数，没有其他。

//远程代理
//微服务架构
struct UserMange//用户管理系统
{
	virtual bool Login(const string& name, const string& password);
};

class UserServer :public UserMange//登录服务
{
	//Mysql
public:
	UserServer() {}
	~UserServer() {}

	bool Login(const string& name, const string& password)
	{
		//
		return true;
	}
};

class User_Skeleton
{
private:
	UserMange* myServer;
public:
	User_Skeleton(UserMange* server)
	{
		this->myServer = server;
	}
	void run()
	{
		//等待客户端建立连接
		//连接成功
		//获取数据，反序列化  //Login // name //password protbuff
		string name = "liangxuan";
		string password = "123456";
		bool tag = myServer->Login(name, password);
	}
};

int main()
{
	UserMange* user = new UserServer();
	User_Skeleton* skel = new User_Skeleton(user);
	skel->run();

	return 0;
}

///////////////////
//-client

class UserManger_Stud :public UserMange
{
private:
	//socket
public:
	UserManger_Stud()
	{
		//网络建立
	}
	~UserManger_Stud()
	{
		//网络销毁
	}

	bool Login(const string& name, const string& password)
	{
		//序列化数据，提交给socket
		//等待返回数据
		bool res = true;
		return res;
	}
};

int main()
{
	UserMange* user = new UserManger_Stud();
	string  name, password;
	cin >> name >> password;
	user->Login(name, password);
	return 0;
}

//虚拟代理
struct Word
{
	virtual void transaction() = 0;
};

class Boss : public Word
{
private:
	std::queue<string> orders;//计划书
public:
	Boss() { cout << "Boss 出现：" << endl; }
	Boss(std::queue<string>& order) :orders(order)
	{
		cout << "Boss 出现：" << endl;
	}
	void addOrder(const string& order) { orders.push(order); }
	void transaction()
	{
		while (!orders.empty())
		{
			string order = orders.front();
			orders.pop();
			cout << "Boss 处理了任务："<<order << endl;
		}
	}
};

class Assistant : public Word
{
private:
	std::queue<string> orders;
	Boss* boss;
public:
	Assistant() :boss(nullptr) {}
	void addOrder(const string& order)
	{
		if (boss == nullptr)
		{
			cout << "助手将 <" << order << " >  任务添加到列表" << endl;
			orders.push(order);
		}
		else
		{
			cout << "Boss 亲自将 <" << order << " >  任务添加到列表" << endl;
			boss->addOrder(order);
		}
	}
	void transaction()
	{
		inviteBoss();
		boss->transaction();
	}
private:
	void inviteBoss()
	{
		if (boss == nullptr)
		{
			boss = new Boss(orders);
		}
	}
};

int main()
{
	Assistant* assistant = new Assistant();
	assistant->addOrder("找boss面试");
	assistant->addOrder("找boss审批");
	assistant->addOrder("找boss聊天");
	
	assistant->transaction();

	assistant->addOrder("找boss借钱");
	assistant->addOrder("找boss喝酒");
	
	assistant->transaction();
}

struct Subject
{
	virtual void request() = 0;
};

class RealSubject :public Subject
{
public:
	void request()
	{
		cout << "RealSubject::request" << endl;
	}
};

class Proxy :public Subject
{
private:
	RealSubject* realSubject;
public:
	Proxy() :realSubject(new RealSubject()) {}

	void preRequest() { cout << "pre" << endl; }
	void postRequest() { cout << "post" << endl; }
	void request()
	{
		preRequest();
		realSubject->request();
		postRequest();
	}
};

int main()
{
	Subject* sub = new Proxy;
	sub->request();

	return 0;
}
#endif