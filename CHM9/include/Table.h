#pragma once

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
	Row* Data;
	int Size;
public:
	Table() { Data = 0; }
	Table(int size) { 
		Size = size; 
		Data = new Row[Size];
	}
	Table(Row* data, int size) {
		Size = size;
		Data = new Row[Size];
		for (int i = 0; i < size; i++) {
			Data[i] = data[i];
		}
	}
	Table(const Table& t) {
		Size = t.Size;
		Data = new Row[Size];
		for (int i = 0; i < t.Size; i++) {
			Data[i] = t.Data[i];
		}
	}
	~Table(){
		delete[] Data;
		Data = 0;
		Size = 0;
	}
	Row& operator[] (int i) { return Data[i]; }
	int GetSize() { return Size; }

};
