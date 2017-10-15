#include <vector>
#include <list>
typedef std::vector<double>(*Function)(double, std::vector<double>);
typedef std::vector<double>(*Method)(Function, double, double, std::vector<double>);
struct Row {
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
	double total;
	std::vector<double> ui;
	double abs_ui_vi;

	friend std::ifstream& operator>> (std::ifstream & ins, Row& t) {
		ins >> t.i >> t.hi_1 >> t.xi >> t.viPr >> t.viKor >> t.viPr_viKor >> t.s >> t.viUtoch >> t.viItog >> t.stepDec >> t.stepInc >> t.total >> t.ui >> t.abs_ui_vi;
		return ins;
	}
	friend std::ofstream& operator<< (std::ofstream & outs, Row& t) {
		outs << t.i << ' ' << t.hi_1 << ' ' << t.xi << ' ' << t.viPr << ' ' << t.viKor << ' ' << t.viPr_viKor << ' ' << t.s << ' ' << t.viUtoch << ' ' << t.viItog << ' ' << t.stepDec << ' ' << t.stepInc << ' ' << t.total << ' ' << t.ui << ' ' << t.abs_ui_vi << std::endl;
		return outs;
	}
};
class Table {
	std::list<Row> Data;
public:
	Table() {}
	Table(const Table& t) :Data(t.Data) {}
	~Table() {}

	typedef std::list<Row>::iterator iterator;

	iterator begin() { return Data.begin(); }
	iterator end() { return Data.end(); }

	int GetSize() { return Data.size(); }
	void AddRow(Row row) { Data.push_back(row); }
	Row GetLastRow() { return *(--Data.end()); }

	void Clear() { Data.clear(); }

	friend std::ifstream& operator>> (std::ifstream & ins, Table& t) {
		Row r;
		while (!ins.eof()) {
			ins >> r;
			if (!ins.eof()) t.AddRow(r);
		}
		return ins;
	}
	friend std::ofstream& operator<< (std::ofstream & outs, Table& t) {
		for (auto it = t.begin(); it != t.end(); it++)
			outs << (*it);
		return outs;
	}
};

static double eps = 1e-5;
static double c = 0, k = 0, K = 0, m = 0;
static std::vector<double> u0 = std::vector<double>(2, 0.0);

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

void SetParam(double c_ = 1, double k_ = 1, double K_ = 1, double m_ = 1, std::vector<double> u0_ = std::vector<double>(2, 1.0))
{
	c = c_;
	k = k_;
	K = K_;
	m = m_;
	u0 = u0_;
}
std::vector<double> mainf(double x, std::vector<double> u) {
	std::vector<double> f(2);
	f[0] = u[1];
	f[1] = -(c*u[1] + k*u[0] + K*u[0]) / m;
}
std::vector<double> RK4(Function f, double h, double x, std::vector<double> v) {
	std::vector<double> k1 = f(x, v);
	std::vector<double> k2 = f(x + h / 2, v + (h/2)*k1);
	std::vector<double> k3 = f(x + h / 2, v + (h/2)*k2);
	std::vector<double> k4 = f(x + h, v + h*k3);
	return v + (h/6) * (k1 + 2 * k2 + 2 * k3 + k4);
}
Row DoubleCount(Method method, Function f, int p, Row* R) {
	R->stepDec = R->stepInc = 0;
	std::vector<double> v1 = method(f, R->hi_1, R->xi, R->viPr);
	std::vector<double> v2 = method(f, R->hi_1*0.5, R->xi + R->hi_1*0.5, method(f, R->hi_1*0.5, R->xi, R->viPr));
	R->s = (v2 + (-1)*v1) / (pow(2, p) - 1);
	while (sqrt(R->s[0] * R->s[0] + R->s[1] * R->s[1]) > eps) {
		R->hi_1 *= 0.5;
		R->stepDec++;
		v1 = method(f, R->hi_1, R->xi, R->viPr);
		v2 = method(f, R->hi_1*0.5, R->xi + R->hi_1*0.5, method(f, R->hi_1*0.5, R->xi, R->viPr));
		R->s = (v2 + (-1)*v1) / (pow(2, p) - 1);
	}
	R->xi += R->hi_1;
	if (sqrt(R->s[0] * R->s[0] + R->s[1] * R->s[1]) < eps / pow(2, p + 1)) {
		R->stepInc++;
	}
	R->viItog = R->viPr = v1;
	R->viKor = v2;
	R->viPr_viKor = v1 + (-1)*v2;
	R->viUtoch = v1 + pow(2, p)*R->s;
}
void Integrate(Method method, Function f, double x0, double maxX, std::vector<double> y0, int maxI, double h0, double eps_, double epsX, Table* T, int p, double c, double k, double K, double m)
{
	Row R1;
	eps = eps_;
	SetParam(c, k, K, m, y0);
	int i = 0;
	Row tmp;
	tmp.i = 0;
	tmp.hi_1 = h0;
	tmp.xi = x0;
	tmp.viPr = y0;
	tmp.viKor = y0;
	tmp.viPr_viKor = std::vector<double>(2,0.0);
	tmp.s = std::vector<double>(2, 0.0);
	tmp.viUtoch = y0;
	tmp.viItog = std::vector<double>(2, 0.0);
	tmp.stepInc = 0;
	tmp.stepDec = 0;
	tmp.total = 0;
	tmp.ui = exp(x0)*y0;
	tmp.abs_ui_vi = 0;
	T->AddRow(tmp);
	for (i = 1; i < maxI; ++i) {
		R1 = tmp;
		DoubleCount(RK4, mainf, 4, &tmp);
		if (tmp.xi <= maxX) {
			T->AddRow(tmp);
			if (tmp.stepInc) tmp.hi_1 *= 2;
			if (tmp.xi > maxX - epsX) break;
		}
		else {
			tmp = R1;
			tmp.hi_1 *= 0.5;
			tmp.stepDec++;
			i--;
			continue;
		}
	}
}