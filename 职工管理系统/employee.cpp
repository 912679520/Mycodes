#include"employee.h"

Employee::Employee(int id, string name, int dId)
{
	this->m_id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

void Employee::showInfo()//显示个人信息
{
	cout << "职工编号： " << this->m_id
		<< "\t职工姓名： " << this->m_Name
		<< "\t岗位： " << this->getDeptName()
		<< "\t岗位职责： 完成经理交代的任务" << endl;
}

string Employee::getDeptName()//获取岗位名称
{
	return string("员工");
}


