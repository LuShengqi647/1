#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "worker.h"
using namespace std;

class workerManager
{
public:
	workerManager();

	void showMenu();

	int m_EmpNum;

	worker ** m_EmpArray;

	void Add_Emp();

	void save();

	//�ж��ļ��Ƿ�Ϊ��
	bool m_FileIsEmpyt;

	int get_EmpNum(); 

	void  init_Emp();

	void showemp();

	~workerManager();
};