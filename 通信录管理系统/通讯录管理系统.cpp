#include<iostream>
#include<string>

using namespace std;

#define Max 1000

//联系人结构体
struct Person
{
	string m_Name;	//姓名
	int m_Sex;		//性别  1、男   2、女
	int m_Age;		//年龄
	string m_Phone;	//电话
	string m_Addr;	//住址
};

//通讯录结构体
struct AddressBooks
{
	//通讯录保存联系人的数组
	struct Person personArray[Max];

	//通讯录中当前记录联系人个数
	int m_size;
};

//添加联系人
void addPerson(AddressBooks* abs)
{
	//判断通信录是否满，满不添加
	if (abs->m_size == Max)
	{
		cout << "通讯录已满，无法添加" << endl;
	}
	else
	{
		//添加具体联系人

		//姓名
		string name;
		cout << "请输入姓名： " << endl;
		cin >> name;
		abs->personArray[abs->m_size].m_Name = name;
		
		//性别
		cout << "请输入性别： " << endl;
		cout << "1----男" << endl;
		cout << "2----女" << endl;
		int sex = 0;

		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_size].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入: " << endl;
		}		

		//年龄
		cout << "请输入年龄： " << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_size].m_Age = age;

		//电话
		cout << "请输入联系电话： " << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_size].m_Phone = phone;

		//住址
		cout << "请输入家庭住址： " << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_size].m_Addr = address;

		//更新人数
		abs->m_size++;

		cout << "添加成功" << endl;

		system("pause");//请按任意键继续
		system("cls"); //清屏
	}
}

//显示菜单界面
void showMenu()
{
	cout << "**************************" << endl;
	cout << "*******1、添加联系人******" << endl;
	cout << "*******2、显示联系人******" << endl;
	cout << "*******3、删除联系人******" << endl;
	cout << "*******4、查找联系人******" << endl;
	cout << "*******5、修改联系人******" << endl;
	cout << "*******6、清空联系人******" << endl;
	cout << "*******0、退出通讯录******" << endl;
	cout << "**************************" << endl;
}

//显示联系人
void showPerson(AddressBooks* abs)
{
	if (abs->m_size == 0)
	{
		cout << "联系人为空：" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "姓名： " << abs->personArray[i].m_Name <<"\t";
			cout << "性别： " << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
			cout << "年龄： " << abs->personArray[i].m_Age << "\t";
			cout << "电话： " << abs->personArray[i].m_Phone << "\t";
			cout << "住址： " << abs->personArray[i].m_Addr << endl;
		}
	}

	system("pause");
	system("cls");
}

//检测联系人是否存在，存在返回下标
int isExist(AddressBooks *abs, string name)
{
	for (int i = 0; i < abs->m_size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;
}

//删除联系人
void deletePerson(AddressBooks* abs)
{
	cout << "请输入要删除的联系人： " << endl;

	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "没有该联系人 " << endl;
	}
	else
	{
		for (int i = ret; i < abs->m_size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_size--;
		cout << "删除成功" << endl;
	}
	system("pause");
	system("cls");
}

//查找联系人
void findPerson(AddressBooks* abs)
{
	cout << "请输入要查找的联系人： " << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);

	if (ret != -1)
	{
		cout << "姓名： " << abs->personArray[ret].m_Name << "\t";
		cout << "性别： " << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
		cout << "年龄： " << abs->personArray[ret].m_Age << "\t";
		cout << "电话： " << abs->personArray[ret].m_Phone << "\t";
		cout << "住址： " << abs->personArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "没有该联系人" << endl;
	}
	system("pause");
	system("cls");
}

//修改联系人
void modifyPerson(AddressBooks* abs)
{
	cout << "请输入您要修改的联系人" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//姓名
		string name;
		cout << "请输入姓名： " << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		//性别
		cout << "请输入性别： " << endl;
		cout << "1----男" << endl;
		cout << "2----女" << endl;
		int sex = 0;

		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入: " << endl;
		}

		//年龄
		cout << "请输入年龄： " << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		//电话
		cout << "请输入联系电话： " << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		//住址
		cout << "请输入家庭住址： " << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;

	}
	else
	{
		cout << "查无此人" << endl;
	}
}

//清空联系人
void cleanPerson(AddressBooks* abs)
{
	abs->m_size = 0;
	cout << "已清空" << endl;
	system("pause");
	system("cls");
}

int main()
{
	//创建通讯录结构体变量
	AddressBooks abs;
	//初始化通讯录当前人员个数
	abs.m_size = 0;

	int select = 0; // 用户选择输入变量

	while (true)
	{
		//显示菜单
		showMenu();

		cout << "请选择您的操作: " << endl;
		cin >> select;
		switch (select)
		{
		case 1: //添加
			addPerson(&abs);  //利用地址传递，可以修饰实参
			break;
		case 2: //显示
			showPerson(&abs);
			break;
		case 3: //删除
			deletePerson(&abs);
			break;
		case 4: //查找
			findPerson(&abs);
			break;
		case 5: //修改
			modifyPerson(&abs);
			break;
		case 6: //清空
			cleanPerson(&abs);
			break;
		case 0: //退出
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	

	system("pause");
	return 0;
}