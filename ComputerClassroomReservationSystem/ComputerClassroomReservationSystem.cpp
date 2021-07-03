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
			cout << "成功登出!" << endl;
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
			cout << "成功登出!" << endl;
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
			cout << "成功登出!" << endl;
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
		cout << "請輸入您的學號: " << endl;
		cin >> id;
	}else if (type == 2) {
		cout << "請輸入您的職工號: " << endl;
		cin >> id;
	}

	cout << "請輸入用戶名: " << endl;
	cin >> name;
	cout << "請輸入密碼: " << endl;
	cin >> pwd;

	string fId, fName, fPwd;
	if (type == 1) {
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "學生登入成功!" << endl;
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
				cout << "教師登入成功!" << endl;
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
				cout << "管理員登入成功!" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				managerMenu(person);
				return;
			}
		}
	}

	cout << "輸入有誤，登入失敗!" << endl;
	system("pause");
	system("cls");

	return;
}

int main() {
	char select = 0;

	while (true) {
		cout << "=================== 歡迎來到電腦教室預約系統 ==================="
			<< endl;
		cout << endl << "請輸入您的身份" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t| 1.學 生 代 表                 |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t| 2.老 師                       |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t| 3.管 理 員                    |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t| 0.退 出                       |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "輸入您的選擇: ";

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
			cout << "歡迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "輸入錯誤，請重新選擇!" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	
	

	system("pause");
	return 0;
}