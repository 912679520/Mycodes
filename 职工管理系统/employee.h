#pragma once
#include<iostream>
#include"worker.h"
using namespace std;

//��ͨԱ��
class Employee :public Worker
{
public:
	virtual void showInfo();//��ʾ������Ϣ

	virtual string getDeptName();//��ȡ��λ����

	Employee(int id, string name, int dId);
};