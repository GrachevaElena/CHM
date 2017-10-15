#pragma once
#include <vector>
#include "Table.h"

typedef std::vector<double>(*Function)(double, std::vector<double>);
typedef std::vector<double>(*Method)(Function, double, double, std::vector<double>);

std::vector<double> testf(double x, std::vector<double> u);
std::vector<double> mainf(double x, std::vector<double> u);

std::vector<double> RK4(Function f, double h, double x, std::vector<double> v);

void Integrate(Method method, Function f, double x0, double maxX, double _y0, double _ypr0, int maxI, double h0, double eps_, double epsX, Table* T, int p, double c=1, double k=1, double kst=1, double m=1);