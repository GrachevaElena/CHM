#pragma once
#include <list>
#include <fstream>

const int MainTask = 1;
const int TestTask = 0;

//Don't laugh, please, I know that names are stupid
struct Row {
	unsigned i;
	double xi;
	double ui;
	double vi;
	double v2i;
	double diff_abs;

	Row() {
		i = 0;
		xi = 0;
		ui = 0;
		vi = 0;
		v2i = 0;
		diff_abs = 0;
	}
	friend std::ifstream& operator>> (std::ifstream & ins, Row& t) {
		ins >> t.i >>  t.xi >> t.ui >> t.vi >> t.v2i >> t.diff_abs;
		return ins;
	}
	friend std::ofstream& operator<< (std::ofstream & outs, Row& t) {
		outs << t.i <<' '<< t.xi <<' '<< t.ui <<' '<< t.vi <<' '<< t.v2i <<' '<< t.diff_abs << std::endl;
		return outs;
	}
};

class Table {
	std::list<Row> Data;
public:
	Table() {}
	Table(const Table& t):Data(t.Data) {}
	~Table() {}

	typedef std::list<Row>::iterator iterator;

	iterator begin() { return Data.begin(); }
	iterator end() { return Data.end(); }

	int GetSize() { return Data.size(); }
	void AddRow(Row row) { Data.push_back(row); }
	Row GetLastRow() { return *(--Data.end()); } 

	void Clear() { Data.clear(); }

	friend std::ifstream& operator>> (std::ifstream & ins, Table& t) {
		Row r;
		while (!ins.eof()) {
			ins >> r;
			if (!ins.eof()) t.AddRow(r);
		}
		return ins;
	}
	friend std::ofstream& operator<< (std::ofstream & outs, Table& t) {
		for (auto it = t.begin(); it != t.end(); it++)
			outs << (*it);
		return outs;
	}
};
