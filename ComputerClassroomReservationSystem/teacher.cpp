#include "teacher.h"

Teacher::Teacher() {

}


Teacher::Teacher(string empId, string name, string pwd) {
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

void Teacher::operMenu() {
	cout << "�w��Юv�G " << this->m_Name << " �n���I" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t| 1.�d�ݩҦ��w��                   |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t| 2.�f�ֹw��                       |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t| 0.�n�X                           |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "�п�ܱz���ާ@�G " << endl;
}

void Teacher::showAllOrder() {
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
		cout << i + 1 << "�B ";

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

void Teacher::verifyOrder() {
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "�L�w���O��" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "�ݼf�֪��w���O���p�U�G" << endl;

	vector<int>v;
	int index = 0;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (of.m_orderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << ++index << "�B ";
			cout << "�w������G �g" << of.m_orderData[i]["date"];
			cout << " �ɬq�G" << (of.m_orderData[i]["interval"] == "1" ? "�W��" : "�U��");
			cout << " �q���ЫǡG" << of.m_orderData[i]["roomId"];
			cout << " ���A�G �f�֤�" << endl;
		}
	}
	cout << "�п�J�f�֪��w���O��,0�N���^" << endl;
	int select = 0;
	int ret = 0;
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
				cout << "�п�J�f�ֵ��G" << endl;
				cout << "1�B�q�L" << endl;
				cout << "2�B���q�L" << endl;
				cin >> ret;

				if (ret == 1)
				{
					of.m_orderData[v[select - 1]]["status"] = "2";
				}
				else
				{
					of.m_orderData[v[select - 1]]["status"] = "-1";
				}
				of.updateOrder();
				cout << "�f�֧����I" << endl;
				break;
			}
		}
		cout << "��J���~�A�Э��s��J" << endl;
	}

	system("pause");
	system("cls");
}