#pragma once
//��ͨԱ���ļ�
#include <iostream>
#include "worker.h"
using namespace std;

class employee :public worker
{
public:

	employee(int id, string name, int dId);

	virtual void showInfo();

	virtual string getDepName();
};