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

	Row(): i(0), hi_1(0),xi(0), viPr(0), viKor(0), viPr_viKor(0), s(0), viUtoch(0), viItog(0), 
		stepInc(0), stepDec(0), total(0), ui(0), abs_ui_vi(0){

	}

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
