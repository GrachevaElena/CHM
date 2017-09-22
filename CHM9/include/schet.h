#pragma once
#include "Table.h"

const int MainTask = 1;
const int TestTask = 0;

double f(double x, double y);
double Euler(double(*f)(double, double), double h, double x, double y);
double RK2(double(*f)(double, double), double h, double x, double y);
double DoubleCount(double(*f)(double, double), double &h, double x, double y, double &e);
