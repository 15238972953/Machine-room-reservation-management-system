#include<iostream>
using namespace std;
#include"Identity.h"
#include<fstream>
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"
#include<typeinfo>
int a;
//����ѧ���Ӳ˵�����
void studentMenu(Identity*& student)
{
	while (true)
	{
		//ѧ���˵�
		student->operMenu();

		Student* stu = (Student*)student;
		int select = 0;

		cin >> select;

		if (select == 1) //����ԤԼ
		{
			stu->applyOrder();
		}
		else if (select == 2) //�鿴����ԤԼ
		{
			stu->showMyOrder();
		}
		else if (select == 3) //�鿴����ԤԼ
		{
			stu->showAllOrder();
		}
		else if (select == 4) //ȡ��ԤԼ
		{
			stu->cancelOrder();
		}
		else
		{
			delete student;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//��ʦ�˵�
void TeacherMenu(Identity*& teacher)
{
	while (true)
	{
		//��ʦ�˵�
		teacher->operMenu();

		Teacher* tea = (Teacher*)teacher;
		int select = 0;

		cin >> select;

		if (select == 1)
		{
			//�鿴����ԤԼ
			tea->showAllOrder();
		}
		else if (select == 2)
		{
			//���ԤԼ
			tea->validOrder();
		}
		else
		{
			delete teacher;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//�������Ա�Ӳ˵�����
void managerMenu(Identity*& manager)
{
	while (true)
	{
		//���ù���Ա�Ӳ˵���
		manager->operMenu();
		Manager* man = (Manager*)manager;
		int select = 0;
		cin >> select;
		if (1 == select)//����˺�
		{
			cout << "����˺�" << endl;
			man->addPerson();
		}
		else if (2 == select)//�鿴�˺�
		{
			cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (3 == select)//�鿴����
		{
			cout << "�鿴����" << endl;
			man->showComputer();
		}
		else if (4 == select)//���ԤԼ
		{
			cout << "���ԤԼ" << endl;
			man->cleanFile();
		}
		else
		{
			//ע��
			delete manager; //���ٵ���������
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void LoginIn(string fileName, int type)
{
	Identity* person = NULL;

	ifstream ifs;
	ifs.open(fileName,ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}
	int id = 0;
	string name;
	string pwd;
	if (1 == type)
	{
		cout << "���������ѧ�ţ�" << endl;
		cin >> id;	
	}
	else if (2 == type)
	{
		cout << "���������ְ���ţ�" << endl;
		cin >> id;

	}
	cout << "�������û�����" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> pwd;

	if (1 == type)//ѧ�������֤
	{
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "ѧ����֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				studentMenu(person);
				return;
			}
		}
	}
	else if(2==type)//��ʦ�����֤
	{
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "��ʦ��֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//�����ʦ�Ӳ˵�
				TeacherMenu(person);
				return;
			}
		}
	}
	else if (3 == type)//����Ա�����֤
	{
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (name == fName && pwd == fPwd)
			{
				cout << "��֤��¼�ɹ�!" << endl;
				//��¼�ɹ��󣬰�������������Ա����
				system("pause");
				system("cls");
				//��������Ա����
				person = new Manager(name, pwd);
				managerMenu(person);
				return;
			}
		}
	}
	cout << "��֤��½ʧ�ܣ�" << endl;
	system("pause");
	system("cls");
	return;
}
int main() {
	int select;
	while (true)
	{
		cout << "======================  ��ӭ�������ǲ��ͻ���ԤԼϵͳ  ====================="
			<< endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.ѧ������           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.��    ʦ           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.�� �� Ա           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.��    ��           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "��������ѡ��: ";
		cin >> select;
		switch (select)
		{
		case 1:
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:
			cout << "��ӭ��һ��ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
}