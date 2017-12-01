#include <cmath>
#include "Table.h"
#include "schet.h"

//-параметтры системы--------
static double eps = 1e-5;
//static double a1 = 0, a2 = 0, m = 0, 
static double u0 = 0;
//---------------------------

void SetParam(double a1_ = 1, double a2_ = 1, double m_ = 1, double u0_ = 1)
{
	//a1 = a1_;
	//a2 = a2_;
	//m = m_;
	u0 = u0_;
}

double Mainf(double x, double y)
{
	return (-cos(20*x)*pow(y,3)+(1/(1+pow(sin(x),3)))*y*y+y);
}

double Testf(double x, double y)
{
	return -3*y;
}

double RK4(Function f, double h, double x, double y)
{
	double k1, k2, k3, k4;
	k1 = f(x, y);
	k2 = f(x + h / 2, y + k1*h / 2);
	k3 = f(x + h / 2, y + k2*h / 2);
	k4 = f(x + h, y + k3*h);
	return y + (h/6) * (k1+2*k2+2*k3+k4);
}

Row DoubleCount(Method method, Function f, int p, double h_, Row R, int depth=0)
{
	double y1 = method(f, h_, R.xi, R.viPr);
	double y2 = method(f, h_*0.5, R.xi + h_*0.5, method(f, h_*0.5, R.xi, R.viPr));
	double e_ = abs(y2 - y1) * (pow(2, p) - 1);
	Row Res;
	if (e_ < eps / pow(2, p + 1) && depth==0)
	{
		Res.stepInc = 1;
	}
	if (e_ > eps)
	{
		return DoubleCount(method, f, p, h_*0.5, R, depth+1);
	}
	Res.stepDec = depth;
	Res.hi_1 = h_;
	Res.xi = R.xi + h_;
	Res.viPr = y1;
	Res.viKor = y2;
	Res.viPr_viKor = y1 - y2;
	Res.s = e_*pow(2, p);
	Res.viUtoch = y1 + e_;
	Res.viItog = y1;
	Res.total = 0;
	return Res;
}

void Swap(double& a, double& b) {
	double c = a;
	a = b;
	b = c;
}
void Integrate(Method method, Function f, double x0, double maxX, double y0, int maxI, double h0, double eps_, double epsX, Table* T, int p, double a1, double a2, double m )
{
	eps = eps_;
	SetParam(a1,a2,m,u0);
	int i = 0;
	double tmph=h0, tmpstepinc=0;
	Row tmp;
	tmp.i = 0;
	tmp.hi_1 = 0;
	tmp.xi = x0;
	tmp.viPr = y0;
	tmp.viKor = y0;
	tmp.viPr_viKor = 0;
	tmp.s = 0;
	tmp.viUtoch = y0;
	tmp.viItog = y0;
	tmp.stepInc = 0;
	tmp.stepDec = 0;
	tmp.total = 0;
	tmp.ui = y0*exp(x0);
	tmp.abs_ui_vi = 0;
	T->AddRow(tmp);
	tmp.hi_1 = h0;
	while (tmp.xi<maxX - epsX && i<maxI)
	{
		i++;
		tmp = DoubleCount(method, f, p, tmp.hi_1*(tmpstepinc+1), tmp);
		tmp.i = i;
		tmp.ui = y0*exp(-3*tmp.xi);
		tmp.abs_ui_vi = abs(tmp.ui - tmp.viPr);
		Swap(tmp.stepInc, tmpstepinc);
		T->AddRow(tmp);	
	}
}