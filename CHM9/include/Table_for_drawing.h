#pragma once
#include "Table.h"
#include <cstdlib>
#include <ctime>

const int NC = 57;
const int colors[NC] = 
{ 0xffCD5C5C ,0xffFFA07A ,0xffDC143C ,0xffFF0000 ,0xffB22222 ,
0xff8B0000 ,0xffFF1493 ,0xffC71585 ,0xffDB7093 ,0xffFFA07A ,
0xffFF7F50 ,0xffFF6347 ,0xffFF4500 ,0xffFF8C00 ,0xffFFA500 ,
0xffFFD700 ,0xffFFFF00 ,0xffFF00FF ,0xffBA55D3 ,0xff9400D3 ,
0xff8B008B ,0xff4B0082 ,0xff6A5ACD ,0xff483D8B ,0xffBC8F8F ,
0xffA0522D ,0xff8B4513 ,0xffD2691E ,0xffB8860B ,0xffDAA520 ,
0xffFF00FF ,0xff800080 ,0xffFFFF00 ,0xff00FF00 ,0xff008000 ,
0xff00FFFF ,0xff008080 ,0xff0000FF ,0xff000080 ,0xff32CD32 ,
0xff7CFC00 ,0xff00FF00 ,0xff98FB98 ,0xff90EE90 ,0xff00FA9A ,
0xff008000 ,0xff808000 ,0xff66CDAA ,0xff20B2AA ,0xff4682B4 ,
0xffB0C4DE ,0xff7B68EE ,0xff0000CD ,0xff00008B ,0xff000080 ,
0xff191970 ,0xff2F4F4F };

struct Row_for_drawing {
	double x;
	double v;
};

class Table_for_drawing {
	std::list<Row_for_drawing> Data;
	int Color;

public:
	Table_for_drawing() {}
	~Table_for_drawing() { Clear(); }
	Table_for_drawing(Table& t) {
		AddTable(t);
	}

	typedef std::list<Row_for_drawing>::iterator iterator;

	iterator begin() { return Data.begin(); }
	iterator end() { return Data.end(); }

	void AddTable(Table& table) { 
		//for every table her own color
		srand(time(NULL));
		Color = colors[rand() % NC];

		Row_for_drawing r;
		for (auto it = table.begin(); it != table.end(); it++) {
			r.x = it->xi;
			r.v = it->viItog;
			Data.push_back(r);
		}
	}
	void AddColor() {
		srand(time(NULL));
		Color = colors[rand() % NC];
	}

	void AddRow(Row_for_drawing& r) {
		Data.push_back(r);
	}

	int GetColor() { return Color; }

	void Clear() { Data.clear(); }
};