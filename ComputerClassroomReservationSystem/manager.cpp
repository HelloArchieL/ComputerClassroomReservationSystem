#include "manager.h"

Manager::Manager() {

}

Manager::Manager(string name, string pwd) {
	this->m_Name = name;
	this->m_Pwd = pwd;

	this->initVector();
}

void Manager::operMenu() {
	cout << "�w��޲z���G " << this->m_Name << " �n���I" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t| 1.�s�W�b��                       |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t| 2.�d�ݱb��                       |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t| 3.�d�ݹq���Ы�                   |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t| 4.�M�Źw��                       |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t| 0.�n�X                           |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "�п�ܱz���ާ@�G " << endl;
}

void Manager::addPerson() {
	cout << "�п�J�s�W�b��������" << endl;
	cout << "1.�s�W�ǥ�" << endl;
	cout << "2.�s�W�Ѯv" << endl;

	string fileName, tip;
	ofstream ofs;

	int select = 0;
	cin >> select;

	if (select == 1) {
		fileName = STUDENT_FILE;
		tip = "�п�J�Ǹ��G ";
	}
	else {
		fileName = TEACHER_FILE;
		tip = "�п�J¾�u�s���G ";
	}

	ofs.open(fileName, ios::out | ios::app);

	string id, name, pwd;

	cout << tip << endl;
	while (true) {
		cin >> id;
		bool ret = this->checkRepeat(id, select);
		if (ret) {
			cout << "�w�ϥΡA�Э��s��J: " << endl;
		}
		else {
			break;
		}
	}
	

	cout << "�п�J�m�W�G " << endl;
	cin >> name;

	cout << "�п�J�K�X�G " << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << endl;
	cout << "�s�W���\!" << endl;

	system("pause");
	system("cls");

	ofs.close();
	this->initVector();
}

void Manager::showPerson() {
	cout << "�п�ܬd�ݤ��e�G" << endl;
	cout << "1.�d�ݩҦ��ǥ�" << endl;
	cout << "2.�d�ݩҦ��Юv" << endl;

	int select = 0;
	cin >> select;

	if (select == 1) {
		cout << "�Ҧ��ǥ͸�Ʀp�U�G " << endl;
		for (int i = 0; i < this->vStu.size(); i++) {
			cout << "�Ǹ��G " << this->vStu[i].m_Id << " �m�W�G " << this->vStu[i].m_Name << endl;
		}
	}
	else {
		cout << "�Ҧ��Юv��Ʀp�U�G " << endl;
		for (int i = 0; i < this->vTea.size(); i++) {
			cout << "¾�u���G " << this->vTea[i].m_EmpId << " �m�W�G " << this->vTea[i].m_Name << endl;
		}
	}
	system("pause");
	system("cls");
}

void Manager::showComputer() {
	cout << "�q���ЫǸ�Ʀp�U: " << endl;
	for (int i = 0; i < this->vCom.size(); i++) {
		cout << "�q���Ы� " << this->vCom[i].m_ComId << " ��e�Ǫ��̤j�H�ơG " << this->vCom[i].m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

void Manager::cleanFile() {
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "�M�Ŧ��\!" << endl;
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