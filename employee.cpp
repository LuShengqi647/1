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
	cout << "ְ����ţ� " << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << this->getDepName()
		<< "\tְ����ɾ�����������" << endl;
}

string employee::getDepName()
{
	return string("Ա��");
}
