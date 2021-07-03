#include <iostream>
#include "Identity.h"
#include <fstream>
#include <string>
#include "globalFile.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"
using namespace std;

void teacherMenu(Identity*& teacher) {
	while (true) {
		teacher->operMenu();

		Teacher* tea = (Teacher*)teacher;

		int select = 0;
		cin >> select;

		if (select == 1) {
			tea->showAllOrder();
		}
		else if (select == 2) {
			tea->verifyOrder();
		}
		else {
			delete teacher;
			cout << "���\�n�X!" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void studentMenu(Identity*& student) {
	while (true) {
		student->operMenu();

		Student* stu = (Student*)student;

		int select = 0;
		cin >> select;

		if (select == 1) {
			stu->applyOrder();
		}
		else if (select == 2) {
			stu->showOrder();
		}
		else if (select == 3) {
			stu->showAllOrder();
		}
		else if (select == 4) {
			stu->cancelOrder();
		}
		else {
			delete student;
			cout << "���\�n�X!" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void managerMenu(Identity*& manager) {
	while (true) {
		manager->operMenu();

		Manager* man = (Manager*)manager;

		int select = 0;
		cin >> select;

		if (select == 1) {
			man->addPerson();
		}else if (select == 2) {
			man->showPerson();
		}else if (select == 3) {
			man->showComputer();
		}else if (select == 4) {
			man->cleanFile();
		}else {
			delete manager;
			cout << "���\�n�X!" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void LoginIn(string fileName, int type) {
	 
	Identity* person = NULL;

	ifstream ifs;
	ifs.open(fileName, ios::in);

	if (!ifs.is_open()) {
		return;
	}

	string id, name, pwd;

	if (type == 1) {
		cout << "�п�J�z���Ǹ�: " << endl;
		cin >> id;
	}else if (type == 2) {
		cout << "�п�J�z��¾�u��: " << endl;
		cin >> id;
	}

	cout << "�п�J�Τ�W: " << endl;
	cin >> name;
	cout << "�п�J�K�X: " << endl;
	cin >> pwd;

	string fId, fName, fPwd;
	if (type == 1) {
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "�ǥ͵n�J���\!" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				studentMenu(person);
				return;
			}
		}
	}else if (type == 2) {
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "�Юv�n�J���\!" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				teacherMenu(person);
				return;
			}
		}
	}else if (type == 3) {
		while (ifs >> fName && ifs >> fPwd) {
			if (fName == name && fPwd == pwd) {
				cout << "�޲z���n�J���\!" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				managerMenu(person);
				return;
			}
		}
	}

	cout << "��J���~�A�n�J����!" << endl;
	system("pause");
	system("cls");

	return;
}

int main() {
	char select = 0;

	while (true) {
		cout << "=================== �w��Ө�q���Ыǹw���t�� ==================="
			<< endl;
		cout << endl << "�п�J�z������" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t| 1.�� �� �N ��                 |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t| 2.�� �v                       |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t| 3.�� �z ��                    |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t| 0.�h �X                       |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "��J�z�����: ";

		cin >> select;

		switch (select)
		{
		case '1':
			LoginIn(STUDENT_FILE, 1);
			break;
		case '2':
			LoginIn(TEACHER_FILE, 2);
			break;
		case '3':
			LoginIn(ADMIN_FILE, 3);
			break;
		case '0':
			cout << "�w��U���ϥ�" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "��J���~�A�Э��s���!" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	
	

	system("pause");
	return 0;
}