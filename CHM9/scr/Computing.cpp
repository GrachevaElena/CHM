#include "Computing.h"
using namespace std;

double FindEps(MyMatrix& v, MyMatrix& v1) {
	double max=0;
	for (int i = 1; i < v.GetM()-1; i++)
		for (int j = 1; j < v.GetN()-1; j++)
			if (max < abs(v(i,j)-v1(i,j))) max = abs(v(i, j) - v1(i, j));
	return max;
}

double Abs(std::vector<double> & s) {
	double max = 0;
	for (int i = 0; i < s.size(); i++)
			if (max < abs(s[i])) max = abs(s[i]);
	return max;
}


//Zaidel's method
void Reference::ZaidelMethod(std::vector<double>& b)
{
	eps = 10000;
	int s = 0;
	while (eps > epsZaidel) {
		MyMatrix xs_1 = numericSolution;
		s++;

		for (int k = 0; k < (n - 1)*(m - 1); k++) {
			int i = GetIndexX(k);
			int j = GetIndexY(k);

			numericSolution(i, j) = b[k];
			for (int l = 0; l < k; l++)
				numericSolution(i, j) -= GetA(k, l)*numericSolution(GetIndexX(l), GetIndexY(l));
			for (int l = k + 1; l < (n - 1)*(m - 1); l++)
				numericSolution(i, j) -= GetA(k, l)*numericSolution(GetIndexX(l), GetIndexY(l));

			numericSolution(i, j) /= GetA(k, k);
		}

		eps = FindEps(numericSolution, xs_1);

		std::cout << std::endl << "s=" <<s<< std::endl;
		std::cout << numericSolution << std::endl;

	}
}

void Reference::FindRs(std::vector<double> b)
{
	std::vector<double>s((n-1)*(m-1));

	for (int i = 0; i < (n - 1)*(m - 1); i++) {
		for (int j = 0; j < (m - 1)*(n - 1); j++)
			s[i] += GetA(i, j)*numericSolution(GetIndexX(j), GetIndexY(j));
		s[i] -= b[i];
	}

	rs = Abs(s);
}

void Reference::FindGeneralError()
{
	generalError = FindEps(trueSolution, numericSolution);
}

void Reference::Compute(){
	vector<double> b = CreateB();
	ZaidelMethod(b);
	FindRs(b);
	FindGeneralError();
}

std::vector<double> Reference::CreateB()
{
	std::vector<double>b((n - 1)*(m - 1));

	for (int j = 1; j < m; j++)
		for (int i = 1; i < (n - 1); i++)
			b[GetIndex(i, j)] += -f(GetX(i), GetY(j));

	for (int j = 1; j < m; j++)
		b[GetIndex(1, j)] += -1 / (h*h)*numericSolution(0, j);
	for (int j = 1; j < m; j++)
		b[GetIndex(n - 1, j)] += -1 / (h*h)*numericSolution(n, j);

	for (int i = 1; i < n; i++)
		b[GetIndex(i, 1)] += -1 / (k*k)*numericSolution(i, 0);
	for (int i = 1; i < n; i++)
		b[GetIndex(i, m - 1)] += -1 / (k*k)*numericSolution(i, m);

	return b;

}


