#include"manger.h"

Manager::Manager(int id, string name, int dId)
{
	this->m_id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
void Manager::showInfo()//显示个人信息
{
	cout << "职工编号： " << this->m_id
		<< "\t职工姓名： " << this->m_Name
		<< "\t岗位： " << this->getDeptName()
		<< "\t岗位职责： 完成老板交代的任务，并且下发任务给普通员工" << endl;
}

string Manager::getDeptName()//获取岗位名称
{
	return string("经理");
}