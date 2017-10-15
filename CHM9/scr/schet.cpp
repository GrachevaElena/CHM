#include <cmath>
#include "schet.h"
#include "Table.h"

static double eps = 1e-5;
static double c = 0, k = 0, K = 0, m = 0;
static double u0, upr0;

struct VectorRow {
	unsigned i;
	double hi_1;
	double xi;
	std::vector<double> viPr;
	std::vector<double> viKor;
	std::vector<double> viPr_viKor;
	std::vector<double> s;
	std::vector<double> viUtoch;
	std::vector<double> viItog;
	int stepInc;
	int stepDec;

	operator Row () {
		Row tmp;
		tmp.i = i;
		tmp.hi_1 = hi_1;
		tmp.xi = xi;
		tmp.stepDec = stepDec;
		tmp.stepInc = stepInc;
		tmp.viPr = viPr[0];
		tmp.viKor = viKor[0];
		tmp.viPr_viKor = viPr_viKor[0];
		tmp.s = sqrt(s[0]*s[0]+s[1]*s[1]);
		tmp.viItog = viItog[0];
		tmp.viUtoch = viUtoch[0];
		tmp.ui = exp(-1 * xi)*(u0 * cos(3 * xi) + (upr0 + u0) / 3 * sin(3 * xi));
		tmp.abs_ui_vi = abs(tmp.ui - tmp.viItog);
		return tmp;
	}
};

std::vector<double> operator+(std::vector<double> v1, std::vector<double>v2) {
	std::vector<double> res(2);
	res[0] = v1[0] + v2[0];
	res[1] = v1[1] + v2[1];
	return res;
}
std::vector<double> operator*(double a, std::vector<double>v) {
	std::vector<double> res(2);
	res[0] = a * v[0];
	res[1] = a * v[1];
	return res;
}
std::vector<double> operator/(std::vector<double>v, double a) {
	std::vector<double> res(2);
	res[0] = v[0] / a;
	res[1] = v[1] / a;
	return res;
}

void SetParam(double c_ = 1, double k_ = 1, double K_ = 1, double m_ = 1)
{
	c = c_;
	k = k_;
	K = K_;
	m = m_;
}
std::vector<double> testf(double x, std::vector<double> u)
{
	std::vector<double> f(2);
	f[0] = u[1];
	f[1] = -(2*u[1] + 9*u[0]);
	return f;
}
std::vector<double> mainf(double x, std::vector<double> u) {//u3?
	std::vector<double> f(2);
	f[0] = u[1];
	f[1] = -(c*u[1] + k*u[0] + K*pow(u[0],3)) / m;
	return f;
}
std::vector<double> RK4(Function f, double h, double x, std::vector<double> v) {
	std::vector<double> k1 = f(x, v);
	std::vector<double> k2 = f(x + h / 2, v + (h / 2)*k1);
	std::vector<double> k3 = f(x + h / 2, v + (h / 2)*k2);
	std::vector<double> k4 = f(x + h, v + h*k3);
	return v + (h / 6) * (k1 + 2 * k2 + 2 * k3 + k4);
}
VectorRow DoubleCount(Method method, Function f, int p, double& _h, VectorRow* R) {
	std::vector<double> v1 = method(f, _h, R->xi, R->viPr);
	std::vector<double> v2 = method(f, _h*0.5, R->xi + _h*0.5, method(f, _h*0.5, R->xi, R->viPr));
	std::vector<double> _s = (v2 + (-1)*v1) / (pow(2, p) - 1);
	if (sqrt(_s[0] * _s[0] + _s[1] * _s[1]) > eps) {
		R->stepDec += 1;
		_h *= 0.5;
		return DoubleCount(method, f, p, _h, R);
	}
	R->hi_1 = _h;
	R->xi += _h;
	if (sqrt(_s[0] * _s[0] + _s[1] * _s[1]) < eps / pow(2, p + 1)) {
		R->stepInc += 1;
		_h *= 2;
	}
	R->s = _s;
	R->viPr = v1;
	R->viKor = v2;
	R->viItog = R->viKor;
	R->viPr_viKor = v1 + (-1)*v2;
	R->viUtoch = v1 + pow(2, p)*R->s;
	R->viItog = R->viPr;
	return *R;
}
void Integrate(Method method, Function f, double x0, double maxX, double _y0, double _ypr0, int maxI, double h0, double eps_, double epsX, Table* T, int p, double c, double k, double K, double m)
{
	VectorRow R1;
	std::vector<double> y0(2);
	y0[0] = _y0;
	y0[1] = _ypr0;
	eps = eps_;
	u0 = _y0, upr0=_ypr0;
	SetParam(c, k, K, m);
	int i = 0;
	VectorRow tmp;
	tmp.i = 0;
	tmp.hi_1 = 0;
	tmp.xi = x0;
	tmp.viPr = y0;
	tmp.viKor = y0;
	tmp.viPr_viKor = std::vector<double>(2, 0.0);
	tmp.s = std::vector<double>(2, 0.0);
	tmp.viUtoch = y0;
	tmp.viItog = std::vector<double>(2, 0.0);
	tmp.stepInc = 0;
	tmp.stepDec = 0;
	double hi = h0;
	while (tmp.xi + hi<maxX && i<maxI)
	{
		T->AddRow(tmp);
		i++;
		tmp.stepDec = tmp.stepInc = 0;
		tmp = DoubleCount(method, f, p, hi, &tmp);
		tmp.i = i;
	}
	T->AddRow(tmp);

	//board, if f in Infinity on the board
	if (i < maxI) {
		hi = maxX - tmp.xi;
		do {
			i++;
			tmp.stepDec = tmp.stepInc = 0;
			tmp = DoubleCount(method, f, p, hi, &tmp);
			tmp.i = i;
			T->AddRow(tmp);
		} while (maxX - tmp.xi > eps);
	}
}

void Integrate()
{
}
