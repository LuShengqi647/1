#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void showMenu()
{
	cout << "**************************" << endl;
	cout << "***** 1.����û����� *****" << endl;
	cout << "***** 2.��ʾ��ϵ��   *****" << endl;
	cout << "***** 3.ɾ����ϵ��   *****" << endl;
	cout << "***** 4.������ϵ��   *****" << endl;
	cout << "***** 5.�޸���ϵ��   *****" << endl;
	cout << "***** 6.�����ϵ��   *****" << endl;
	cout << "***** 0.�˳��˵�     *****" << endl;
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
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else
	{
		string name;
		cout << "�������û�����:";
		cin >> name;
		abs->personArray[abs->m_size].m_name = name; 

		cout << "�������Ա�1--�У�2--Ů" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_size].m_sex = sex;
				break;
			}
			else cout << "������������������" << endl;
		}

		cout << "����������: " << endl;
		int age = 0;
		cin>>age;
		abs->personArray[abs->m_size].m_age = age;

		cout << "��������: " << endl;
		string number;
		cin >> number;
		abs->personArray[abs->m_size].m_number = number;
	}
	abs->m_size++;
	cout << "��ӳɹ�" << endl;
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
		case 1:  Addperson(&abs);//���õ�ַ���ݿ����޸�ʵ��
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
		case 0: cout << "�˳�ϵͳ�ɹ�" << endl;
			system("pause");
			return 0;
			break;
		}
	}
	system("pause");
	return 0;
}

