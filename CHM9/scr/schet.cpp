#include <cmath>

const double Eps = 1e-5;

double f(double x, double y)
{
	return y;
}

double Euler(double (*f)(double,double), double h, double x, double y)
{
	return y + h * f(x,y);
}

double RK2(double (*f)(double,double), double h, double x, double y)
{
	return y + h * f(x + h, y + Euler(f, h, x, y));
}

double DoubleCount(double (*f)(double,double), double &h, double x, double y, double &e)
{
	double h_ = h;
	double y1 = RK2(f, h, x, y);
	double y2 = RK2(f, h*0.5, x+h*0.5, RK2(f, h*0.5, x, y));
	double e_ = (y2 - y1) * 4/3;
	if(fabs(e_)<Eps*0.5)
		h_ = h_ * 2;
	while (fabs(e_)>Eps)
	{
		h_ = h_ * 0.5;
		y1 = RK2(f, h_, x, y);
		y2 = RK2(f, h_*0.5, x+h_*0.5, RK2(f, h_*0.5, x, y));
		e_ = (y2 - y1) * 4/3;
	}
	h = h_;
	e = e_;
	return y2;
}

