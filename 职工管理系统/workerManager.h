#pragma once

#include<iostream>
#include<fstream>
#include"worker.h"
#include"boss.h"
#include"employee.h"
#include"manger.h"

using namespace std;

#define FILENAME "empFile.txt"

class WorkerManager
{
public:
	WorkerManager();

	~WorkerManager();

	void Show_Menu();

	void exitSystem(); //�˳�

	void Add_Emp(); //���ְ��

	void save(); //�����ļ�

	int get_EmpNum(); //�ļ������ж���Ա��

	void init_Emp(); //��ʼ��Ա��

	void Show_Emp(); //��ʾԱ��

	int IsExist(int id); // ���Ҹ�Ա���Ƿ����

	void Del_Emp(); //ɾ��Ա��

	void Mod_Emp(); //�޸�ְ��

	void Find_Emp(); //����Ա��

	void Sort_Emp(); //����

	void clean_File(); //���

public:
	int m_EmpNum; //��¼ְ������

	Worker** m_EmpArray; //ְ������ָ��

	bool m_FIleIsEmpty; //�ж��ļ��Ƿ�Ϊ�յı�־
};