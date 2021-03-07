#if 0
#include<iostream>
#include<string>
#include<vector>
#include<cstring>
using namespace std;



//增删改查、显示
class Student
{
private:
	string s_id;
	string s_name;
	string s_sex;
	int s_age;
public:
	Student() :s_age(0) {}
	Student(const string &id, const string &name, const string &sex, const int age)
		:s_id(id),s_name(name),s_sex(sex),s_age(age)
	{}
	~Student() {}

	string & Id() { return s_id; }
	const string& Id() const { return s_id; }

	string& Name() { return s_name; }
	const string& Name() const { return s_name; }

	string& Sex() { return s_sex; }
	const string& Sex() const { return s_sex; }

	int& Age() { return s_age; }
	const int& Age() const { return s_age; }

	ostream& operator<<(ostream& out) const
	{
		out << s_id <<" "<< s_name<<" " << s_sex<<" " << s_age;
		return out;
	}
};

class StudManage
{
	std::vector<Student> studdata;
	typename std::vector<Student>::iterator cur;
public:
	StudManage() {}
	~StudManage() {}

	void Add_Student(const Student& s)
	{
		studdata.push_back(s);
	}

	/*void Updata_Student(const Student& s, string name,string sex, int age) const
	{
		cur->Name() = name;
		cur->Sex() = sex;
		cur->Age() = age;
	}*/
	void Print_Student() const
	{
		cout << "output 学生信息" << endl;
		for (auto const &x:studdata)
		{
			x << cout;
			cout << endl;
		}
		cout << endl;

		/*typename std::vector<Student>::const_iterator it = studdata.begin();
		for (; it != studdata.end();++it)
		{
			cout << it->Id() << " " << it->Name() << " " << it->Sex() << " " << it->Age() << endl;
		}
		cout << endl;*/
	}

	bool Find_Id(const string& id)
	{
		bool res = false;
		cur = studdata.begin();
		for (; cur != studdata.end();++cur)
		{
			if (cur->Id() == id)
			{
				cout << "查询成功" << endl;
				res = true;
				break;
			}
		}
		return res;
	}

	bool Del_Student_Id(const string& id)
	{
		bool res = Find_Id(id);
		if (res)
		{
			studdata.erase(cur);
			cur = studdata.end();
		}
		return res;
	}
};

void Add(StudManage& studMan)
{
	string id, name, sex;
	int age;
	char ch;
	do
	{
		cout << "请输入学生： " << endl;
		cin >> id >> name >> sex >> age;
		Student s(id, name, sex, age);
		studMan.Add_Student(s);
		cout << "是否继续（N/Y）" << endl;
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	cout << "添加完毕" << endl;
}

//void Updata(StudManage& studMan)
//{
//	string id, name, sex;
//	int id;
//	char ch;
//	cout << "请输入学号：" << endl;
//	cin >> id;
//
//}

bool Find_Student(StudManage& studMan)
{
	string id;
	cout << "input student id: " << endl;
	cin >> id;
	return studMan.Find_Id(id);
}

bool Del_Student(StudManage& studMan)
{
	string id;
	cout << "input del student id: " << endl;
	return studMan.Del_Student_Id(id);
}

int MenuStudent()
{
	int pos;
	cout << "******************************************" << endl<<endl;
	cout << "*1 Add                              2 Print" << endl;
	cout << "*3 Find                             4 Del" << endl;
	cout << "*5 Updata                           0 Exit " << endl<<endl;
	cout << "******************************************" << endl<<endl;
	cout << "请选择" << endl;
	cin >> pos;
	return pos;
}
int main()
{
	StudManage studMan;
	int pos = 0;
	do
	{
		pos = MenuStudent();
		switch (pos)
		{
		case 0:cout << "退出"<<endl;
		case 1:Add(studMan);break;
		case 2:studMan.Print_Student();break;
		case 3:
			if (Del_Student(studMan))
			{
				cout << "删除成功！" << endl;
			}
			else
			{
				cout << "删除失败！" << endl;
			}
		case 4:
			if (Del_Student(studMan))
			{
				cout << "删除成功！" << endl;
			}
			else
			{
				cout << "删除失败！" << endl;
			}
		default:
			cout << "选择错误！" << endl;
		}
	} while (pos != 0);

	studMan.Print_Student();

	return 0;
}
#endif
