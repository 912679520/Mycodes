#include<iostream>
#include"workerManager.h"
#include"boss.h"
#include"employee.h"
#include"manger.h"
using namespace std;

int main()
{
	//ʵ���������߶���
	WorkerManager wm;

	int choice = 0;
	while (true)
	{
		wm.Show_Menu();
		cout << "���������ѡ�� " << endl;
		cin >> choice;

		switch (choice)
		{
		case 0: //�˳�
			wm.exitSystem();
			break;
		case 1:	//����
			wm.Add_Emp();
			break;
		case 2:	//��ʾ
			wm.Show_Emp();
			break;
		case 3:	//ɾ��
			wm.Del_Emp();
			break;
		case 4:	//�޸�
			wm.Mod_Emp();
			break;
		case 5:	//����
			wm.Find_Emp();
			break;
		case 6:	//����
			wm.Sort_Emp();
			break;
		case 7:	//���
			wm.clean_File();
			break;
		default:
			system("cls");
			break;
		}
	}
	

	system("pause");

	return 0;
}