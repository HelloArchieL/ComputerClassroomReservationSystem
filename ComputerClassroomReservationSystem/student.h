#pragma once
#include <iostream>
#include "Identity.h"
#include "computerRoom.h"
#include "orderFile.h"
using namespace std;

class Student :public Identity{
public:

	Student();

	Student(string id, string name, string pwd);

	virtual void operMenu();

	void applyOrder();

	void showOrder();

	void showAllOrder();

	void cancelOrder();

	string m_Id;

	vector<ComputerRoom> vCom;
};