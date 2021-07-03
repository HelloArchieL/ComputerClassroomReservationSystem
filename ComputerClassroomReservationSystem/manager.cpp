#include "manager.h"

Manager::Manager() {

}

Manager::Manager(string name, string pwd) {
	this->m_Name = name;
	this->m_Pwd = pwd;

	this->initVector();
}

void Manager::operMenu() {
	cout << "歡迎管理員： " << this->m_Name << " 登錄！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t| 1.新增帳號                       |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t| 2.查看帳號                       |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t| 3.查看電腦教室                   |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t| 4.清空預約                       |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t| 0.登出                           |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "請選擇您的操作： " << endl;
}

void Manager::addPerson() {
	cout << "請輸入新增帳號的類型" << endl;
	cout << "1.新增學生" << endl;
	cout << "2.新增老師" << endl;

	string fileName, tip;
	ofstream ofs;

	int select = 0;
	cin >> select;

	if (select == 1) {
		fileName = STUDENT_FILE;
		tip = "請輸入學號： ";
	}
	else {
		fileName = TEACHER_FILE;
		tip = "請輸入職工編號： ";
	}

	ofs.open(fileName, ios::out | ios::app);

	string id, name, pwd;

	cout << tip << endl;
	while (true) {
		cin >> id;
		bool ret = this->checkRepeat(id, select);
		if (ret) {
			cout << "已使用，請重新輸入: " << endl;
		}
		else {
			break;
		}
	}
	

	cout << "請輸入姓名： " << endl;
	cin >> name;

	cout << "請輸入密碼： " << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << endl;
	cout << "新增成功!" << endl;

	system("pause");
	system("cls");

	ofs.close();
	this->initVector();
}

void Manager::showPerson() {
	cout << "請選擇查看內容：" << endl;
	cout << "1.查看所有學生" << endl;
	cout << "2.查看所有教師" << endl;

	int select = 0;
	cin >> select;

	if (select == 1) {
		cout << "所有學生資料如下： " << endl;
		for (int i = 0; i < this->vStu.size(); i++) {
			cout << "學號： " << this->vStu[i].m_Id << " 姓名： " << this->vStu[i].m_Name << endl;
		}
	}
	else {
		cout << "所有教師資料如下： " << endl;
		for (int i = 0; i < this->vTea.size(); i++) {
			cout << "職工號： " << this->vTea[i].m_EmpId << " 姓名： " << this->vTea[i].m_Name << endl;
		}
	}
	system("pause");
	system("cls");
}

void Manager::showComputer() {
	cout << "電腦教室資料如下: " << endl;
	for (int i = 0; i < this->vCom.size(); i++) {
		cout << "電腦教室 " << this->vCom[i].m_ComId << " 能容納的最大人數： " << this->vCom[i].m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

void Manager::cleanFile() {
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "清空成功!" << endl;
	system("pause");
	system("cls");
}

void Manager::initVector() {
	this->vStu.clear();
	this->vTea.clear();
	this->vCom.clear();

	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		return;
	}

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd) {
		this->vStu.push_back(s);
	}
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open()) {
		return;
	}

	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd) {
		this->vTea.push_back(t);
	}
	ifs.close();


	ifs.open(COMPUTER_FILE, ios::in);
	if (!ifs.is_open()) {
		return;
	}

	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum) {
		this->vCom.push_back(c);
	}
	ifs.close();
	

}

bool Manager::checkRepeat(string id, int type) {
	if (type == 1) {
		for (int i = 0; i < this->vStu.size(); i++) {
			if (id == this->vStu[i].m_Id)
				return true;
		}
	}
	else {
		for (vector<Teacher>::iterator it = this->vTea.begin(); it != this->vTea.end(); it++) {
			if (id == it->m_EmpId)
				return true;
		}
	}

	return false;
}