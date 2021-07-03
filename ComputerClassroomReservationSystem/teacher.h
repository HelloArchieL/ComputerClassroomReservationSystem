#pragma once
#include <iostream>
#include "Identity.h"
#include "orderFile.h"
using namespace std;

class Teacher :public Identity {
public:

	Teacher();

	Teacher(string empId, string name, string pwd);

	virtual void operMenu();

	void showAllOrder();

	void verifyOrder();

	string m_EmpId;
};