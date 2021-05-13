#pragma once
#include<iostream>
#include"worker.h"
using namespace std;

//普通员工
class Employee :public Worker
{
public:
	virtual void showInfo();//显示个人信息

	virtual string getDeptName();//获取岗位名称

	Employee(int id, string name, int dId);
};