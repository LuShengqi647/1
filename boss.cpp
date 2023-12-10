#include "boss.h"
#include <iostream>
using namespace std;

boss::boss(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DepId = did;
}

void boss::showInfo()
{
	cout << "职工编号： " << this->m_Id
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位：" << this->getDepName()
		<< "\t职责：管理公司所以事务" << endl;
}

string boss::getDepName()
{
	return string("总裁");
}
