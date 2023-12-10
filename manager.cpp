#include "manager.h"
#include <iostream>
using namespace std;

manager::manager(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DepId = did;
}

void manager::showInfo()
{
	cout << "职工编号： " << this->m_Id
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位：" << this->getDepName()
		<< "\t职责：完成老板交给的任务，并下放任务给员工" << endl;
}

string manager::getDepName()
{
	return string("经理");
}
