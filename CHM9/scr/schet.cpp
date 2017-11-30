#include <cmath>
#include "Table.h"
#include "schet.h"
#include <vector>

static Function k, f, q;
int task;


double RetX(int i, double h, double x0) {
	return x0 + i*h;
}

double Integral(double a, double b, double f(double)) {
	const int n = 1000;
	double h = (b - a) / n;
	double s = 0;
	for (int i = 0; i < n; i++)
		s += h*f(a + (i + 1 / 2)*h);//central rectangles
	return s;
}

void CalcCoef(Function func, double ksi, double x0, const int N, double h, std::vector<double>& d) {
	for (int i = 1; i < N; i++) {
		double x1 = RetX(i,h,x0) - h / 2, x2 = RetX(i,h,x0) + h / 2;
		if (x2 <= ksi || x1 >= ksi)
			d[i] = 1 / h*Integral(x1, x2, func);
		else if (x1 <= ksi && x2 >= ksi)
			d[i] = 1 / h*(Integral(x1, ksi, func) + Integral(ksi, x2, func));
	}
}

void CalcD(double ksi, double x0, const int N, double h, std::vector<double>& d) {
	return CalcCoef(q, ksi, x0, N, h, d);
}
void CalcA(double ksi, double x0, const int N, double h, std::vector<double>& a) {
	for (int i = 1; i <= N; i++) {
		double x1 = RetX(i,h,x0) - h, x2 = RetX(i,h,x0);
		if (x2 <= ksi || x1 >= ksi)
			a[i] = 1 / h*Integral(x1, x2, [](double x) {return 1/k(x); });
		else if (x1 <= ksi && x2 >= ksi)
			a[i] = 1 / h*(Integral(x1, ksi, [](double x) {return 1 / k(x); }) + Integral(ksi, x2, [](double x) {return 1 / k(x); }));
		a[i] = 1 / a[i];
	}
}
void CalcFi(double ksi, double x0, const int N, double h, std::vector<double>& fi) {
	CalcCoef(f, ksi, x0, N, h, fi);
}

void Progonka(double nu1, double nu2, std::vector<double>& a, std::vector<double>& d, std::vector<double>&fi, int N, double h, std::vector<double>& v) {
	std::vector<double> alpha(N+1), beta(N+1);
	//прямой ход
	alpha[1] = 0; beta[1] = nu1;
	for (int i = 2; i <= N; i++) {
		double A, B, C;
		B = a[i] / (h*h);
		A = a[i-1] / (h*h);
		C = (a[i] + a[i-1]) / (h*h) + d[i-1];
		alpha[i] = B / (C - alpha[i - 1] * A);
		beta[i] = (fi[i - 1] + beta[i - 1] * A) / (C - alpha[i - 1] * A);
	}
	//обратный ход
	v[N] = nu2;
	for (int i = N - 1; i >= 0; i--) {
		v[i] = alpha[i + 1] * v[i + 1] + beta[i + 1];
	}
}


void CalculateForOneGrid(double nu1, double nu2, double ksi, double x0, const int N, double h, std::vector<double>& v) {
	std::vector<double> d(N+1), a(N+1), fi(N+1);
	CalcD(ksi, x0, N, h, d);
	CalcA(ksi, x0, N, h, a);
	CalcFi(ksi, x0, N, h, fi);

	Progonka(nu1, nu2, a, d, fi, N, h, v);
}

double RetU(double x) {
	return x*x;
}

void WriteTable(Table & table, double x0, double h, std::vector<double>& v, std::vector<double>& v2, std::vector<double>& s, int nGrid) {
	for (int i = 0; i <=nGrid; i++) {
		Row r;
		r.i = i;
		r.xi = RetX(i,h,x0);
		r.vi = v[i];
		r.v2i = v2[i];
		if (task==TestTask) r.ui = RetU(RetX(i,h,x0));
		r.diff_abs = s[i];
		table.AddRow(r);
	}
}

void Calculate(Table & table, Function _k, Function _q, Function _f, double nu1, double nu2, double ksi, double x0, const int N, double h, double locErr, int _task)
{
	f = _f, k = _k, q = _q, task=_task;

	std::vector<double> v(N + 1);
	CalculateForOneGrid(nu1, nu2, ksi, x0, N, h, v);

	std::vector<double> v2(2 * (N + 1));
	CalculateForOneGrid(nu1, nu2, ksi, x0, 2 * N, h / 2, v2);

	std::vector<double> s(N + 1);

	double max = 0;
	for (int i = 0; i < N + 1; i++) {
		if (task==MainTask)
			s[i] = abs(v[i] - v2[2 * i]);
		else s[i] = abs(v[i] - RetU(RetX(i,h,x0)));
		if (s[i] > max) max = s[i];
	}

	if (max > locErr) {
		Calculate(table, _k, _q, _f, nu1, nu2, ksi, x0, N * 2, h / 2, locErr, task);
	}
	else {
		WriteTable(table, x0, h, v, v2, s, N);
	}



}


