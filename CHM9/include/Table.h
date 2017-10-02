#pragma once
#include <list>
#include <fstream>

const int MainTask = 1;
const int TestTask = 0;

const int N = 100000;

//Don't laugh, please, I know that names are stupid
struct Row {
	unsigned i;
	double hi_1;
	double xi;
	double viPr;
	double viKor;
	double viPr_viKor;
	double s;
	double viUtoch;
	double viItog;
	double stepInc;
	double stepDec;
	double total;
	double ui;
	double abs_ui_vi;

	friend std::ifstream& operator>> (std::ifstream & ins, Row& t) {
		ins >> t.i >> t.hi_1 >> t.xi >> t.viPr >> t.viKor >> t.viPr_viKor >> t.s >> t.viUtoch >> t.viItog >> t.stepDec >> t.stepInc >> t.total >> t.ui >> t.abs_ui_vi;
		return ins;
	}
	friend std::ofstream& operator<< (std::ofstream & outs, Row& t) {
		outs << t.i <<' '<< t.hi_1 <<' '<< t.xi <<' '<< t.viPr <<' '<< t.viKor <<' '<< t.viPr_viKor <<' '<< t.s <<' '<< t.viUtoch <<' '<< t.viItog <<' '<< t.stepDec <<' '<< t.stepInc <<' '<< t.total <<' '<< t.ui <<' '<< t.abs_ui_vi<<std::endl;
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
