#include "teacher.h"

Teacher::Teacher() {

}


Teacher::Teacher(string empId, string name, string pwd) {
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

void Teacher::operMenu() {
	cout << "歡迎教師： " << this->m_Name << " 登錄！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t| 1.查看所有預約                   |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t| 2.審核預約                       |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t| 0.登出                           |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "請選擇您的操作： " << endl;
}

void Teacher::showAllOrder() {
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
		cout << i + 1 << "、 ";

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

void Teacher::verifyOrder() {
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "無預約記錄" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "待審核的預約記錄如下：" << endl;

	vector<int>v;
	int index = 0;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (of.m_orderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << ++index << "、 ";
			cout << "預約日期： 週" << of.m_orderData[i]["date"];
			cout << " 時段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
			cout << " 電腦教室：" << of.m_orderData[i]["roomId"];
			cout << " 狀態： 審核中" << endl;
		}
	}
	cout << "請輸入審核的預約記錄,0代表返回" << endl;
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
				cout << "請輸入審核結果" << endl;
				cout << "1、通過" << endl;
				cout << "2、不通過" << endl;
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
				cout << "審核完畢！" << endl;
				break;
			}
		}
		cout << "輸入有誤，請重新輸入" << endl;
	}

	system("pause");
	system("cls");
}