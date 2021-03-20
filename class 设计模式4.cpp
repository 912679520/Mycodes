
#include<iostream>
#include<string>
#include<memory>
#include<map>
#include<unordered_map>
#include<thread>
#include<mutex>
#include<queue>
using namespace std;

//������ģʽ
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
//����ģʽ
//�ӿ�,ֻ�д��麯����û��������

//Զ�̴���
//΢����ܹ�
struct UserMange//�û�����ϵͳ
{
	virtual bool Login(const string& name, const string& password);
};

class UserServer :public UserMange//��¼����
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
		//�ȴ��ͻ��˽�������
		//���ӳɹ�
		//��ȡ���ݣ������л�  //Login // name //password protbuff
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
		//���罨��
	}
	~UserManger_Stud()
	{
		//��������
	}

	bool Login(const string& name, const string& password)
	{
		//���л����ݣ��ύ��socket
		//�ȴ���������
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

//�������
struct Word
{
	virtual void transaction() = 0;
};

class Boss : public Word
{
private:
	std::queue<string> orders;//�ƻ���
public:
	Boss() { cout << "Boss ���֣�" << endl; }
	Boss(std::queue<string>& order) :orders(order)
	{
		cout << "Boss ���֣�" << endl;
	}
	void addOrder(const string& order) { orders.push(order); }
	void transaction()
	{
		while (!orders.empty())
		{
			string order = orders.front();
			orders.pop();
			cout << "Boss ����������"<<order << endl;
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
			cout << "���ֽ� <" << order << " >  ������ӵ��б�" << endl;
			orders.push(order);
		}
		else
		{
			cout << "Boss ���Խ� <" << order << " >  ������ӵ��б�" << endl;
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
	assistant->addOrder("��boss����");
	assistant->addOrder("��boss����");
	assistant->addOrder("��boss����");
	
	assistant->transaction();

	assistant->addOrder("��boss��Ǯ");
	assistant->addOrder("��boss�Ⱦ�");
	
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