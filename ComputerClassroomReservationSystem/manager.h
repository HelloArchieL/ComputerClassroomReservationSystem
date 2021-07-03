#pragma once
#include<iostream>
#include "Identity.h"
#include "student.h"
#include "teacher.h"
#include "computerRoom.h"
using namespace std;

class Manager :public Identity
{
public:

	Manager();

	Manager(string name, string pwd);

	virtual void operMenu();

	void addPerson();

	void showPerson();

	void showComputer();

	void cleanFile();

	void initVector();

	bool checkRepeat(string id, int type);

	vector<Student> vStu;

	vector<Teacher> vTea;

	vector<ComputerRoom> vCom;
};