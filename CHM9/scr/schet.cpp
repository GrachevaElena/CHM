#include <cmath>
#include "Table.h"
#include "schet.h"

//-параметтры системы--------
static double eps = 1e-5;
static double a1 = 0, a2 = 0, m = 0, u0 = 0;
//---------------------------

void SetParam(double a1_ = 1, double a2_ = 1, double m_ = 1, double u0_ = 1)
{
	a1 = a1_;
	a2 = a2_;
	m = m_;
	u0 = u0_;
}

double Mainf(double x, double y)
{
	return (-(a1*y+a2*y*y))/m;
}

double Testf(double x, double y)
{
	return y;
}

double Euler(Function f, double h, double x, double y)
{
	return y + h * f(x, y);
}

double RK2(Function f, double h, double x, double y)
{
	return y + h * f(x + h*0.5, Euler(f, h*0.5, x, y));
}

Row DoubleCount(Method method, Function f, int p,double h_, Row* R)
{
	int x2 = 0, x05 = 0;
	double y1 = method(f, h_, R->xi, R->viPr);
	double y2 = method(f, h_*0.5, R->xi + h_*0.5, method(f, h_*0.5, R->xi, R->viPr));
	double e_ = (y2 - y1) * (pow(2,p)-1);
	Row Res; Res.stepDec = Res.stepInc=Res.ui=Res.abs_ui_vi = 0;
	if (fabs(e_)<eps/(pow(2,p+1)))
	{
		Res.stepInc = 1;
		h_ = h_ * 2;
		x2++;
	}
	while (fabs(e_)>eps)
	{
		Res.stepDec += 1;
		h_ = h_ * 0.5;
		x05--;
		y1 = method(f, h_, R->xi, R->viPr);
		y2 = method(f, h_*0.5, R->xi + h_*0.5, method(f, h_*0.5, R->xi, R->viPr));
		e_ = (y2 - y1) * (pow(2,p)-1);
	}
	Res.hi_1 = h_;
	Res.xi = R->xi + h_;
	Res.viPr = y1;
	Res.viKor = y2;
	Res.viPr_viKor = y1 - y2;
	Res.s = (y2 - y1) / 3;
	Res.viUtoch = y1 + e_;
	Res.viItog = y1;
	Res.total = 0;
	return Res;
}

void Integrate(Method method, Function f, double x0, double maxX, double y0, int maxI, double h0, double eps_, double epsX, Table* T, int p, double a1, double a2, double m )
{
	eps = eps_;
	SetParam(a1,a2,m,u0);
	int i = 0;
	double tmph1 = h0, tmph2=h0;
	Row tmp;
	tmp.i = 0;
	tmp.hi_1 = 0;
	tmp.xi = x0;
	tmp.viPr = y0;
	tmp.viKor = y0;
	tmp.viPr_viKor = 0;
	tmp.s = 0;
	tmp.viUtoch = y0;
	tmp.viItog = 0;
	tmp.stepInc = 0;
	tmp.stepDec = 0;
	tmp.total = 0;
	tmp.ui = y0*exp(x0);
	tmp.abs_ui_vi = 0;
	T->AddRow(tmp);
	while (tmp.xi<maxX - epsX && i<maxI)
	{
		i++;
		tmp = DoubleCount(method, f, p, tmph1, &tmp);
		tmph2 = tmp.hi_1;
		tmp.hi_1 = tmph1;
		tmph1 = tmph2;
		tmp.i = i;
		tmp.ui = y0*exp(tmp.xi);
		tmp.abs_ui_vi = abs(tmp.ui - tmp.viPr);
		T->AddRow(tmp);
	}
}