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
	cout << "歡迎學生代表： " << this->m_Name << " 登錄！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t| 1.申請預約                       |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t| 2.查看我的預約                   |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t| 3.查看所有預約                   |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t| 4.取消預約                       |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t| 0.登出                           |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "請選擇您的操作： " << endl;
}

void Student::applyOrder() {
	cout << "電腦教室開放時間為周一至週五！" << endl;
	cout << "請輸入申請預約的時間：" << endl;
	cout << "1、週一" << endl;
	cout << "2、週二" << endl;
	cout << "3、週三" << endl;
	cout << "4、週四" << endl;
	cout << "5、週五" << endl;
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
		cout << "輸入有誤，請重新輸入" << endl;
	}


	cout << "請輸入申請預約的時間段：" << endl;
	cout << "1、上午" << endl;
	cout << "2、下午" << endl;

	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "輸入有誤，請重新輸入" << endl;
	}

	cout << "請選擇電腦教室：" << endl;
	for (int i = 0; i < this->vCom.size(); i++) {
		cout << i+1 << "、電腦教室 " << this->vCom[i].m_ComId << " 容納的最大人數：" << this->vCom[i].m_MaxNum << endl;
	}
	
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= this->vCom.size())
		{
			break;
		}
		cout << "輸入有誤，請重新輸入" << endl;
	}

	cout << "預約成功！審核中" << endl;

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
		cout << "無預約記錄!" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		if (this->m_Id == of.m_orderData[i]["stuId"])
		{
			cout << "預約日期： 週" << of.m_orderData[i]["date"];
			cout << " 時段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
			cout << " 電腦教室：" << of.m_orderData[i]["roomId"];
			string status = " 狀態： ";
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "審核中";
			}
			else if (of.m_orderData[i]["status"] == "2")
			{
				status += "預約成功";
			}
			else if (of.m_orderData[i]["status"] == "-1")
			{
				status += "審核未通過，預約失敗";
			}
			else
			{
				status += "預約已取消";
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
		cout << "無預約記錄" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		cout << "預約日期： 週" << of.m_orderData[i]["date"];
		cout << " 時段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
		cout << " 學號：" << of.m_orderData[i]["stuId"];
		cout << " 姓名：" << of.m_orderData[i]["stuName"];
		cout << " 電腦教室：" << of.m_orderData[i]["roomId"];
		string status = " 狀態： ";
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "審核中";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "預約成功";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "審核未通過，預約失敗";
		}
		else
		{
			status += "預約已取消";
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
		cout << "無預約記錄" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "審核中或預約成功的記錄可以取消，您的預約記錄如下: " << endl;

	vector<int>v;
	int index = 1;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (of.m_orderData[i]["stuId"] == this->m_Id)
		{
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << "、 ";
				cout << "預約日期： 週" << of.m_orderData[i]["date"];
				cout << " 時段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
				cout << " 電腦教室：" << of.m_orderData[i]["roomId"];
				string status = " 狀態： ";
				if (of.m_orderData[i]["status"] == "1")
				{
					status += "審核中";
				}
				else if (of.m_orderData[i]["status"] == "2")
				{
					status += "預約成功";
				}
				cout << status << endl;

			}
		}
	}

	cout << "請輸入取消的記錄,0代表返回" << endl;
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
				cout << "已取消預約" << endl;
				break;
			}

		}
		cout << "輸入有誤，請重新輸入" << endl;
	}

	system("pause");
	system("cls");
}