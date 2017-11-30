#pragma once
#include "Table.h"

typedef double(*Function)(double);

double RetU(double x);
void Calculate(Table & table, Function _k, Function _q, Function _f, double nu1, double nu2, double ksi, double x0, const int N, double h, double locErr, int _task);