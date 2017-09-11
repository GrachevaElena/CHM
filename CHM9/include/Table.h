#pragma once

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
	double Total;
	double ui;
	double abs_ui_vi;
};

typedef Row Table[N];
