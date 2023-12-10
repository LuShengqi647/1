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
	//�ļ�������
	ifstream ifs;
	ifs.open("file.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		//��ʼ��
		this->m_EmpNum = 0;
		this->m_FileIsEmpyt = true;
		this->m_EmpArray = NULL;
		ifs.close();
		return;
	}
	//�ļ����ڣ�����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��" << endl;
		this->m_EmpArray = NULL;
		this->m_EmpNum = 0;
		this->m_FileIsEmpyt = true;
		ifs.close();
		return;
	}
	//�ļ����ڣ����ݲ�Ϊ��
	    int num = this->get_EmpNum();
	    this->m_EmpNum = num;;
		this->m_EmpArray = new worker * [this->m_EmpNum];
		this->init_Emp();
}

void workerManager::showMenu()
{ 
	cout << "******************************" << endl;
	cout << "******* 0.�˳�������� *******" << endl;
	cout << "******* 1.����ְ����Ϣ *******" << endl;
	cout << "******* 2.��ʾְ����Ϣ *******" << endl;
	cout << "******* 3.ɾ����ְԱ�� *******" << endl;
	cout << "******* 4.�޸�ְ����Ϣ *******" << endl;
	cout << "******* 5.����Ա����Ϣ *******" << endl;
	cout << "******* 6.���ձ������ *******" << endl;
	cout << "******* 7.��������ĵ� *******" << endl;
	cout << "******************************" << endl;
	cout << endl;
}



void workerManager::Add_Emp()
{
	cout << "���������ְ��������" << endl;

	int AddNum = 0;
	cin >> AddNum;

	if (AddNum > 0)
	{
		int newSize = this->m_EmpNum + AddNum; //�¿ռ����� = ԭ����¼���� + ����������
		//�����¿ռ�
		worker** newspace = new worker * [newSize];
		//��ԭ���ռ������ݣ��������¿ռ���
		if (this->m_EmpArray != NULL)
		{ 
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newspace[i] = this->m_EmpArray[i];
			}
		}
		//���������
		for (int i = 0; i < AddNum; i++)
		{
			int id;
			string name;
			int dSelect;
			cout << "�������" << i + 1 << "����ְ����ţ�" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "����ְ��������" << endl;
			cin >> name;
			cout << "��ѡ���" << i + 1 << "����ְ����λ��" << endl;
			cout << "1.Ա����2.����3.�ϰ�" << endl;
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
			//������ְ��ָ�뱣�浽������
			newspace[this->m_EmpNum + i] = worker;
		}
		
		//�ͷ�ԭ�пռ�
		delete[] this->m_EmpArray;
		//�����¿ռ�ָ��
		this->m_EmpArray = newspace;
		//�����µ�ְ������
		this->m_EmpNum = newSize;
		cout << "��ӳɹ�" << endl;
		this->save();
		cout << "�ɹ����" << AddNum << "����ְ����" << endl;
		this->m_FileIsEmpyt = false;
	}
	else
	{
		cout << "��������" << endl;
	}
    //����������������ص��ϼ�Ŀ¼
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

void workerManager::showemp()    //��ʾְ��
{
	if (this->m_FileIsEmpyt)
		cout << "�ļ������ڻ��ļ�Ϊ��" << endl;
	
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

