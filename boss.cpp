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
	cout << "ְ����ţ� " << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << this->getDepName()
		<< "\tְ�𣺹���˾��������" << endl;
}

string boss::getDepName()
{
	return string("�ܲ�");
}
