#include "student.h"

Student::Student() {

}

Student::Student(string id, string name, string pwd) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	ifstream ifs(COMPUTER_FILE, ios::in);
	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum) {
		this->vCom.push_back(c);
	}
	ifs.close();
}

void Student::operMenu() {
	cout << "�w��ǥͥN��G " << this->m_Name << " �n���I" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t| 1.�ӽйw��                       |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t| 2.�d�ݧڪ��w��                   |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t| 3.�d�ݩҦ��w��                   |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t| 4.�����w��                       |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t| 0.�n�X                           |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "�п�ܱz���ާ@�G " << endl;
}

void Student::applyOrder() {
	cout << "�q���ЫǶ}��ɶ����P�@�ܶg���I" << endl;
	cout << "�п�J�ӽйw�����ɶ��G" << endl;
	cout << "1�B�g�@" << endl;
	cout << "2�B�g�G" << endl;
	cout << "3�B�g�T" << endl;
	cout << "4�B�g�|" << endl;
	cout << "5�B�g��" << endl;
	int date = 0;
	int interval = 0;
	int room = 0;

	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "��J���~�A�Э��s��J" << endl;
	}


	cout << "�п�J�ӽйw�����ɶ��q�G" << endl;
	cout << "1�B�W��" << endl;
	cout << "2�B�U��" << endl;

	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "��J���~�A�Э��s��J" << endl;
	}

	cout << "�п�ܹq���ЫǡG" << endl;
	for (int i = 0; i < this->vCom.size(); i++) {
		cout << i+1 << "�B�q���Ы� " << this->vCom[i].m_ComId << " �e�Ǫ��̤j�H�ơG" << this->vCom[i].m_MaxNum << endl;
	}
	
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= this->vCom.size())
		{
			break;
		}
		cout << "��J���~�A�Э��s��J" << endl;
	}

	cout << "�w�����\�I�f�֤�" << endl;

	ofstream ofs(ORDER_FILE, ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_Id << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "roomId:" << this->vCom[room-1].m_ComId << " ";
	ofs << "status:" << 1 << endl;

	ofs.close();

	system("pause");
	system("cls");
}

void Student::showOrder() {
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "�L�w���O��!" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		if (this->m_Id == of.m_orderData[i]["stuId"])
		{
			cout << "�w������G �g" << of.m_orderData[i]["date"];
			cout << " �ɬq�G" << (of.m_orderData[i]["interval"] == "1" ? "�W��" : "�U��");
			cout << " �q���ЫǡG" << of.m_orderData[i]["roomId"];
			string status = " ���A�G ";
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "�f�֤�";
			}
			else if (of.m_orderData[i]["status"] == "2")
			{
				status += "�w�����\";
			}
			else if (of.m_orderData[i]["status"] == "-1")
			{
				status += "�f�֥��q�L�A�w������";
			}
			else
			{
				status += "�w���w����";
			}
			cout << status << endl;

		}
	}

	system("pause");
	system("cls");
}

void Student::showAllOrder() {
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "�L�w���O��" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		cout << "�w������G �g" << of.m_orderData[i]["date"];
		cout << " �ɬq�G" << (of.m_orderData[i]["interval"] == "1" ? "�W��" : "�U��");
		cout << " �Ǹ��G" << of.m_orderData[i]["stuId"];
		cout << " �m�W�G" << of.m_orderData[i]["stuName"];
		cout << " �q���ЫǡG" << of.m_orderData[i]["roomId"];
		string status = " ���A�G ";
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "�f�֤�";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "�w�����\";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "�f�֥��q�L�A�w������";
		}
		else
		{
			status += "�w���w����";
		}
		cout << status << endl;
	}

	system("pause");
	system("cls");
}

void Student::cancelOrder() {
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "�L�w���O��" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "�f�֤��ιw�����\���O���i�H�����A�z���w���O���p�U: " << endl;

	vector<int>v;
	int index = 1;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (of.m_orderData[i]["stuId"] == this->m_Id)
		{
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << "�B ";
				cout << "�w������G �g" << of.m_orderData[i]["date"];
				cout << " �ɬq�G" << (of.m_orderData[i]["interval"] == "1" ? "�W��" : "�U��");
				cout << " �q���ЫǡG" << of.m_orderData[i]["roomId"];
				string status = " ���A�G ";
				if (of.m_orderData[i]["status"] == "1")
				{
					status += "�f�֤�";
				}
				else if (of.m_orderData[i]["status"] == "2")
				{
					status += "�w�����\";
				}
				cout << status << endl;

			}
		}
	}

	cout << "�п�J�������O��,0�N���^" << endl;
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				of.m_orderData[v[select - 1]]["status"] = "0";
				of.updateOrder();
				cout << "�w�����w��" << endl;
				break;
			}

		}
		cout << "��J���~�A�Э��s��J" << endl;
	}

	system("pause");
	system("cls");
}