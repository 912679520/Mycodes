#include<iostream>
#include<string>

using namespace std;

#define Max 1000

//��ϵ�˽ṹ��
struct Person
{
	string m_Name;	//����
	int m_Sex;		//�Ա�  1����   2��Ů
	int m_Age;		//����
	string m_Phone;	//�绰
	string m_Addr;	//סַ
};

//ͨѶ¼�ṹ��
struct AddressBooks
{
	//ͨѶ¼������ϵ�˵�����
	struct Person personArray[Max];

	//ͨѶ¼�е�ǰ��¼��ϵ�˸���
	int m_size;
};

//�����ϵ��
void addPerson(AddressBooks* abs)
{
	//�ж�ͨ��¼�Ƿ������������
	if (abs->m_size == Max)
	{
		cout << "ͨѶ¼�������޷����" << endl;
	}
	else
	{
		//��Ӿ�����ϵ��

		//����
		string name;
		cout << "������������ " << endl;
		cin >> name;
		abs->personArray[abs->m_size].m_Name = name;
		
		//�Ա�
		cout << "�������Ա� " << endl;
		cout << "1----��" << endl;
		cout << "2----Ů" << endl;
		int sex = 0;

		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_size].m_Sex = sex;
				break;
			}
			cout << "������������������: " << endl;
		}		

		//����
		cout << "���������䣺 " << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_size].m_Age = age;

		//�绰
		cout << "��������ϵ�绰�� " << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_size].m_Phone = phone;

		//סַ
		cout << "�������ͥסַ�� " << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_size].m_Addr = address;

		//��������
		abs->m_size++;

		cout << "��ӳɹ�" << endl;

		system("pause");//�밴���������
		system("cls"); //����
	}
}

//��ʾ�˵�����
void showMenu()
{
	cout << "**************************" << endl;
	cout << "*******1�������ϵ��******" << endl;
	cout << "*******2����ʾ��ϵ��******" << endl;
	cout << "*******3��ɾ����ϵ��******" << endl;
	cout << "*******4��������ϵ��******" << endl;
	cout << "*******5���޸���ϵ��******" << endl;
	cout << "*******6�������ϵ��******" << endl;
	cout << "*******0���˳�ͨѶ¼******" << endl;
	cout << "**************************" << endl;
}

//��ʾ��ϵ��
void showPerson(AddressBooks* abs)
{
	if (abs->m_size == 0)
	{
		cout << "��ϵ��Ϊ�գ�" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "������ " << abs->personArray[i].m_Name <<"\t";
			cout << "�Ա� " << (abs->personArray[i].m_Sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺 " << abs->personArray[i].m_Age << "\t";
			cout << "�绰�� " << abs->personArray[i].m_Phone << "\t";
			cout << "סַ�� " << abs->personArray[i].m_Addr << endl;
		}
	}

	system("pause");
	system("cls");
}

//�����ϵ���Ƿ���ڣ����ڷ����±�
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

//ɾ����ϵ��
void deletePerson(AddressBooks* abs)
{
	cout << "������Ҫɾ������ϵ�ˣ� " << endl;

	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "û�и���ϵ�� " << endl;
	}
	else
	{
		for (int i = ret; i < abs->m_size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_size--;
		cout << "ɾ���ɹ�" << endl;
	}
	system("pause");
	system("cls");
}

//������ϵ��
void findPerson(AddressBooks* abs)
{
	cout << "������Ҫ���ҵ���ϵ�ˣ� " << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);

	if (ret != -1)
	{
		cout << "������ " << abs->personArray[ret].m_Name << "\t";
		cout << "�Ա� " << (abs->personArray[ret].m_Sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺 " << abs->personArray[ret].m_Age << "\t";
		cout << "�绰�� " << abs->personArray[ret].m_Phone << "\t";
		cout << "סַ�� " << abs->personArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "û�и���ϵ��" << endl;
	}
	system("pause");
	system("cls");
}

//�޸���ϵ��
void modifyPerson(AddressBooks* abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//����
		string name;
		cout << "������������ " << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		//�Ա�
		cout << "�������Ա� " << endl;
		cout << "1----��" << endl;
		cout << "2----Ů" << endl;
		int sex = 0;

		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "������������������: " << endl;
		}

		//����
		cout << "���������䣺 " << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		//�绰
		cout << "��������ϵ�绰�� " << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		//סַ
		cout << "�������ͥסַ�� " << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;

	}
	else
	{
		cout << "���޴���" << endl;
	}
}

//�����ϵ��
void cleanPerson(AddressBooks* abs)
{
	abs->m_size = 0;
	cout << "�����" << endl;
	system("pause");
	system("cls");
}

int main()
{
	//����ͨѶ¼�ṹ�����
	AddressBooks abs;
	//��ʼ��ͨѶ¼��ǰ��Ա����
	abs.m_size = 0;

	int select = 0; // �û�ѡ���������

	while (true)
	{
		//��ʾ�˵�
		showMenu();

		cout << "��ѡ�����Ĳ���: " << endl;
		cin >> select;
		switch (select)
		{
		case 1: //���
			addPerson(&abs);  //���õ�ַ���ݣ���������ʵ��
			break;
		case 2: //��ʾ
			showPerson(&abs);
			break;
		case 3: //ɾ��
			deletePerson(&abs);
			break;
		case 4: //����
			findPerson(&abs);
			break;
		case 5: //�޸�
			modifyPerson(&abs);
			break;
		case 6: //���
			cleanPerson(&abs);
			break;
		case 0: //�˳�
			cout << "��ӭ�´�ʹ��" << endl;
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