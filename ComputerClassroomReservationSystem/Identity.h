#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "globalFile.h"
#include <vector>
#include <algorithm>
using namespace std;

class Identity {
public:

	virtual void operMenu() = 0;

	string m_Name;
	string m_Pwd;
};