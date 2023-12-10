#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void showMenu()
{
	cout << "**************************" << endl;
	cout << "***** 1.添加用户数据 *****" << endl;
	cout << "***** 2.显示联系人   *****" << endl;
	cout << "***** 3.删除联系人   *****" << endl;
	cout << "***** 4.查找联系人   *****" << endl;
	cout << "***** 5.修改联系人   *****" << endl;
	cout << "***** 6.清空联系人   *****" << endl;
	cout << "***** 0.退出菜单     *****" << endl;
	cout << "**************************" << endl;
}

struct Person 
{
	string m_name;
	int m_sex;//1 man,2 woman
	int m_age;
	string m_number;
};

struct AddressBooks
{
	struct Person personArray[1000];
	int m_size;
};

void Addperson(AddressBooks * abs)
{  
	if (abs->m_size == 1000)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else
	{
		string name;
		cout << "请输入用户名称:";
		cin >> name;
		abs->personArray[abs->m_size].m_name = name; 

		cout << "请输入性别，1--男，2--女" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_size].m_sex = sex;
				break;
			}
			else cout << "输入有误请重新输入" << endl;
		}

		cout << "请输入年龄: " << endl;
		int age = 0;
		cin>>age;
		abs->personArray[abs->m_size].m_age = age;

		cout << "请输入编号: " << endl;
		string number;
		cin >> number;
		abs->personArray[abs->m_size].m_number = number;
	}
	abs->m_size++;
	cout << "添加成功" << endl;
	system("pause");
	system("cls");
}

int main()
{   
	int select = 0;
	AddressBooks abs;
	abs.m_size = 0;
	while (true) {
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1:  Addperson(&abs);//利用地址传递可以修改实参
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 0: cout << "退出系统成功" << endl;
			system("pause");
			return 0;
			break;
		}
	}
	system("pause");
	return 0;
}

