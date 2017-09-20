#pragma once
#include <list>

const int MainTask = 1;
const int TestTask = 0;

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
};

class Table {
	std::list<Row> Data;
public:
	Table() {}
	Table(const Table& t):Data(t.Data) {}
	~Table() {}
	auto GetIterator() { return Data.begin(); }
	int GetSize() { return Data.size(); }
	void AddRow(Row row) { Data.push_back(row); }
	Row GetLastRow() { return *(--Data.end()); } 
};
