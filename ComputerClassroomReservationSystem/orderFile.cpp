#include "orderFile.h"

OrderFile::OrderFile() {
	ifstream ifs(ORDER_FILE, ios::in);

	vector<string> v(6);

	this->m_Size = 0;

	while (ifs >> v[0] && ifs >> v[1] && ifs >> v[2] && ifs >> v[3] && ifs >> v[4] && ifs >> v[5]) {
		string key, value;
		int pos;
		map<string, string> m;

		for (int i = 0; i < 6; i++) {
			pos = v[i].find(":");
			if (pos != -1)
			{
				key = v[i].substr(0, pos);
				value = v[i].substr(pos + 1, v[i].size() - pos - 1);
				m[key] = value;
			}
		}
		this->m_orderData[this->m_Size] = m;
		this->m_Size++;
	}
	ifs.close();
}

void OrderFile::updateOrder() {
	if (this->m_Size == 0) return;

	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0; i < this->m_Size; i++) {
		ofs << "date:" << this->m_orderData[i]["date"] << " ";
		ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
		ofs << "stuId:" << this->m_orderData[i]["stuId"] << " ";
		ofs << "stuName:" << this->m_orderData[i]["stuName"] << " ";
		ofs << "roomId:" << this->m_orderData[i]["roomId"] << " ";
		ofs << "status:" << this->m_orderData[i]["status"] << endl;
	}
	ofs.close();
}