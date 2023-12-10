#pragma once
#include <iostream>
using namespace std;
#include <string>

class worker
{
public:
	virtual void showInfo() = 0;     //显示个人信息
	virtual string getDepName() = 0; //获取岗位名称

	int m_Id;
	string m_Name;
	int m_DepId;
};