#include <iostream>
#include "employee.h"
using namespace std;

employee::employee(int id,string name,int dId)
{  
	this->m_Id = id;
	this->m_Name = name;
	this->m_DepId = dId;
}

void employee::showInfo()
{
	cout << "职工编号： " << this->m_Id
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位：" << this->getDepName()
		<< "\t职责：完成经理交给的任务" << endl;
}

string employee::getDepName()
{
	return string("员工");
}
