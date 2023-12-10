#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

workerManager::workerManager()
{
	//文件不存在
	ifstream ifs;
	ifs.open("file.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		//初始化
		this->m_EmpNum = 0;
		this->m_FileIsEmpyt = true;
		this->m_EmpArray = NULL;
		ifs.close();
		return;
	}
	//文件存在，数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空" << endl;
		this->m_EmpArray = NULL;
		this->m_EmpNum = 0;
		this->m_FileIsEmpyt = true;
		ifs.close();
		return;
	}
	//文件存在，数据不为空
	    int num = this->get_EmpNum();
	    this->m_EmpNum = num;;
		this->m_EmpArray = new worker * [this->m_EmpNum];
		this->init_Emp();
}

void workerManager::showMenu()
{ 
	cout << "******************************" << endl;
	cout << "******* 0.退出管理程序 *******" << endl;
	cout << "******* 1.增加职工信息 *******" << endl;
	cout << "******* 2.显示职工信息 *******" << endl;
	cout << "******* 3.删除离职员工 *******" << endl;
	cout << "******* 4.修改职工信息 *******" << endl;
	cout << "******* 5.查找员工信息 *******" << endl;
	cout << "******* 6.按照编号排序 *******" << endl;
	cout << "******* 7.清空所有文档 *******" << endl;
	cout << "******************************" << endl;
	cout << endl;
}



void workerManager::Add_Emp()
{
	cout << "请输入添加职工的数量" << endl;

	int AddNum = 0;
	cin >> AddNum;

	if (AddNum > 0)
	{
		int newSize = this->m_EmpNum + AddNum; //新空间人数 = 原来记录人数 + 新增人数；
		//开辟新空间
		worker** newspace = new worker * [newSize];
		//将原来空间下数据，拷贝到新空间下
		if (this->m_EmpArray != NULL)
		{ 
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newspace[i] = this->m_EmpArray[i];
			}
		}
		//添加新数据
		for (int i = 0; i < AddNum; i++)
		{
			int id;
			string name;
			int dSelect;
			cout << "请输入第" << i + 1 << "个新职工编号：" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工姓名：" << endl;
			cin >> name;
			cout << "请选择第" << i + 1 << "个新职工岗位：" << endl;
			cout << "1.员工，2.经理，3.老板" << endl;
			cin >> dSelect;

			worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new employee(id, name, 1);
				break;
			case 2:
				worker = new manager(id, name, 2);
				break;
			case 3:
				worker = new boss(id, name, 3);
				break;
			default : 
				break;
			}
			//将创建职工指针保存到数组中
			newspace[this->m_EmpNum + i] = worker;
		}
		
		//释放原有空间
		delete[] this->m_EmpArray;
		//更改新空间指向
		this->m_EmpArray = newspace;
		//更新新的职工人数
		this->m_EmpNum = newSize;
		cout << "添加成功" << endl;
		this->save();
		cout << "成功添加" << AddNum << "名新职工！" << endl;
		this->m_FileIsEmpyt = false;
	}
	else
	{
		cout << "数据有误" << endl;
	}
    //按任意键后清屏，回到上级目录
	//system("pause");
	//system("cls");
}

void workerManager::save()
{
	ofstream ofs;
	ofs.open("file.txt", ios::out);

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name <<" "
			<< this->m_EmpArray[i]->m_DepId << endl;
	}
	ofs.close();
}

int workerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open("file.txt", ios::in);
		int num = 0;
	int id;
	string name;
	int did;
	while (ifs >> id && ifs >> name && ifs >> did)
		num++;
	ifs.close();
	return num;
}

void workerManager::init_Emp()
{
	ifstream ifs;
	ifs.open("file.text", ios::in);
	int id;
	string name;
	int did;
	int index = 0;

	while (ifs >> id && ifs >> name && ifs >> did)
	{
		worker* worker = NULL;
		if (did == 1)
		{
			worker = new employee(id, name, did);
		}
		else if(did == 2)
		{
			worker = new manager(id, name, did);
		}
		else
		{
			worker = new boss(id, name, did);
		}
		m_EmpArray[index] = worker;
		index++;
	}
}

void workerManager::showemp()    //显示职工
{
	if (this->m_FileIsEmpyt)
		cout << "文件不存在或文件为空" << endl;
	
		for (int i = 0; i < m_EmpNum; i++)
			this->m_EmpArray[i]->showInfo();
	system("pause");
	system("cls");
}

workerManager::~workerManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}

