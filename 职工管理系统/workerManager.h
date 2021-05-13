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

	void exitSystem(); //退出

	void Add_Emp(); //添加职工

	void save(); //保存文件

	int get_EmpNum(); //文件里面有多少员工

	void init_Emp(); //初始化员工

	void Show_Emp(); //显示员工

	int IsExist(int id); // 查找该员工是否存在

	void Del_Emp(); //删除员工

	void Mod_Emp(); //修改职工

	void Find_Emp(); //查找员工

	void Sort_Emp(); //排序

	void clean_File(); //清空

public:
	int m_EmpNum; //记录职工人数

	Worker** m_EmpArray; //职工数组指针

	bool m_FIleIsEmpty; //判断文件是否为空的标志
};