#include <iostream>
#include <fstream>
using namespace std;
#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "boss.h"
#include "manager.h"

 int main()
{
	int choice=0;
	workerManager wm;
	while (true) {
		wm.showMenu();
		cout << "���������ѡ��:" << endl;
		cin>>choice;
		switch (choice)
		{
		case 0: cout << "ϵͳ�ɹ��˳�" << endl;
			    system("pause");  return 0;  break;
		case 1: wm.Add_Emp();
			break;
		case 2: wm.showemp();
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		}
		 
	}
	system("pause");
	return 0;
}