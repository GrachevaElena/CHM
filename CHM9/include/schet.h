#pragma once
#include "Table.h"

typedef double(*Function)(double, double);
typedef double(*Method) (Function, double, double, double);

double Testf(double x, double y);
double Mainf(double x, double y);

double RK4(Function, double h, double x, double y);

const Method arrMethod[] = { RK4 };

void Integrate(Method, Function, double x0, double maxX, double y0, int maxI, double h0, double eps_, double epsX, Table* T, int p, double a1=0, double a2=0, double m=0);