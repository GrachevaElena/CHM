#pragma once
#include "Table.h"
#include <cstdlib>
#include <ctime>

const int colors[10] = { 0xff1e90ff, 0xffF4a460, 0xffffc1c1, 0xff8b4513, 0x7ff006400, 0xffadff2f, 0xff7cfc00, 0xffff4500, 0xffff0000, 0xffffff00 };

struct Row_for_drawing {
	double x;
	double v;
};

class Table_for_drawing {
	std::list<Row_for_drawing> Data;
	int Color;

public:
	Table_for_drawing(Table& t) {
		AddTable(t);
	}

	typedef std::list<Row_for_drawing>::iterator iterator;

	iterator begin() { return Data.begin(); }
	iterator end() { return Data.end(); }

	void AddTable(Table& table) { 
		//for every table her own color
		srand(time(NULL));
		Color = rand() % 10;

		Row_for_drawing r;
		for (auto it = table.begin(); it != table.end(); it++) {
			r.x = it->xi;
			r.v = it->viItog;
			Data.push_back(r);
		}
	}

	int GetColor() { return colors[Color]; }
};