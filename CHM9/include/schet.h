#pragma once
#include "Table.h"

const int MainTask = 1;
const int TestTask = 0;

double Testf(double x, double y);
double Mainf(double x, double y);

double Euler(double(*f)(double, double), double h, double x, double y);
double RK2(double(*f)(double, double), double h, double x, double y);

void Integrate(double(*f)(double, double), double x0, double maxX, double y0, int maxI, double h0, double eps_, double epsX, Table* T);